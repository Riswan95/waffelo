//COMPILED 15 FEB FINAL BUILD
// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and MOVE
// Chapter 6 Waffelo.cpp v1.0
// This class is the core of the game

#include "waffelo.h"

//=======================================================================================================================================================================================================================================
// Constructor
//=======================================================================================================================================================================================================================================
Waffelo::Waffelo()
{}

//=======================================================================================================================================================================================================================================
// Destructor
//=======================================================================================================================================================================================================================================
Waffelo::~Waffelo()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=======================================================================================================================================================================================================================================
// Initializes the game
// Throws GameError on error
//=======================================================================================================================================================================================================================================
void Waffelo::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError
	bool jump = false;
	//WafflePos[0] = bubble.getX();

	//for (int i = 0; i < 2; i++)
	//{
	//	WafflePos[1] = shrink[i].getX();
	//}

	// Background texture
    if (!backgroundTexture.initialize(graphics,BACKGROUND_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Background texture"));

    // cake textures
    if (!cakeTexture.initialize(graphics,CAKES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Cake texture"));

	//tile texture
	if (!TileTexture.initialize(graphics, TILE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Tile texture"));

	//tile water texture
	if (!TileWaterTexture.initialize(graphics, TILE_WATER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Tile Water texture"));

	// PauseUi texture
	if (!pauseUiTexture.initialize(graphics, PAUSE_UI_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui texture"));

	// PauseUiresume texture
	if (!pauseUiresumeTexture.initialize(graphics, PAUSE_RESUME_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui resume texture"));

	// PauseUirestart texture
	if (!pauseUirestartTexture.initialize(graphics, PAUSE_RESTART_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui restart texture"));

	// PauseUiMainMenu texture
	if (!pauseUiMainMenuTexture.initialize(graphics, PAUSE_MAINMENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui mainmenu texture"));

	// AttentionUi texture
	if (!attentionUiTexture.initialize(graphics, ATTENTION_UI_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing attention Ui texture"));

	// swl texture
	if (!swTexture.initialize(graphics, SOLDIER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing waffeleo texture"));

	// portal texture
	if (!portalTexture.initialize(graphics, PORTAL_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing portal texture"));

	// portal image
	if (!portal.initialize(this, 0, 0, 0, &portalTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing portal image"));

	// Background image
	if (!background.initialize(graphics,0,0,0,&backgroundTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background image"));

    // Cake image
    if (!cake.initialize(this, cakeNS::WIDTH, cakeNS::HEIGHT, cakeNS::TEXTURE_COLS, &cakeTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cake image"));
		
	// tile image
	if (!tiles.initialize(this, tileNS::WIDTH, tileNS::HEIGHT, 0, &TileTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing tile image"));

	// tile water image
	if (!tilesWater.initialize(this, tileNS::WIDTH, tileNS::HEIGHT, 0, &TileWaterTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing tile water image"));

	// PauseUi image
	if (!pauseUi.initialize(graphics, 0, 0, 0, &pauseUiTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui image"));

	// PauseUiresume image
	if (!pauseUiresume.initialize(graphics, 200, 171/2, 1, &pauseUiresumeTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui resume image"));

	// PauseUirestart image
	if (!pauseUirestart.initialize(graphics, 200, 171 / 2, 1, &pauseUirestartTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui restart image"));

	// PauseUimainmenu image
	if (!pauseUiMainMenu.initialize(graphics, 200, 171 / 2, 1, &pauseUiMainMenuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui mainmenu image"));
	
	// AttentionUi image
	if (!attentionUi.initialize(graphics, 0, 0, 0, &attentionUiTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing attention Ui image"));

	// sw image
	if (!sw.initialize(this, waffleNS::WIDTH, waffleNS::WIDTH, waffleNS::TEXTURE_COLS, &swTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing waffeleo image"));
	
	//Text
	if (gameFont.initialize(graphics, 30, false, false, "Courier New") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font for Achievement."));

	////tile test texture
	//if (!TileTestTexture.initialize(graphics, TILE_IMAGE_TEST))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Tile Test texture"));

	//// tile test image
	//if (!testTile.initialize(this, tileNS::WIDTH, tileNS::HEIGHT, 0, &TileTestTexture))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing tile image"));

	//TEST DELETE LATER
	if (!test.initialize(this, cakeNS::WIDTH, cakeNS::HEIGHT, cakeNS::TEXTURE_COLS, &cakeTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing test image"));

	// menu texture
	if (!menuTexture.initialize(graphics, MENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));
	// menu image
	if (!menu.initialize(graphics, 0, 0, 0, &menuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	// START OF MENU TEXTURE
	// menu selector texture
	//if (!menuSelectorTexture.initialize(graphics, MENUSELECTOR_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));

	//// menu selector image
	//if (!menuSelector.initialize(graphics, 0, 0, 0, &menuSelectorTexture))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	// menu texture
	if (!menuTexture.initialize(graphics, MENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));
	// menu image
	if (!menu.initialize(graphics, 0, 0, 0, &menuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	// menu start texture
	if (!menuStartTexture.initialize(graphics, MENU_START_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu start texture"));

	// menu credits texture
	if (!menuCreditsTexture.initialize(graphics, MENU_CREDITS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu start texture"));

	// menu exit texture
	if (!menuExitTexture.initialize(graphics, MENU_EXIT_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu start texture"));

	// menu start image
	if (!menuStart.initialize(graphics, 435, 404 / 2, 1, &menuStartTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu start image"));

	// menu credits image
	if (!menuCredits.initialize(graphics, 435, 404 / 2, 1, &menuCreditsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu credits image"));

	// menu exit image
	if (!menuExit.initialize(graphics, 435, 404 / 2, 1, &menuExitTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu exit image"));

	// END OF MENU TEXTURE

	if (!activationTexture.initialize(graphics, ACTIVATION_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing berry waffle texture"));

	if (!activation.initialize(graphics, 374, 28, 1, &activationTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui restart image"));

	// START OF WAFFLE TEXTURE
	// berry
	if (!berryTexture.initialize(graphics, BERRY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing berry waffle texture"));

	// bubble
	if (!bubbleTexture.initialize(graphics, BUBBLE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing berry waffle texture"));

	// jumpHigh
	if (!jumpHighTexture.initialize(graphics, JUMPHIGH_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing berry waffle texture"));

	// shrink
	if (!shrinkTexture.initialize(graphics, SHRINK_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing berry waffle texture"));

	// strength
	if (!strengthTexture.initialize(graphics, STRENGTH_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing berry waffle texture"));
	// END OF WAFFLE TEXTURE

	// bullet texture
	if (!bulletTexture.initialize(graphics, BULLET_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet texture"));

	// breakable texture
	if (!breakableTexture.initialize(graphics, BREAKABLE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing breakable texture"));

	if (!healthTexture.initialize(graphics, HEART_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing breakable texture"));

	// START OF WAFFLE IMAGE
	// berry image

	for (int i = 0; i < 2; i++)
	{
		if (!berry[i].initialize(this, waffleCollectibleNS::WIDTH, waffleCollectibleNS::HEIGHT, waffleCollectibleNS::TEXTURE_COLS, &berryTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing berry waffle image"));
	}


	for (int i = 0; i < 2; i++)
	{
		if (!bubble[i].initialize(this, waffleCollectibleNS::WIDTH, waffleCollectibleNS::HEIGHT, waffleCollectibleNS::TEXTURE_COLS, &bubbleTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bubble waffle image"));
	}


	for (int i = 0; i < 2; i++)
	{
		if (!jumpHigh[i].initialize(this, waffleCollectibleNS::WIDTH, waffleCollectibleNS::HEIGHT, waffleCollectibleNS::TEXTURE_COLS, &jumpHighTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing jump high waffle image"));
	}
	
	for (int i = 0; i < 2; i++)
	{
		if (!shrink[i].initialize(this, waffleCollectibleNS::WIDTH, waffleCollectibleNS::HEIGHT, waffleCollectibleNS::TEXTURE_COLS, &shrinkTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing shrink waffle image"));
	}

	for (int i = 0; i < 2; i++)
	{
		if (!strength[i].initialize(this, waffleCollectibleNS::WIDTH, waffleCollectibleNS::HEIGHT, waffleCollectibleNS::TEXTURE_COLS, &strengthTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing strength waffle image"));
	}
	// END OF WAFFLE IMAGE

	for (int i = 0; i < 2; i++)
	{
		if (!breakable.initialize(this, breakableNS::WIDTH, breakableNS::HEIGHT, breakableNS::TEXTURE_COLS, &breakableTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing strength waffle image"));
	}

	for (int i = 0; i < 2; i++)
	{
		if (!health.initialize(graphics, 129, 37, 1, &healthTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Ui restart image"));
	}

	//breakable.setFrames(breakable.getStartFrame(), breakable.getStartFrame());



	bulletMax[0] = bullet1;
	bulletMax[1] = bullet2;
	bulletMax[2] = bullet3;


	for (int i = 0; i < 3; i++)
	{
		if (!bulletMax[i].initialize(this, bulletNS::WIDTH, bulletNS::HEIGHT, 1, &bulletTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet image"));
	}

	velocityBullet[0] = bulletMax[0].getVelocity();
	velocityBullet[1] = bulletMax[1].getVelocity();
	velocityBullet[2] = bulletMax[2].getVelocity();

	activation.setY(0);
	activation.setX(500);
	activation.setVisible(false);

    return;
}

//=======================================================================================================================================================================================================================================
// Update all game items
//=======================================================================================================================================================================================================================================
void Waffelo::update()
{

		PlaySound("sound\\backGround.wav", NULL, SND_ASYNC);
	

	//if (menuOn == true)
	//{
	//	//("sound\\backGround.wav", NULL, SND_ASYNC);
	//}

	sw.update(frameTime, hOffset);

	cake.setVisible(true);
	if (cake.getHealth() == 300)
	{
		health.setCurrentFrame(0);
	}
	else if (cake.getHealth() == 200)
	{
		health.setCurrentFrame(1);
	}
	else if (cake.getHealth() == 100)
	{
		health.setCurrentFrame(2);
	}
	else if (cake.getHealth() == 0)
	{
		health.setCurrentFrame(3);
		paused = true;
		attentionOn = true;
	}


	//breakable.setFrames(breakable.getStartFrame(), breakable.getStartFrame());


	//if (menuOn)
	//{
	//	if (menuPosition == 1)
	//	{
	//		menuSelector.setX(750);
	//		menuSelector.setY(275);
	//	}
	//	else if (menuPosition == 2)
	//	{
	//		menuSelector.setX(750);
	//		menuSelector.setY(450);
	//	}

	//	if (input->isKeyDown(DOWN_KEY))
	//	{
	//		menuPosition++;
	//		if (menuPosition >= 2)
	//		{
	//			menuPosition = 2;
	//		}
	//	}

	//	if (input->isKeyDown(UP_KEY))
	//	{
	//		menuPosition--;
	//		if (menuPosition <= 1)
	//		{
	//			menuPosition = 1;
	//		}
	//	}

	//	if (input->isKeyDown(ENTER_KEY))
	//	{
	//		if (menuPosition == 1)
	//		{
	//			menuOn = false;
	//			//input->clearAll();
	//		}

	//		else if (menuPosition == 2)
	//		{
	//			PostQuitMessage(0);
	//		}
	//	}
	//}

	/*if (velocity.y <= 300)
	{*/
		velocity.y += (gravity * frameTime);
	//}
	cake.setY(cake.getY() + frameTime * velocity.y);
	cake.setFrames(0, 1);


	//MOVE START
	// if move right
	if (input->isKeyDown(CAKE_RIGHT_KEY))
	{

		cake.setFrames(2, 3);
		velocity.x += 200;
		cake.setX(cake.getX() + frameTime * velocity.x);

		if (cake.getX() >= midpoint)
		{
			cake.setX(midpoint);
			background.setX(background.getX() - frameTime * velocity.x *0.5f);
			hOffset += frameTime * velocity.x; //keeps changing the offset
		}
		cake.flipHorizontal(false);
		flip = false;
	}

	if (!input->isKeyDown(CAKE_RIGHT_KEY))
	{
		//cake.setFrames(0, 1);
		velocity.x = 0;
		cake.setX(cake.getX() + frameTime * velocity.x);
	}
	if (cake.getX() > GAME_WIDTH)               // if off screen right
		cake.setX((float)-cake.getWidth()); // position off screen left
	//MOVE RIGHT END


	// if move left
	if (input->isKeyDown(CAKE_LEFT_KEY))
	{
		cake.setFrames(2, 3);
		velocity.x -= 200;
		cake.setX(cake.getX() + frameTime * velocity.x);

		if (cake.getX() < midpoint)
		{
			//background.setX(background.getX() - frameTime * velocity.x *0.5f);
			//cake.setX(midpoint);
			//hOffset += frameTime * velocity.x; //keeps changing the offset
		}
		cake.flipHorizontal(true);
		flip = true;
	}

	if (!input->isKeyDown(CAKE_LEFT_KEY))
	{
		//cake.setFrames(0, 1);
		velocity.x = 0;
		cake.setX(cake.getX() + frameTime * velocity.x);
	}
	if (cake.getX() < -cake.getWidth())         // if off screen left
		cake.setX((float)GAME_WIDTH);      // position off screen right
	//MOVE LEFT END
	//MOVE END




	//if Jump
	if (input->wasKeyPressed(CAKE_UP_KEY) && doubleJump > 0 && jumpCounter > 0)
	{

		PlaySound("sound\\jump.wav", NULL, SND_ASYNC);
		

		if (jumpHighAct == false)
		{
			velocity.y = -JumpForce;
			doubleJump--;
			jumpCounter--;
		}

		//waffle jump High
		else if (jumpHighAct == true && doubleJump > 0)
		{
			velocity.y = -JumpForce * 1.75;
			doubleJump = 0;
			jumpCounter--;
		}
		cake.setCurrentFrame(4);
	}


	// START OF WAFFLES
	//SHRINK START

	if (shrinkAct == true && cake.getScale() >= 0.5)
	{
		cake.setScale(cake.getScale() - frameTime * SCALE_RATE);
		cake.setCollisionRadius(cake.getRadius());
	}

	//cake.DeactivatePower(&shrink);
	if (shrinkAct == false && cake.getScale() <= 1)
	{
		cake.setScale(cake.getScale() + frameTime * SCALE_RATE);
	}
	//SHRINK END

	//BUBBLE START
	if (bubbleAct == true)
	{
		cake.setBubble(true);
		// Collision with water is always false;
	}

	else if (bubbleAct == false)
	{
		cake.setBubble(false);
		//bubbleImage.setAnimationComplete(false);
		// collision with water is back
	}
	//BUBBLE END


	//BERRY START
	if (berryAct == true)
	{
		if (input->wasKeyPressed(E_KEY) && bull < 3 && flip == false)
		{

			velocityBullet[bull].x = 700;

			bulletMax[bull].setX(cake.getX() + (cake.getWidth() / 2)); // sets horizontal bullet position to be at cake's hand
			bulletMax[bull].setY(cake.getY()); // sets vertical bullet position at cake's center

			bull++;
		}

		else if (input->wasKeyPressed(E_KEY) && bull < 3 && flip == true)
		{
			velocityBullet[bull].x = -700;

			bulletMax[bull].setX(cake.getX() - (cake.getWidth() / 2)); // sets horizontal bullet position to be at cake's hand
			bulletMax[bull].setY(cake.getY()); // sets vertical bullet position at cake's center

			bull++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		/*if ((bulletMax[i].getX() > cake.getX() + GAME_WIDTH - cake.getWidth() && cake.getX() < midpoint) || (bulletMax[i].getX() > cake.getX() + GAME_WIDTH / 2 - cake.getWidth() && cake.getX() == midpoint) || (bulletMax[i].getX() < cake.getX() - GAME_WIDTH + cake.getWidth() && cake.getX() > midpoint) || (bulletMax[i].getX() < cake.getX() - GAME_WIDTH / 2 + cake.getWidth() && cake.getX() == midpoint))
		{
			bulletMax[i].setScale(0);
		}*/

		bulletMax[i].setX(bulletMax[i].getX() + frameTime * velocityBullet[i].x); // enables bullet to move

		bulletMax[i].update(frameTime);
	}
		//BERRY END



		cake.update(frameTime);

	for (int i = 0; i < 2; i++)
	{
		berry[i].update(frameTime);
	}
	for (int i = 0; i < 2; i++)
	{
		bubble[i].update(frameTime);
	}
	for (int i = 0; i < 2; i++)
	{
		jumpHigh[i].update(frameTime);
	}

	for (int i = 0; i < 2; i++)
	{
		shrink[i].update(frameTime);
	}

	for (int i = 0; i < 2; i++)
	{
		strength[i].update(frameTime);
	}
}

//=======================================================================================================================================================================================================================================
// Artificial Intelligence
//=======================================================================================================================================================================================================================================
void Waffelo::ai()
{
	sw.setPlayerPos(cake.getX() + hOffset, cake.getY());
	sw.ai(frameTime);
}

//=======================================================================================================================================================================================================================================
// Handle collisions
//=======================================================================================================================================================================================================================================
void Waffelo::collisions()
{
	endText = false;
	VECTOR2 collisionVector;
	if (sw.collision(frameTime, velocity.x, velocity.y))
	{
		cake.setHealth(cake.getHealth() - 1);
	}

//=============================================================================
// Check TILES
//=============================================================================
	RECT caketest = cake.getSpriteDataRect();
	int cakeY = ceil(cake.getCenterY()) / 72;
	int cakeX = ceil(cake.getCenterX() + hOffset) / 72;
	testTile.setX(0);
	testTile.setY(0);
	
	if (tut)
	{
		//Check for tiles when jumping
		if ((tileNS::mapDesignTut[cakeY - 1][cakeX] == 1) && (velocity.y <= 0))
		{
			//test.setY((cakeY - 1) * 72);
			//test.setX((cakeX * 72) - hOffset);

			testTile.setY((cakeY - 1) * 72);
			testTile.setX((cakeX * 72) - hOffset);

			if ((cake.getY()) <= (testTile.getY() + testTile.getHeight()))
			{
				cake.setY(testTile.getY() + testTile.getHeight());
				velocity.y = -velocity.y;
			}
		}


		//check for tiles when falling
		if (velocity.y >= 0)
		{
			if (tileNS::mapDesignTut[cakeY + 1][cakeX] == 1)
			{
				testTile.setY((cakeY + 1) * 72);
				testTile.setX((cakeX * 72) - hOffset);

				//test.setY((cakeY + 1) * 72);
				//test.setX((cakeX * 72) - hOffset);
				if (((cake.getY() + cake.getHeight()*cake.getScale()) > testTile.getY()))
				{
					cake.setY((testTile.getY() - cake.getHeight()*cake.getScale()));
					velocity.y = 0;
					doubleJump = 2;
				}
			}

			if (tileNS::mapDesignTut[cakeY + 1][cakeX] == 0)
			{
				cake.setCurrentFrame(5);
			}

			//if ((tileNS::mapDesign[cakeY + 1][cakeX] == 1) && (tileNS::mapDesign[cakeY + 1][cakeX + 1] == 0))
			//{
			//	testTile.setY((cakeY + 1) * 72);
			//	testTile.setX(cakeX * 72);

			//	//test.setY((cakeY + 1) * 72);
			//	//test.setX((cakeX + 1) * 72);
			//	if (((cake.getY() + cake.getHeight()*cake.getScale()) >= testTile.getY()) && ((testTile.getX()) <= (cake.getCenterX()) <= (testTile.getX() + testTile.getWidth())))
			//	{
			//		cake.setY((testTile.getY() - cake.getHeight()*cake.getScale()));
			//		velocity.y = 0;
			//	}
			//}
		}


		//when moving right
		if (velocity.x >= 0)
		{
			//check for tile on right
			if (tileNS::mapDesignTut[cakeY][cakeX + 1] == 1)
			{
				testTile.setY(cakeY * 72);
				testTile.setX(((cakeX + 1) * 72) - hOffset);

				if ((cake.getX() + cake.getWidth()*cake.getScale()) > testTile.getX())
				{
					test.setY(cakeY * 72);
					test.setX(((cakeX + 1) * 72) - hOffset);
					cake.setX(testTile.getX() - cake.getWidth()*cake.getScale());
					velocity.x = -velocity.x;
				}
			}

			//check for tile on the top right & bot right
			if ((tileNS::mapDesignTut[cakeY - 1][cakeX + 1] == 1) && (tileNS::mapDesignTut[cakeY + 1][cakeX + 1] == 1))
			{

				testTile.setY((cakeY - 1) * 72);
				testTile.setX(((cakeX + 1) * 72) - hOffset);

				if (((cake.getX() + cake.getWidth()) > testTile.getX()) && (cake.getY() <= (testTile.getY() + testTile.getHeight())))
				{
					//test.setY(cakeY * 72);
					//test.setX(((cakeX + 1) * 72) - hOffset);
					cake.setX(testTile.getX() - cake.getWidth()*cake.getScale());
					velocity.x = -velocity.x;
				}
			}

		}


		//when moving left
		if (velocity.x < 0)
		{
			//check for tile on the left
			if (tileNS::mapDesignTut[cakeY][cakeX - 1] == 1)
			{

				testTile.setY(cakeY * 72);
				testTile.setX(((cakeX - 1) * 72) - hOffset);

				if (cake.getX() < (testTile.getX() + testTile.getWidth()))
				{
					//test.setY(cakeY * 72);
					//test.setX(((cakeX - 1) * 72) - hOffset);
					cake.setX(testTile.getX() + testTile.getWidth());
					velocity.x = -velocity.x;
				}
			}

			//check for tile on top left and bot left
			if ((tileNS::mapDesignTut[cakeY - 1][cakeX - 1] == 1) && (tileNS::mapDesignTut[cakeY + 1][cakeX - 1] == 1))
			{

				testTile.setY((cakeY - 1) * 72);
				testTile.setX(((cakeX - 1) * 72) - hOffset);

				if ((cake.getX() < testTile.getX() + testTile.getWidth()) && (cake.getY() <= (testTile.getY() + testTile.getHeight())))
				{
					//test.setY(cakeY * 72);
					//test.setX(((cakeX - 1) * 72) - hOffset);
					cake.setX(testTile.getX() + testTile.getWidth());
					velocity.x = -velocity.x;
				}
			}

		}
	}

	if (level1)
	{
		//Check for tiles when jumping
		if ((tileNS::mapDesign1[cakeY - 1][cakeX] == 1) && (velocity.y <= 0))
		{
			//test.setY((cakeY - 1) * 72);
			//test.setX((cakeX * 72) - hOffset);

			testTile.setY((cakeY - 1) * 72);
			testTile.setX((cakeX * 72) - hOffset);

			if ((cake.getY()) <= (testTile.getY() + testTile.getHeight()))
			{
				cake.setY(testTile.getY() + testTile.getHeight());
				velocity.y = -velocity.y;
			}
		}


		//check for tiles when falling
		if (velocity.y >= 0)
		{
			if (tileNS::mapDesign1[cakeY + 1][cakeX] == 1)
			{
				testTile.setY((cakeY + 1) * 72);
				testTile.setX((cakeX * 72) - hOffset);

				//test.setY((cakeY + 1) * 72);
				//test.setX((cakeX * 72) - hOffset);
				if (((cake.getY() + cake.getHeight()*cake.getScale()) > testTile.getY()))
				{
					cake.setY((testTile.getY() - cake.getHeight()*cake.getScale()));
					velocity.y = 0;
					doubleJump = 2;
				}
			}

			if (tileNS::mapDesign1[cakeY + 1][cakeX] == 0)
			{
				cake.setCurrentFrame(5);
			}

			//if ((tileNS::mapDesign[cakeY + 1][cakeX] == 1) && (tileNS::mapDesign[cakeY + 1][cakeX + 1] == 0))
			//{
			//	testTile.setY((cakeY + 1) * 72);
			//	testTile.setX(cakeX * 72);

			//	//test.setY((cakeY + 1) * 72);
			//	//test.setX((cakeX + 1) * 72);
			//	if (((cake.getY() + cake.getHeight()*cake.getScale()) >= testTile.getY()) && ((testTile.getX()) <= (cake.getCenterX()) <= (testTile.getX() + testTile.getWidth())))
			//	{
			//		cake.setY((testTile.getY() - cake.getHeight()*cake.getScale()));
			//		velocity.y = 0;
			//	}
			//}
		}


		//when moving right
		if (velocity.x >= 0)
		{
			//check for tile on right
			if (tileNS::mapDesign1[cakeY][cakeX + 1] == 1)
			{
				testTile.setY(cakeY * 72);
				testTile.setX(((cakeX + 1) * 72) - hOffset);

				if ((cake.getX() + cake.getWidth()*cake.getScale()) > testTile.getX())
				{
					test.setY(cakeY * 72);
					test.setX(((cakeX + 1) * 72) - hOffset);
					cake.setX(testTile.getX() - cake.getWidth()*cake.getScale());
					velocity.x = -velocity.x;
				}
			}

			//check for tile on the top right & bot right
			if ((tileNS::mapDesign1[cakeY - 1][cakeX + 1] == 1) && (tileNS::mapDesign1[cakeY + 1][cakeX + 1] == 1))
			{

				testTile.setY((cakeY - 1) * 72);
				testTile.setX(((cakeX + 1) * 72) - hOffset);

				if (((cake.getX() + cake.getWidth()) > testTile.getX()) && (cake.getY() <= (testTile.getY() + testTile.getHeight())))
				{
					//test.setY(cakeY * 72);
					//test.setX(((cakeX + 1) * 72) - hOffset);
					cake.setX(testTile.getX() - cake.getWidth()*cake.getScale());
					velocity.x = -velocity.x;
				}
			}

		}


		//when moving left
		if (velocity.x < 0)
		{
			//check for tile on the left
			if (tileNS::mapDesign1[cakeY][cakeX - 1] == 1)
			{

				testTile.setY(cakeY * 72);
				testTile.setX(((cakeX - 1) * 72) - hOffset);

				if (cake.getX() < (testTile.getX() + testTile.getWidth()))
				{
					//test.setY(cakeY * 72);
					//test.setX(((cakeX - 1) * 72) - hOffset);
					cake.setX(testTile.getX() + testTile.getWidth());
					velocity.x = -velocity.x;
				}
			}

			//check for tile on top left and bot left
			if ((tileNS::mapDesign1[cakeY - 1][cakeX - 1] == 1) && (tileNS::mapDesign1[cakeY + 1][cakeX - 1] == 1))
			{

				testTile.setY((cakeY - 1) * 72);
				testTile.setX(((cakeX - 1) * 72) - hOffset);

				if ((cake.getX() < testTile.getX() + testTile.getWidth()) && (cake.getY() <= (testTile.getY() + testTile.getHeight())))
				{
					//test.setY(cakeY * 72);
					//test.setX(((cakeX - 1) * 72) - hOffset);
					cake.setX(testTile.getX() + testTile.getWidth());
					velocity.x = -velocity.x;
				}
			}

		}
	}

	if (level2)
	{
		//Check for tiles when jumping
		if ((tileNS::mapDesign2[cakeY - 1][cakeX] == 1) && (velocity.y <= 0))
		{
			//test.setY((cakeY - 1) * 72);
			//test.setX((cakeX * 72) - hOffset);

			testTile.setY((cakeY - 1) * 72);
			testTile.setX((cakeX * 72) - hOffset);

			if ((cake.getY()) <= (testTile.getY() + testTile.getHeight()))
			{
				cake.setY(testTile.getY() + testTile.getHeight());
				velocity.y = -velocity.y;
			}
		}


		//check for tiles when falling
		if (velocity.y >= 0)
		{
			if (tileNS::mapDesign2[cakeY + 1][cakeX] == 1)
			{
				testTile.setY((cakeY + 1) * 72);
				testTile.setX((cakeX * 72) - hOffset);

				//test.setY((cakeY + 1) * 72);
				//test.setX((cakeX * 72) - hOffset);
				if (((cake.getY() + cake.getHeight()*cake.getScale()) > testTile.getY()))
				{
					cake.setY((testTile.getY() - cake.getHeight()*cake.getScale()));
					velocity.y = 0;
					doubleJump = 2;
				}
			}

			if (tileNS::mapDesign2[cakeY + 1][cakeX] == 0)
			{
				cake.setCurrentFrame(5);
			}

			//if ((tileNS::mapDesign[cakeY + 1][cakeX] == 1) && (tileNS::mapDesign[cakeY + 1][cakeX + 1] == 0))
			//{
			//	testTile.setY((cakeY + 1) * 72);
			//	testTile.setX(cakeX * 72);

			//	//test.setY((cakeY + 1) * 72);
			//	//test.setX((cakeX + 1) * 72);
			//	if (((cake.getY() + cake.getHeight()*cake.getScale()) >= testTile.getY()) && ((testTile.getX()) <= (cake.getCenterX()) <= (testTile.getX() + testTile.getWidth())))
			//	{
			//		cake.setY((testTile.getY() - cake.getHeight()*cake.getScale()));
			//		velocity.y = 0;
			//	}
			//}
		}


		//when moving right
		if (velocity.x >= 0)
		{
			//check for tile on right
			if (tileNS::mapDesign2[cakeY][cakeX + 1] == 1)
			{
				testTile.setY(cakeY * 72);
				testTile.setX(((cakeX + 1) * 72) - hOffset);

				if ((cake.getX() + cake.getWidth()*cake.getScale()) > testTile.getX())
				{
					test.setY(cakeY * 72);
					test.setX(((cakeX + 1) * 72) - hOffset);
					cake.setX(testTile.getX() - cake.getWidth()*cake.getScale());
					velocity.x = -velocity.x;
				}
			}

			//check for tile on the top right & bot right
			if ((tileNS::mapDesign2[cakeY - 1][cakeX + 1] == 1) && (tileNS::mapDesign2[cakeY + 1][cakeX + 1] == 1))
			{

				testTile.setY((cakeY - 1) * 72);
				testTile.setX(((cakeX + 1) * 72) - hOffset);

				if (((cake.getX() + cake.getWidth()) > testTile.getX()) && (cake.getY() <= (testTile.getY() + testTile.getHeight())))
				{
					//test.setY(cakeY * 72);
					//test.setX(((cakeX + 1) * 72) - hOffset);
					cake.setX(testTile.getX() - cake.getWidth()*cake.getScale());
					velocity.x = -velocity.x;
				}
			}

		}


		//when moving left
		if (velocity.x < 0)
		{
			//check for tile on the left
			if (tileNS::mapDesign2[cakeY][cakeX - 1] == 1)
			{

				testTile.setY(cakeY * 72);
				testTile.setX(((cakeX - 1) * 72) - hOffset);

				if (cake.getX() < (testTile.getX() + testTile.getWidth()))
				{
					//test.setY(cakeY * 72);
					//test.setX(((cakeX - 1) * 72) - hOffset);
					cake.setX(testTile.getX() + testTile.getWidth());
					velocity.x = -velocity.x;
				}
			}

			//check for tile on top left and bot left
			if ((tileNS::mapDesign2[cakeY - 1][cakeX - 1] == 1) && (tileNS::mapDesign2[cakeY + 1][cakeX - 1] == 1))
			{

				testTile.setY((cakeY - 1) * 72);
				testTile.setX(((cakeX - 1) * 72) - hOffset);

				if ((cake.getX() < testTile.getX() + testTile.getWidth()) && (cake.getY() <= (testTile.getY() + testTile.getHeight())))
				{
					//test.setY(cakeY * 72);
					//test.setX(((cakeX - 1) * 72) - hOffset);
					cake.setX(testTile.getX() + testTile.getWidth());
					velocity.x = -velocity.x;
				}
			}

		}
	}
//=============================================================================
// END OF CHECK TILES
//=============================================================================
	if (tut)
	{
		if ((tileNS::mapDesignTut[cakeY
		][cakeX] == 2))
		if (bubbleAct == false)
		{
			doubleJump = 2;
		}
		else
		{
			doubleJump = 2;
		}

		// collision between berry and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(berry[i], collisionVector))
			{
				deactivateAll();

				// create bullets
				bull = 0;
				for (int i = 0; i < 3; i++)
				{
					bulletMax[i].setScale(1);
				}
				// end create bullets
				cake.ActivatePower(&berryAct);
				berry[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(0);
			}
		}

		// collision between bubble and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(bubble[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&bubbleAct);
				bubble[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(1);
			}
		}

		// collision between jumpHigh and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(jumpHigh[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&jumpHighAct);
				jumpHigh[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(2);
			}
		}

		// collision between shrink and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(shrink[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&shrinkAct);
				shrink[i].setScale(0);
				shrink[i].getRadius()*shrink[i].getScale();
				//testText = true;
				activation.setVisible(true);
				activation.setCurrentFrame(3);
			}
		}

		// collision between strength and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(strength[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&strengthAct);
				strength[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(4);
			}
		}

		if (cake.collidesWith(breakable, collisionVector))
		{
			velocity.x -= 200;
			if (strengthAct == true)
			{
				if (input->wasKeyPressed(E_KEY))
				{
					//breakable.setFrames(0, 1);
					//breakable.setCurrentFrame(breakable.getEndFrame());

					breakable.setScale(0);
					//test.setX(breakable.getX());
					//test.setY(breakable.getY());
				}
			}
		}

		if (cake.collidesWith(portal, collisionVector)) // go to next level or main menu
		{
			//exitGame();
			paused = true;
			attentionOn = true;
			//restartGame();
			levelNo++;
			//jumpCounter = 10;
		}
	}

	if (level1)
	{
		if ((tileNS::mapDesign1[cakeY
		][cakeX] == 2))
		if (bubbleAct == false)
		{
			cake.setHealth(cake.getHealth() - 1);
			doubleJump = 2;
		}
		else
		{
			doubleJump = 2;
		}

		// collision between berry and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(berry[i], collisionVector))
			{
				deactivateAll();

				// create bullets
				bull = 0;
				for (int i = 0; i < 3; i++)
				{
					bulletMax[i].setScale(1);
				}
				// end create bullets
				cake.ActivatePower(&berryAct);
				berry[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(0);
			}
		}

		// collision between bubble and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(bubble[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&bubbleAct);
				bubble[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(1);
			}
		}

		// collision between jumpHigh and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(jumpHigh[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&jumpHighAct);
				jumpHigh[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(2);
			}
		}

		// collision between shrink and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(shrink[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&shrinkAct);
				shrink[i].setScale(0);
				shrink[i].getRadius()*shrink[i].getScale();
				//testText = true;
				activation.setVisible(true);
				activation.setCurrentFrame(3);
			}
		}

		// collision between strength and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(strength[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&strengthAct);
				strength[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(4);
			}
		}

		if (cake.collidesWith(breakable, collisionVector))
		{
			velocity.x -= 200;
			if (strengthAct == true)
			{
				if (input->wasKeyPressed(E_KEY))
				{
					//breakable.setFrames(0, 1);
					//breakable.setCurrentFrame(breakable.getEndFrame());

					breakable.setScale(0);
					//test.setX(breakable.getX());
					//test.setY(breakable.getY());
				}
			}
		}

		if (cake.collidesWith(portal, collisionVector)) // go to next level or main menu
		{
			//exitGame();
			paused = true;
			attentionOn = true;
			//restartGame();
			levelNo++;
			//jumpCounter = 10;
		}
	}

	if (level2)
	{
		if ((tileNS::mapDesign2[cakeY
		][cakeX] == 2))
		if (bubbleAct == false)
		{
			cake.setHealth(cake.getHealth() - 1);
			doubleJump = 2;
		}
		else
		{
			doubleJump = 2;
		}

		// collision between berry and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(berry[i], collisionVector))
			{
				deactivateAll();

				// create bullets
				bull = 0;
				for (int i = 0; i < 3; i++)
				{
					bulletMax[i].setScale(1);
				}
				// end create bullets
				cake.ActivatePower(&berryAct);
				berry[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(0);
			}
		}

		// collision between bubble and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(bubble[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&bubbleAct);
				bubble[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(1);
			}
		}

		// collision between jumpHigh and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(jumpHigh[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&jumpHighAct);
				jumpHigh[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(2);
			}
		}

		// collision between shrink and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(shrink[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&shrinkAct);
				shrink[i].setScale(0);
				shrink[i].getRadius()*shrink[i].getScale();
				//testText = true;
				activation.setVisible(true);
				activation.setCurrentFrame(3);
			}
		}

		// collision between strength and Cakes
		for (int i = 0; i < 2; i++)
		{
			if (cake.collidesWith(strength[i], collisionVector))
			{
				deactivateAll();
				cake.ActivatePower(&strengthAct);
				strength[i].setScale(0);
				activation.setVisible(true);
				activation.setCurrentFrame(4);
			}
		}

		if (cake.collidesWith(breakable, collisionVector))
		{
			velocity.x -= 200;
			if (strengthAct == true)
			{
				if (input->wasKeyPressed(E_KEY))
				{
					//breakable.setFrames(0, 1);
					//breakable.setCurrentFrame(breakable.getEndFrame());

					breakable.setScale(0);
					//test.setX(breakable.getX());
					//test.setY(breakable.getY());
				}
			}
		}

		if (cake.collidesWith(portal, collisionVector)) // go to next level or main menu
		{
			//exitGame();
			paused = true;
			attentionOn = true;
			//restartGame();
			levelNo++;
			//jumpCounter = 10;
		}
	}
}

//=======================================================================================================================================================================================================================================
// Render game items
//=======================================================================================================================================================================================================================================
void Waffelo::render()
{
	int shrinkCounter = 0;
	int berryCounter = 0;
	int jumpHighCounter = 0;
	int bubbleCounter = 0;
	int strengthCounter = 0;

	//PAUSEf
	if ((input->isKeyDown(PAUSE_KEY)) && (paused == false) && (menuOn == false))
	{
		paused = true;

	}

	else if ((input->isKeyDown(PAUSE_KEY)) && (paused == true))
	{
		paused = false;
	}

	graphics->spriteBegin();

	
	background.draw();
	health.draw();
	if (testText)
	{
		gameFont.print("CAKE Eaten", 500, 0);
	}

	if (endText)
	{
		gameFont.print("Reached End", 500, 500);
	}
	gameFont.print("Jumps left: " + std::to_string(doubleJump), 1000, 0);
	
	//gameFont.print(std::to_string(cake.getHealth()), 0, 0);

//=============================================================================
// Draw tiles, waffles etc
//=============================================================================
	switch (levelNo)
	{
	default:
		exitGame();
		break;

	case 0:
		level1 = false;
		level2 = false;
		tut = true;
		break;

	case 1: 
		level1 = true;
		level2 = false;
		tut = false;
		break;

	case 2:
		level1 = false;
		level2 = true;
		tut = false;
		break;
	}

	if (level1)
	{
		for (int row = 0; row < tileNS::MAP_HEIGHT; row++) // for each row of map
		{
			tiles.setY((float)(row * tileNS::HEIGHT));	// set tile Y

			for (int col = 0; col < tileNS::MAP_WIDTH; col++)	// for each column of map
			{
				if (tileNS::mapDesign1[row][col] == 1) // if tile present
				{
					tiles.setX((float)(col * tileNS::WIDTH) - hOffset); // set tile X
					tiles.draw(); // draw tile
				}

				if (tileNS::mapDesign1[row][col] == 2) //if water tile
				{
					tilesWater.setY((float)(row * tileNS::WIDTH));	// set tile Y
					tilesWater.setX((float)(col * tileNS::HEIGHT) - hOffset); // set tile X
					tilesWater.draw(); // draw tile
				}

				if (tileNS::mapDesign1[row][col] == 3) //if shrink waffle
				{
					shrink[shrinkCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					shrink[shrinkCounter].setY((float)(row * tileNS::HEIGHT));
					shrink[shrinkCounter].draw();
					shrinkCounter++;
				}

				if (tileNS::mapDesign1[row][col] == 4) //if berry waffle
				{
					berry[berryCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					berry[berryCounter].setY((float)(row * tileNS::HEIGHT));
					berry[berryCounter].draw();
					berryCounter++;

				}

				if (tileNS::mapDesign1[row][col] == 5) //if bubble waffle
				{
					bubble[bubbleCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					bubble[bubbleCounter].setY((float)(row * tileNS::HEIGHT));
					bubble[bubbleCounter].draw();
					bubbleCounter++;

				}

				if (tileNS::mapDesign1[row][col] == 6) //if jumpHigh waffle
				{
					jumpHigh[jumpHighCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					jumpHigh[jumpHighCounter].setY((float)(row * tileNS::HEIGHT));
					jumpHigh[jumpHighCounter].draw();
					jumpHighCounter++;

				}

				if (tileNS::mapDesign1[row][col] == 7) //if strength waffle
				{
					strength[strengthCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					strength[strengthCounter].setY((float)(row * tileNS::HEIGHT));
					strength[strengthCounter].draw();
					strengthCounter++;
				}

				if (tileNS::mapDesign1[row][col] == 8) //if breakable tile
				{
					breakable.setX((float)(col * tileNS::WIDTH) - hOffset);
					breakable.setY((float)(row * tileNS::HEIGHT));
					breakable.draw();
				}

				if (tileNS::mapDesign1[row][col] == 100) //if portal tile
				{
					portal.setX((float)(col * tileNS::WIDTH) - hOffset);
					portal.setY((float)(row * tileNS::HEIGHT));
					portal.draw();
				}
			}
		}
	}

	if (level2)
	{
		for (int row = 0; row < tileNS::MAP_HEIGHT; row++) // for each row of map
		{
			tiles.setY((float)(row * tileNS::HEIGHT));	// set tile Y

			for (int col = 0; col < tileNS::MAP_WIDTH; col++)	// for each column of map
			{
				if (tileNS::mapDesign2[row][col] == 1) // if tile present
				{
					tiles.setX((float)(col * tileNS::WIDTH) - hOffset); // set tile X
					tiles.draw(); // draw tile
				}

				if (tileNS::mapDesign2[row][col] == 2) //if water tile
				{
					tilesWater.setY((float)(row * tileNS::WIDTH));	// set tile Y
					tilesWater.setX((float)(col * tileNS::HEIGHT) - hOffset); // set tile X
					tilesWater.draw(); // draw tile
				}

				if (tileNS::mapDesign2[row][col] == 3) //if shrink waffle
				{
					shrink[shrinkCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					shrink[shrinkCounter].setY((float)(row * tileNS::HEIGHT));
					shrink[shrinkCounter].draw();
					shrinkCounter++;
				}

				if (tileNS::mapDesign2[row][col] == 4) //if berry waffle
				{
					berry[berryCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					berry[berryCounter].setY((float)(row * tileNS::HEIGHT));
					berry[berryCounter].draw();
					berryCounter++;

				}

				if (tileNS::mapDesign2[row][col] == 5) //if bubble waffle
				{
					bubble[bubbleCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					bubble[bubbleCounter].setY((float)(row * tileNS::HEIGHT));
					bubble[bubbleCounter].draw();
					bubbleCounter++;

				}

				if (tileNS::mapDesign2[row][col] == 6) //if jumpHigh waffle
				{
					jumpHigh[jumpHighCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					jumpHigh[jumpHighCounter].setY((float)(row * tileNS::HEIGHT));
					jumpHigh[jumpHighCounter].draw();
					jumpHighCounter++;

				}

				if (tileNS::mapDesign2[row][col] == 7) //if strength waffle
				{
					strength[strengthCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					strength[strengthCounter].setY((float)(row * tileNS::HEIGHT));
					strength[strengthCounter].draw();
					strengthCounter++;
				}

				if (tileNS::mapDesign2[row][col] == 8) //if breakable tile
				{
					breakable.setX((float)(col * tileNS::WIDTH) - hOffset);
					breakable.setY((float)(row * tileNS::HEIGHT));
					breakable.draw();
				}

				if (tileNS::mapDesign2[row][col] == 100) //if portal tile
				{
					portal.setX((float)(col * tileNS::WIDTH) - hOffset);
					portal.setY((float)(row * tileNS::HEIGHT));
					portal.draw();
				}
			}
		}
	}
	if (tut)
	{

		for (int row = 0; row < tileNS::MAP_HEIGHT; row++) // for each row of map
		{
			tiles.setY((float)(row * tileNS::HEIGHT));	// set tile Y

			for (int col = 0; col < tileNS::MAP_WIDTH; col++)	// for each column of map
			{
				if (tileNS::mapDesignTut[row][col] == 1) // if tile present
				{
					tiles.setX((float)(col * tileNS::WIDTH) - hOffset); // set tile X
					tiles.draw(); // draw tile
				}

				if (tileNS::mapDesignTut[row][col] == 2) //if water tile
				{
					tilesWater.setY((float)(row * tileNS::WIDTH));	// set tile Y
					tilesWater.setX((float)(col * tileNS::HEIGHT) - hOffset); // set tile X
					tilesWater.draw(); // draw tile
				}

				if (tileNS::mapDesignTut[row][col] == 3) //if shrink waffle
				{
					shrink[shrinkCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					shrink[shrinkCounter].setY((float)(row * tileNS::HEIGHT));
					shrink[shrinkCounter].draw();
					shrinkCounter++;
				}

				if (tileNS::mapDesignTut[row][col] == 4) //if berry waffle
				{
					berry[berryCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					berry[berryCounter].setY((float)(row * tileNS::HEIGHT));
					berry[berryCounter].draw();
					berryCounter++;

				}

				if (tileNS::mapDesignTut[row][col] == 5) //if bubble waffle
				{
					bubble[bubbleCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					bubble[bubbleCounter].setY((float)(row * tileNS::HEIGHT));
					bubble[bubbleCounter].draw();
					bubbleCounter++;

				}

				if (tileNS::mapDesignTut[row][col] == 6) //if jumpHigh waffle
				{
					jumpHigh[jumpHighCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					jumpHigh[jumpHighCounter].setY((float)(row * tileNS::HEIGHT));
					jumpHigh[jumpHighCounter].draw();
					jumpHighCounter++;

				}

				if (tileNS::mapDesignTut[row][col] == 7) //if strength waffle
				{
					strength[strengthCounter].setX((float)(col * tileNS::WIDTH) - hOffset);
					strength[strengthCounter].setY((float)(row * tileNS::HEIGHT));
					strength[strengthCounter].draw();
					strengthCounter++;
				}

				if (tileNS::mapDesignTut[row][col] == 8) //if breakable tile
				{
					breakable.setX((float)(col * tileNS::WIDTH) - hOffset);
					breakable.setY((float)(row * tileNS::HEIGHT));
					breakable.draw();
				}

				if (tileNS::mapDesignTut[row][col] == 100) //if portal tile
				{
					portal.setX((float)(col * tileNS::WIDTH) - hOffset);
					portal.setY((float)(row * tileNS::HEIGHT));
					portal.draw();
				}
			}
		}
	}
//=============================================================================
// End Of Draw tiles, waffles etc
//=============================================================================



	//test.draw();
	cake.draw();
	sw.draw();
	activation.draw();

	if (menuOn)
	{
		//PlaySound("sound\\backGround.wav", NULL, SND_ASYNC);

		menuStart.setX((menu.getCenterX()) - (menuStart.getWidth()) / 2);
		menuStart.setY(menu.getCenterY() - (menuStart.getHeight()) / 2);

		menuCredits.setX((menu.getCenterX()) - (menuCredits.getWidth()) * 1.5);
		menuCredits.setY((menuStart.getY() + (menuCredits.getHeight())));

		menuExit.setX((menu.getCenterX()) + (menuExit.getWidth()) / 2);
		menuExit.setY((menuStart.getY() + (menuExit.getHeight())));

		menu.draw();
		menuStart.draw();
		menuCredits.draw();
		menuExit.draw();

		paused = false;

		if (((input->getMouseX() < menuStart.getX()) || (input->getMouseX() > (menuStart.getX() + menuStart.getWidth())))
			|| ((input->getMouseY() < menuStart.getY()) || (input->getMouseY() > (menuStart.getY() + menuStart.getHeight()))))
		{
			menuStart.setCurrentFrame(0);
		}

		if (((input->getMouseX() < menuStart.getX()) || (input->getMouseX() > (menuCredits.getX() + menuCredits.getWidth())))
			|| ((input->getMouseY() < menuCredits.getY()) || (input->getMouseY() > (menuCredits.getY() + menuCredits.getHeight()))))
		{
			menuCredits.setCurrentFrame(0);
		}

		if (((input->getMouseX() < menuExit.getX()) || (input->getMouseX() > (menuExit.getX() + menuExit.getWidth())))
			|| ((input->getMouseY() < menuExit.getY()) || (input->getMouseY() > (menuExit.getY() + menuExit.getHeight()))))
		{
			menuExit.setCurrentFrame(0);
		}


		if (((input->getMouseX() >= menuStart.getX()) && (input->getMouseX() <= (menuStart.getX() + menuStart.getWidth())))
			&& ((input->getMouseY() >= menuStart.getY()) && (input->getMouseY() <= (menuStart.getY() + menuStart.getHeight()))))
		{
			menuStart.setCurrentFrame(1);
			if (input->getMouseLButton() == true)
			{
				menuOn = false;
			}
		}

		if (((input->getMouseX() >= menuCredits.getX()) && (input->getMouseX() <= (menuCredits.getX() + menuCredits.getWidth())))
			&& ((input->getMouseY() >= menuCredits.getY()) && (input->getMouseY() <= (menuCredits.getY() + menuCredits.getHeight()))))
		{
			menuCredits.setCurrentFrame(1);
			if (input->getMouseLButton() == true)
			{
				creditsOn = true;
				//menuOn = false;

				if (input->wasKeyPressed(ESC_KEY))
				{
					//menuOn = true;
					creditsOn = false;
				}
			}
		}

		if (((input->getMouseX() >= menuExit.getX()) && (input->getMouseX() <= (menuExit.getX() + menuExit.getWidth())))
			&& ((input->getMouseY() >= menuExit.getY()) && (input->getMouseY() <= (menuExit.getY() + menuExit.getHeight()))))
		{
			menuExit.setCurrentFrame(1);
			if (input->getMouseLButton() == true)
				PostQuitMessage(0);
		}
	}
	if (creditsOn == true)
	{
		background.draw();
		gameFont.print("Credits", 0, 0);
		gameFont.print("Buttons - http://opengameart.org/content/free-game-gui", 0, GAME_HEIGHT / 2);
		gameFont.print("Boxy Bold Font - http://opengameart.org/content/boxy-bold-truetype-font", 0, GAME_HEIGHT / 2 + 50);
		gameFont.print("Background - ", 0, GAME_HEIGHT / 2 + 100);
		gameFont.print("Press Escape to return to main menu", 0, GAME_HEIGHT / 2 + 200);
	}

//=============================================================================
// Draw PAUSE MENU
//=============================================================================
	if (paused == true && attentionOn == false)
	{
		//set the pause background location
		pauseUi.setX((GAME_WIDTH / 2) - (pauseUi.getWidth() / 2));
		pauseUi.setY((GAME_HEIGHT / 2) - (pauseUi.getHeight() / 2));

		//set the resume button location
		pauseUiresume.setX((pauseUi.getCenterX()) - (pauseUiresume.getWidth() / 2));
		pauseUiresume.setY(pauseUi.getCenterY() - (pauseUiresume.getHeight()*1.5));
		//pauseUiresume.setCurrentFrame(0);

		//set the restart button location
		pauseUirestart.setX((pauseUi.getCenterX()) - (pauseUirestart.getWidth() / 2));
		pauseUirestart.setY((pauseUiresume.getY() + (pauseUirestart.getHeight()*1.25)));

		//set the mainmenu button location
		pauseUiMainMenu.setX((pauseUi.getCenterX()) - (pauseUiMainMenu.getWidth() / 2));
		pauseUiMainMenu.setY((pauseUirestart.getY() + (pauseUiMainMenu.getHeight()*1.25)));

		pauseUi.draw();
		pauseUiresume.draw();
		pauseUirestart.draw();
		pauseUiMainMenu.draw();

		if (((input->getMouseX() < pauseUiresume.getX()) || (input->getMouseX() > (pauseUiresume.getX() + pauseUiresume.getWidth()))) 
			|| ((input->getMouseY() < pauseUiresume.getY())|| (input->getMouseY() > (pauseUiresume.getY() + pauseUiresume.getHeight()))))
		{
			pauseUiresume.setCurrentFrame(0);		
		}

		if (((input->getMouseX() < pauseUiresume.getX()) || (input->getMouseX() > (pauseUiresume.getX() + pauseUiresume.getWidth())))
			|| ((input->getMouseY() < pauseUiresume.getY()) || (input->getMouseY() > (pauseUiresume.getY() + pauseUiresume.getHeight()))))
		{
			pauseUirestart.setCurrentFrame(0);
		}

		if (((input->getMouseX() < pauseUiresume.getX()) || (input->getMouseX() > (pauseUiresume.getX() + pauseUiresume.getWidth())))
			|| ((input->getMouseY() < pauseUiresume.getY()) || (input->getMouseY() > (pauseUiresume.getY() + pauseUiresume.getHeight()))))
		{
			pauseUiMainMenu.setCurrentFrame(0);
		}
		gameFont.print("PAUSED", 0, 0);

		//if resume clicked
		if (((input->getMouseX() >= pauseUiresume.getX()) && (input->getMouseX() <= (pauseUiresume.getX() + pauseUiresume.getWidth())))
			&& ((input->getMouseY() >= pauseUiresume.getY()) && (input->getMouseY() <= (pauseUiresume.getY() + pauseUiresume.getHeight()))))
		{
			pauseUiresume.setCurrentFrame(1);
			//gameFont.print("HOVERED RESUME", 0, 0);

			if(input->getMouseLButton() == true)
			paused = false;
		}

		//if restart clicked
		if (/*(input->getMouseLButton() == true)
			&& */((input->getMouseX() >= pauseUirestart.getX()) && (input->getMouseX() < (pauseUirestart.getX() + pauseUirestart.getWidth())))
			&& ((input->getMouseY() >= pauseUirestart.getY()) && (input->getMouseY() < (pauseUirestart.getY() + pauseUirestart.getHeight()))))
		{
			pauseUirestart.setCurrentFrame(1);
			//gameFont.print("HOVERED RESTART", 0, 0);
			if (input->getMouseLButton() == true)
			{
				paused = false;
				restartGame();
			}

		}

		//if Main Menu clicked
		if (/*(input->getMouseLButton() == true)
			&& */((input->getMouseX() >= pauseUiMainMenu.getX()) && (input->getMouseX() < (pauseUiMainMenu.getX() + pauseUiMainMenu.getWidth())))
			&& ((input->getMouseY() >= pauseUiMainMenu.getY()) && (input->getMouseY() < (pauseUiMainMenu.getY() + pauseUiMainMenu.getHeight()))))
		{
			pauseUiMainMenu.setCurrentFrame(1);
			//gameFont.print("HOVERED MainMenu", 0, 0);
			if (input->getMouseLButton() == true)
			{
				//exitGame();
				menuOn = true;
				paused = false;
				restartGame();
				//insert Menu code here
			}
		}
	}
	else
	{
		//gameFont.print("RUNNING", 0, 0);
	}
//=============================================================================
// End Of PAUSE MENU
//=============================================================================

//=============================================================================
// Draw ATTENTION
//=============================================================================
	if (attentionOn== true && menuOn == false)
	{
		//set the attention background location
		attentionUi.setX((GAME_WIDTH / 2) - (attentionUi.getWidth() / 2));
		attentionUi.setY((GAME_HEIGHT / 2) - (attentionUi.getHeight() / 2));

		//set the restart button location
		pauseUirestart.setX(attentionUi.getCenterX() - pauseUirestart.getWidth()*1.25);
		pauseUirestart.setY(attentionUi.getY() + attentionUi.getHeight() - pauseUirestart.getHeight() * 2);

		//set the mainmenu button location
		pauseUiMainMenu.setX(pauseUirestart.getX() + pauseUiMainMenu.getWidth()*1.25);
		pauseUiMainMenu.setY(attentionUi.getY() + attentionUi.getHeight() - pauseUiMainMenu.getHeight() * 2);

		attentionUi.draw();
		pauseUirestart.draw();
		pauseUiMainMenu.draw();

		if (((input->getMouseX() < pauseUirestart.getX()) || (input->getMouseX() > (pauseUirestart.getX() + pauseUirestart.getWidth())))
			|| ((input->getMouseY() < pauseUirestart.getY()) || (input->getMouseY() > (pauseUirestart.getY() + pauseUirestart.getHeight()))))
		{
			pauseUirestart.setCurrentFrame(0);
		}

		if (((input->getMouseX() < pauseUiMainMenu.getX()) || (input->getMouseX() > (pauseUiMainMenu.getX() + pauseUiMainMenu.getWidth())))
			|| ((input->getMouseY() < pauseUiMainMenu.getY()) || (input->getMouseY() > (pauseUiMainMenu.getY() + pauseUiMainMenu.getHeight()))))
		{
			pauseUiMainMenu.setCurrentFrame(0);
		}


		//if restart clicked
		if (/*(input->getMouseLButton() == true)
			&& */((input->getMouseX() > pauseUirestart.getX()) && (input->getMouseX() < (pauseUirestart.getX() + pauseUirestart.getWidth())))
			&& ((input->getMouseY() > pauseUirestart.getY()) && (input->getMouseY() < (pauseUirestart.getY() + pauseUirestart.getHeight()))))
		{
			pauseUirestart.setCurrentFrame(1);
			//gameFont.print("HOVERED RESTART", 0, 0);
			if (input->getMouseLButton() == true)
			{
				paused = false;
				attentionOn = false;
				restartGame();
			}

		}

		//if Main Menu clicked
		if (/*(input->getMouseLButton() == true)
			&& */((input->getMouseX() > pauseUiMainMenu.getX()) && (input->getMouseX() < (pauseUiMainMenu.getX() + pauseUiMainMenu.getWidth())))
			&& ((input->getMouseY() > pauseUiMainMenu.getY()) && (input->getMouseY() < (pauseUiMainMenu.getY() + pauseUiMainMenu.getHeight()))))
		{
			pauseUiMainMenu.setCurrentFrame(1);
			//gameFont.print("HOVERED MainMenu", 0, 0);
			if (input->getMouseLButton() == true)
			{
				//exitGame();
				menuOn = true;
				paused = false;
				restartGame();
				//insert Menu code here
				menuOn = true;
				attentionOn = false;
			}
		}

	}
//============================================================================
// END Draw ATTENTION
//=============================================================================
	if (berryAct == true)
	{
		for (int i = 0; i < 3; i++)
		{
			bulletMax[i].draw();
		}
	}

	graphics->spriteEnd();              // end drawing sprites
}

//=======================================================================================================================================================================================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=======================================================================================================================================================================================================================================
void Waffelo::releaseAll()
{
    backgroundTexture.onLostDevice();
    cakeTexture.onLostDevice();

	berryTexture.onLostDevice();
	bubbleTexture.onLostDevice();
	jumpHighTexture.onLostDevice();
	shrinkTexture.onLostDevice();
	strengthTexture.onLostDevice();
	bulletTexture.onLostDevice();
	breakableTexture.onLostDevice();

	pauseUiTexture.onLostDevice();
	pauseUiresumeTexture.onLostDevice();
	pauseUirestartTexture.onLostDevice();
	pauseUiMainMenuTexture.onLostDevice();
	attentionUiTexture.onLostDevice();

	TileTexture.onLostDevice();

	portalTexture.onLostDevice();
    Game::releaseAll();
    return;
}

//=======================================================================================================================================================================================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=======================================================================================================================================================================================================================================
void Waffelo::resetAll()
{
    cakeTexture.onResetDevice();
    backgroundTexture.onResetDevice();

	berryTexture.onResetDevice();
	bubbleTexture.onResetDevice();
	jumpHighTexture.onResetDevice();
	shrinkTexture.onResetDevice();
	strengthTexture.onResetDevice();
	bulletTexture.onResetDevice();
	breakableTexture.onResetDevice();

	pauseUiTexture.onResetDevice();
	pauseUiresumeTexture.onResetDevice();
	pauseUirestartTexture.onResetDevice();
	pauseUiMainMenuTexture.onResetDevice();
	attentionUiTexture.onResetDevice();

	TileTexture.onResetDevice();

	portalTexture.onResetDevice();
    Game::resetAll();
    return;
}

void Waffelo::deactivateAll()
{
	shrinkAct = false;
	bubbleAct = false;
	berryAct = false;
	jumpHighAct = false;
	strengthAct = false;
	rocketAct = false;
}

void Waffelo::restartGame()
{
	deactivateAll();
	cake.setX(0);
	cake.setY(0);
	hOffset = 0;
	cake.setScale(1);
	for (int i = 0; i < 2; i++)
	{
		shrink[i].setScale(1);
	}

	for (int i = 0; i < 2; i++)
	{
		bubble[i].setScale(1);
	}
	
	for (int i = 0; i < 2; i++)
	{
		berry[i].setScale(1);
	}
		
	for (int i = 0; i < 2; i++)
	{
		jumpHigh[i].setScale(1);
	}
			
	for (int i = 0; i < 2; i++)
	{
		strength[i].setScale(1);
	}

	breakable.setScale(1);
	attentionOn = false;
	cake.setHealth(300);
}