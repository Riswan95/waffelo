// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 game.h v1.0

#ifndef _PORTAL_H                 // Prevent multiple definitions if this 
#define _PORTAL_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

//=============================================================================
// This class is the core of all waffle collectibles
//=============================================================================
namespace portalNS
{
	const int WIDTH = 72;                   // image width
	const int HEIGHT = 72;                  // image height
	const int X = 0;   // location on screen
	const int Y = 0;
	//const float ROTATION_RATE = (float)PI/4; // radians per second
	const float SPEED = 100;                // 100 pixels per second
	const float MASS = 300.0f;              // mass
	const int   TEXTURE_COLS = 2;           // texture has 8 columns
	const int   PORTAL_START_FRAME = 0;      // CAKE1 starts at frame 0
	const int   PORTAL_END_FRAME = 1;        // CAKE1 animation frames 0,1,2,3
	const float PORTAL_ANIMATION_DELAY = 0.2f;    // time between frames
	//const bool loops = false;	// stops frame from looping
}


class Portal : public Entity
{
private:
	// waffle collectible items

public:
	// constructor
	Portal();


	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
};

#endif