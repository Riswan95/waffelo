// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 Cake.cpp v1.0

#include "strength.h"

//=============================================================================
// default constructor
//=============================================================================
Strength::Strength() : WaffleCollectible()
{
	spriteData.width = waffleCollectibleNS::WIDTH;           // size of cake1
	spriteData.height = waffleCollectibleNS::HEIGHT;
	spriteData.x = 50;                   // location on screen
	spriteData.y = 530;
	spriteData.rect.bottom = waffleCollectibleNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = waffleCollectibleNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = waffleCollectibleNS::WAFFLECOLLECTIBLE_ANIMATION_DELAY;
	startFrame = waffleCollectibleNS::WAFFLECOLLECTIBLE_START_FRAME;     // first frame of cake animation
	endFrame = waffleCollectibleNS::WAFFLECOLLECTIBLE_END_FRAME;     // last frame of cake animation
	currentFrame = startFrame;
	radius = waffleCollectibleNS::WIDTH / 2.0;
	mass = waffleCollectibleNS::MASS;
	collisionType = entityNS::CIRCLE;
}

//=============================================================================
// Initialize the Cake.
// Post: returns true if successful, false if failed
//=============================================================================
bool Strength::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the cake
//=============================================================================
void Strength::draw()
{
	Image::draw();              // draw cake
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Strength::update(float frameTime)
{
	Entity::update(frameTime);
}

