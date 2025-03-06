// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 Cake.cpp v1.0

#include "portal.h"

//=============================================================================
// default constructor
//=============================================================================
Portal::Portal() : Entity()
{
	spriteData.width = portalNS::WIDTH;           // size of cake1
	spriteData.height = portalNS::HEIGHT;
	spriteData.x = portalNS::X;                   // location on screen
	spriteData.y = portalNS::Y;
	spriteData.rect.bottom = portalNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = portalNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = portalNS::PORTAL_ANIMATION_DELAY;
	startFrame = portalNS::PORTAL_START_FRAME;     // first frame of cake animation
	endFrame = portalNS::PORTAL_END_FRAME;     // last frame of cake animation
	currentFrame = startFrame;
	radius = portalNS::WIDTH / 2.0;
	mass = portalNS::MASS;
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
bool Portal::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the cake
//=============================================================================
void Portal::draw()
{
	Image::draw();              // draw cake
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Portal::update(float frameTime)
{
	Entity::update(frameTime);
}

