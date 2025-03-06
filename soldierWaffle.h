#pragma once

#include "AI.h"
#include "textDX.h"

namespace waffleNS
{
	const int WIDTH = 96;                   // image width
	const int HEIGHT = 96;                  // image height
	const int X = 0;   // location on screen
	const int Y = 720-144;
	//const float ROTATION_RATE = (float)PI/4; // radians per second
	const float SPEED = 100;                // 100 pixels per second
	const float MASS = 1.0e14f;//300.0f;              // mass
	const int   TEXTURE_COLS = 2;           // texture has 8 columns
	const int   WAFFLE_START_FRAME = 0;      // CAKE1 starts at frame 0
	const int   WAFFLE_END_FRAME = 1;        // CAKE1 animation frames 0,1,2,3
	const float WAFFLE_ANIMATION_DELAY = 0.2f;    // time between frames
}
class SoldierWaffle : public Entity
{
private:
	float x;
	float y;
	int tileX;
	int tileY;
	AI a;
	int state;
	float timer;
	float playerX;
	float playerY;
public:
	// constructor
	SoldierWaffle();
	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	void update(float frameTime, float hOffset);
	void ai(float frameTime);
	bool collision(float frameTime, float pXvelocity, float pYvelocity);
	int getTileBelow();
	int getTileAhead();
	float getTileX();
	float getTileY();
	void setPlayerPos(float, float);
	float getPlayerDist();
	float getPlayerAngle();
};

