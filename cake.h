// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 cake.h v1.0

#ifndef _cake_H                 // Prevent multiple definitions if this 
#define _CAKE_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "State.h"
#include "image.h"

namespace cakeNS
{
    const int WIDTH = 86;                   // image width
    const int HEIGHT = 96;                  // image height
	const int X = 0;   // location on screen
	const int Y = 0;
    //const float ROTATION_RATE = (float)PI/4; // radians per second
    const float SPEED = 100;                // 100 pixels per second
	const float MASS = 1.0e14f;//300.0f;              // mass
    const int   TEXTURE_COLS = 7;           // texture has 8 columns
    const int   CAKE_START_FRAME = 0;      // CAKE1 starts at frame 0
    const int   CAKE_END_FRAME = 6;        // CAKE1 animation frames 0,1,2,3
    const float CAKE_ANIMATION_DELAY = 0.2f;    // time between frames
	
	// bubble
	const int BUBBLE_START_FRAME = 6;
	//const int BUBBLE_END_FRAME = 8;
	const float BUBBLE_ANIMATION_DELAY = 0.1f;

	/*const int   MOVE_START_FRAME = 24;    // move start frame
	const int   MOVE_END_FRAME = 27;      // move end frame
	const float MOVE_ANIMATION_DELAY = 0.1f; // time between frames*/
}

// inherits from Entity class
class Cake : public Entity
{
private:
	
	UCHAR CAKE_RIGHT_KEY = VK_RIGHT;
	UCHAR CAKE_LEFT_KEY = VK_LEFT;
	UCHAR CAKE_UP_KEY = VK_UP;
	UCHAR CAKE_DOWN_KEY = VK_DOWN;

	Image	bubble;
	bool waffleBubble;
	//State* currentState;

public:
    // constructor
    Cake();
	virtual ~Cake() {}

    // inherited member functions
    virtual void draw();

	virtual bool  getBubble()  { return waffleBubble; }
	virtual void setBubble(bool v)   { waffleBubble = v; }

    virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
                            TextureManager *textureM);
    void update(float frameTime);
    void damage(WEAPON);
	//void changeSprite(int x, int y);
	//void changeState(const State* NewState);
	//void UpdateState(int ident);
	//void move(float frameTime, float midpoint, Image* background);
	void ActivatePower(bool *power);
	void DeactivatePower(bool *power);
	void setHeight(int h)  { spriteData.height = h; }
	void setWidth(int w)  { spriteData.width = w; }

};
#endif

