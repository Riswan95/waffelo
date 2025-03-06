// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 Cake.cpp v1.0

#include "bubble.h"

//=============================================================================
// default constructor
//=============================================================================
Bubble::Bubble() : WaffleCollectible()
{
	spriteData.width = waffleCollectibleNS::WIDTH;           // size of cake1
	spriteData.height = waffleCollectibleNS::HEIGHT;
	spriteData.x = 200;                   // location on screen
	spriteData.y = 450;
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
bool Bubble::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the cake
//=============================================================================
void Bubble::draw()
{
	Image::draw();              // draw cake
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Bubble::update(float frameTime)
{
	Entity::update(frameTime);
}

