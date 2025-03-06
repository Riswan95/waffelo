// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 Waffelo.h v1.0


#ifndef _WAFFELO_H             // Prevent multiple definitions if this 
#define _WAFFELO_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <vector>

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "planet.h"
#include "cake.h"
#include "soldierWaffle.h"

#include "berry.h"
#include "bubble.h"
#include "jumpHigh.h"
#include "shrink.h"
#include "strength.h"

#include "bullet.h"

#include "breakable.h"

#include "portal.h"
#include <iostream>
//#include "tile.h"
#include "textDX.h"

#include <Windows.h>
#include <MMSystem.h>

//=============================================================================
// This class is the core of the game
//=============================================================================
class Waffelo : public Game
{
private:
    // game items
    TextureManager backgroundTexture;   // background texture
    TextureManager cakeTexture;    // cake idle texture
	TextureManager waffleCollectibleTexture;
	TextureManager TileTexture;
	TextureManager TileWaterTexture;
	TextureManager swTexture;
	TextDX gameFont;

	TextureManager activationTexture;
	TextureManager berryTexture;
	TextureManager bubbleTexture;
	TextureManager jumpHighTexture;
	TextureManager shrinkTexture;
	TextureManager strengthTexture;

	TextureManager bulletTexture;

	TextureManager breakableTexture;

	TextureManager menuTexture;
	//TextureManager menuSelectorTexture;
	//int menuPosition = 1;
	//Image menuSelector;
	TextureManager menuStartTexture;
	TextureManager menuCreditsTexture;
	TextureManager menuExitTexture;
	Image menu;
	Image menuStart;
	Image menuCredits;
	Image menuExit;

	TextureManager pauseUiTexture;
	TextureManager pauseUiresumeTexture;
	TextureManager pauseUirestartTexture;
	TextureManager pauseUiMainMenuTexture;
	TextureManager attentionUiTexture;
	Image pauseUi;
	Image pauseUiresume;
	Image pauseUirestart;
	Image pauseUiMainMenu;
	Image attentionUi;
	TextureManager healthTexture;
	TextureManager portalTexture;

	SoldierWaffle sw;
	Cake cake;           // Cake player
	Cake test;

	Tile tiles;
	Tile tilesWater;
	Tile testTile;

	//Image menuSelector;

	bool menuOn;
	bool attentionOn = false;

	// waffles
	Berry berry[2];
	Bubble bubble[2];
	JumpHigh jumpHigh[2];
	Shrink shrink[2];
	Strength strength[2];
	
	Breakable breakable;

	Portal portal;

	int bull = 0;
	
    Image   background;         // background image
	Image bubbleImage;

	UCHAR CAKE_RIGHT_KEY = VK_RIGHT;
	UCHAR CAKE_LEFT_KEY = VK_LEFT;
	UCHAR CAKE_UP_KEY = VK_UP;
	UCHAR CAKE_DOWN_KEY = VK_DOWN;
	UCHAR PAUSE_KEY = VK_ESCAPE;
	//float Xvelocity = 0.0f;
	VECTOR2 velocity = cake.getVelocity();
	VECTOR2 deltaV = cake.getDeltaV();
	//float Yvelocity = 0.0f;

	const float CAKE_SPEED = 100.0f;                // pixels per second
	float midpoint = GAME_WIDTH / 2;
	bool jump = false;
	float JumpForce = 300.0f;
	float gravity = 300.0f;
	float hOffset = 0;
	
	bool shrinkAct;
	bool bubbleAct = false;
	bool berryAct = false;
	bool jumpHighAct = false;
	bool strengthAct;
	bool rocketAct;

	Image health;

	bool flip;
	bool creditsOn;

	VECTOR2 tilesXY[tileNS::MAP_HEIGHT][tileNS::MAP_WIDTH];

	int WafflePos[2];
	Bullet bullet1, bullet2, bullet3;

	Bullet bulletMax[3];

	Image activation;

	VECTOR2 velocityBullet[3];

	bool testText = false;
	bool endText = false;
	int doubleJump = 2;
	int jumpCounter = 999;
	int levelNo = 0;
	bool level1 = false;
	bool level2 = false;
	bool tut = false;
	// VECTOR2 bulletMax[3];
	// bullet1.add;
	// bullet2.add;
	// bullet3.add;

	//float xtilepos[100];
	//float ytilepos[10];

	

public:
    // Constructor
    Waffelo();

    // Destructor
    virtual ~Waffelo();

    // Initialize the game
    void initialize(HWND hwnd);
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
	void deactivateAll();
	void restartGame();
};

#endif
