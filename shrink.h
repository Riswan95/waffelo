// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 game.h v1.0

#ifndef _SHRINK_H                 // Prevent multiple definitions if this 
#define _SHRINK_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "waffleCollectible.h"

//=============================================================================
// This class is the core of all waffle collectibles
//=============================================================================
//namespace shrinkNS
//{/*
//	const int WIDTH = 32;                   // image width
//	const int HEIGHT = 32;                  // image height
//	const int Y = 530;
//	//const float ROTATION_RATE = (float)PI/4; // radians per second
//	const float SPEED = 100;                // 100 pixels per second
//	const float MASS = 300.0f;              // mass
//	const int   TEXTURE_COLS = 4;           // texture has 8 columns
//	const int   SHRINK_START_FRAME = 0;      // CAKE1 starts at frame 0
//	const int   SHRINK_END_FRAME = 3;        // CAKE1 animation frames 0,1,2,3
//	const float SHRINK_ANIMATION_DELAY = 0.2f;    // time between frames*/
//	const int X = 500;
//}


class Shrink : public WaffleCollectible
{
private:
	// waffle collectible items

public:
	// constructor
	Shrink();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
};

#endif