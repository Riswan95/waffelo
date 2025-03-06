//// Programming 2D Games
// Copyright (c) 2011 by: tileNS
// Charles Kelly
// Chapter 6 Cake.cpp v1.0

#include "tile.h"

//=============================================================================
// default constructor
//=============================================================================
Tile::Tile() : Entity()
{
	spriteData.width = tileNS::WIDTH;           // size of cake1
	spriteData.height = tileNS::HEIGHT;
	//spriteData.x = tileNS::X;                   // location on screen
	//spriteData.y = tileNS::Y;
	spriteData.rect.bottom = tileNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = tileNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	//frameDelay = tileNS::CAKE_ANIMATION_DELAY;
	startFrame = tileNS::TILE_START_FRAME;     // first frame of cake animation
	endFrame = tileNS::TILE_END_FRAME;     // last frame of cake animation
	currentFrame = startFrame;
	radius = 48;//tileNS::WIDTH/2.0;
	collisionType = entityNS::BOX;
	edge.top = -spriteData.height / 2;
	edge.bottom = spriteData.height / 2;
	edge.left = -spriteData.width / 2;
	edge.right = spriteData.width / 2;

}

//=============================================================================
// Initialize the Cake.
// Post: returns true if successful, false if failed
//=============================================================================
bool Tile::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the cake
//=============================================================================
void Tile::draw()
{
	Image::draw();              // draw tile
}

void Tile::update(float frameTime)
{
	Entity::update(frameTime);
}