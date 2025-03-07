// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 constants.h v1.0

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "Waffelo";
const char GAME_TITLE[] = "Waffelo";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH =  1280;               // width of game in pixels
const UINT GAME_HEIGHT = 720;               // height of game in pixels

// game
const double PI = 3.14159265;
const float FRAME_RATE = 200.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 6.67428e-11f;             // gravitational constant
const int background_scale = 2.0f;
const int background_width = (int)(640 * background_scale);
const int background_height = (int)(480 * background_scale);
const float SCALE_RATE = 0.5f;

// graphic images
const char BACKGROUND_IMAGE[] =   "pictures\\backgroundx.jpg";     // photo source NASA/courtesy of nasaimages.org 
const char CAKES_IMAGE[] = "pictures\\CAKES.png";  // game textures
//const char CAKES_IMAGE_MOVEMENT[] = "pictures\\CAKES_Movement.png";
const char SOLDIER_IMAGE[] = "pictures\\Waffleo.png";
const char TILE_IMAGE[] = "pictures\\Tile.png";
const char TILE_IMAGE_TEST[] = "pictures\\tileTest.png";
const char TILE_WATER_IMAGE[] = "pictures\\TileWater.png";

const char MENU_IMAGE[] = "pictures\\menu.png";     // menu texture
//const char MENUSELECTOR_IMAGE[] = "pictures\\bullet.png";	// menu selector texture
const char MENU_START_IMAGE[] = "pictures\\start.png";
const char MENU_CREDITS_IMAGE[] = "pictures\\credits.png";
const char MENU_EXIT_IMAGE[] = "pictures\\exit.png";

const char ACTIVATION_IMAGE[] = "pictures\\activation.png";
const char BERRY_IMAGE[] = "pictures\\berry.png";
const char BUBBLE_IMAGE[] = "pictures\\bubble.png";
const char JUMPHIGH_IMAGE[] = "pictures\\jumphigh.png";
const char SHRINK_IMAGE[] = "pictures\\shrink.png";
const char STRENGTH_IMAGE[] = "pictures\\strength.png";

const char BULLET_IMAGE[] = "pictures\\bullet.png";	// bullet texture

const char BREAKABLE_IMAGE[] = "pictures\\breakable.png";

const char PAUSE_UI_IMAGE[] = "pictures\\Pause Window.png";
const char PAUSE_RESUME_IMAGE[] = "pictures\\Resume Button.png";
const char PAUSE_RESTART_IMAGE[] = "pictures\\Restart Button.png";
const char PAUSE_MAINMENU_IMAGE[] = "pictures\\MainMenu Button.png";
//const char BULLET_IMAGE[] = "pictures\\bullet.png";	// bullet texture
const char ATTENTION_UI_IMAGE[] = "pictures\\Attention Window.png";
const char HEART_IMAGE[] = "pictures\\heart.png";

const char PORTAL_IMAGE[] = "pictures\\portal.png";

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY      = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY      = VK_MENU;         // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;       // Enter key
const UCHAR E_KEY = 'E';				// E key

const UCHAR UP_KEY = VK_UP;
const UCHAR DOWN_KEY = VK_DOWN;

// weapon types
enum WEAPON {TORPEDO, SHIP, PLANET};

#endif
