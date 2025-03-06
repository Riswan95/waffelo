// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 Cake.cpp v1.0

#include "breakable.h"

//=============================================================================
// default constructor
//=============================================================================
Breakable::Breakable() : Entity()
{
	spriteData.width = breakableNS::WIDTH;           // size of cake1
	spriteData.height = breakableNS::HEIGHT;
	spriteData.x = breakableNS::X;                   // location on screen
	spriteData.y = breakableNS::Y;
	spriteData.rect.bottom = breakableNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = breakableNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = breakableNS::BREAKABLE_ANIMATION_DELAY;
	startFrame = breakableNS::BREAKABLE_START_FRAME;     // first frame of cake animation
	endFrame = breakableNS::BREAKABLE_END_FRAME;     // last frame of cake animation
	currentFrame = startFrame;
	radius = breakableNS::WIDTH / 2.0;
	mass = breakableNS::MASS;
	collisionType = entityNS::CIRCLE;

	edge.top = -spriteData.height / 2;
	edge.bottom = spriteData.height / 2;
	edge.left = -spriteData.width / 2;
	edge.right = spriteData.width / 2;
}

//=============================================================================
// Initialize the Cake.
// Post: returns true if successful, false if failed
//=============================================================================
bool Breakable::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the cake
//=============================================================================
void Breakable::draw()
{
	Image::draw();              // draw cake
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Breakable::update(float frameTime)
{
	Entity::update(frameTime);
}

