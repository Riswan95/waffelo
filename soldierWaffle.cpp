#include "soldierWaffle.h"

SoldierWaffle::SoldierWaffle() : Entity()
{
	spriteData.width = waffleNS::WIDTH;           // size of waffle1
	spriteData.height = waffleNS::HEIGHT;
	spriteData.x = waffleNS::X;                   // location on screen
	spriteData.y = waffleNS::Y;
	spriteData.rect.bottom = waffleNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = waffleNS::WIDTH;
	velocity.x = 10;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = waffleNS::WAFFLE_ANIMATION_DELAY;
	startFrame = waffleNS::WAFFLE_START_FRAME;     // first frame of waffle animation
	endFrame = waffleNS::WAFFLE_END_FRAME;     // last frame of waffle animation
	currentFrame = startFrame;
	x = waffleNS::X;
	y = waffleNS::Y;
	tileX = floor(x / tileNS::WIDTH);
	tileY = floor(y / tileNS::HEIGHT);
	state = 1;
	timer = 0;
	playerX = 0;
	playerY = 0;
}

//SoldierWaffle::SoldierWaffle(int gx, int gy) : Entity()
//{
//	spriteData.width = waffleNS::WIDTH;           // size of waffle1
//	spriteData.height = waffleNS::HEIGHT;
//	spriteData.x = gx;                   // location on screen
//	spriteData.y = gy;
//	spriteData.rect.bottom = waffleNS::HEIGHT;    // rectangle to select parts of an image
//	spriteData.rect.right = waffleNS::WIDTH;
//	velocity.x = 2;                             // velocity X
//	velocity.y = 0;                             // velocity Y
//	frameDelay = waffleNS::WAFFLE_ANIMATION_DELAY;
//	startFrame = waffleNS::WAFFLE_START_FRAME;     // first frame of waffle animation
//	endFrame = waffleNS::WAFFLE_END_FRAME;     // last frame of waffle animation
//	currentFrame = startFrame;
//	x = gx;
//	y = gy;
//	tileX = floor(x / 72);
//	tileY = floor(y / 72);
//}

bool SoldierWaffle::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void SoldierWaffle::draw()
{
	Image::draw();              // draw cake
}

void SoldierWaffle::update(float frameTime, float hOffset)
{
	Entity::update(frameTime);
	spriteData.x = x - hOffset;
	spriteData.y = y;

	x += frameTime * velocity.x;
	y += frameTime * velocity.y;

	tileX = floor((x + waffleNS::WIDTH / 2) / 72);
	tileY = floor((y + waffleNS::HEIGHT / 2 )/ 72);

	velocity.y += (gravity * frameTime);
}

void SoldierWaffle::ai(float frameTime)
{
	//state 1 = roaming, 2 = waiting, 3 = chasing, 4 = alarmed

	if (getPlayerDist() <= 200)//within vision
	{
		if ((playerX - x) < 0)
		{
			velocity.x = -200;
		}
		else
		{
			if ((playerX - x) > 0)
			{
				velocity.x = 200;
			}
		}
	}

	if (state == 1) //roaming
	{
		if (getTileBelow() == 3 || getTileBelow() == 4)
		{
			velocity.x = 0;
			timer += 1;
		}

		if (timer == 200)
		{
			state = 2;
			timer = 0;
		}
	}
	
	if (state == 2) // waiting state
	{
		if (getTileBelow() == 3)
		{
			velocity.x = 200;
		}
		if (getTileBelow() == 4)
		{
			velocity.x = -200;
		}
		if (getTileBelow() == 1)
		{
			state = 1;
		}
	}
}

bool SoldierWaffle::collision(float frameTime, float pXvelocity, float pYvelocity)
{
	if (getTileBelow() == 1 || getTileBelow() == 3 || getTileBelow() == 4 || getTileBelow() == 5)
	{
		velocity.y = 0;
		y = ((tileY) * 72) - 14;
	}

	if (getTileAhead() == 1 || getTileAhead() == 3 || getTileAhead() == 4 || getTileAhead() == 5)
	{
		velocity.x = -velocity.x;
	}

	if ((x + getWidth() >= playerX) && (x <= playerX + getWidth()) && (y + getHeight() >= playerY) && (y <= playerY + getHeight())) //collision with player has occured
	{
		//float prevPosY = playerY - (pYvelocity * frameTime);
		//if ((prevPosY + 96) <= y)
		//{
		//	velocity.y = -400;
		//}
		return true;
	}
	else
	{
		return false;
	}
}

int SoldierWaffle::getTileBelow()
{
	return a.getTile(tileY + 1, tileX);
}

int SoldierWaffle::getTileAhead()
{
	if (velocity.x < 0)
	{
		return a.getTile(tileY, tileX - 1);
	}
	if (velocity.x > 0)
	{
		return a.getTile(tileY, tileX + 1);
	}
	if (velocity.x == 0)
	{
		return -1;
	}
}

void SoldierWaffle::setPlayerPos(float pX, float pY)
{
	playerX = pX;
	playerY = pY;
}

float SoldierWaffle::getPlayerDist()
{
	return sqrt((x - playerX) * (x - playerX) + (y - playerY) * (y - playerY));
}
float SoldierWaffle::getPlayerAngle()
{
	return atan2(x - playerX, y - playerY);
}

float SoldierWaffle::getTileX()
{
	return x;
}

float SoldierWaffle::getTileY()
{
	return y;
}