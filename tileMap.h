//#ifndef _tileMap_H                 // Prevent multiple definitions if this 
//#define _TILEMAP_H                 // file is included in more than one place
//#define WIN32_LEAN_AND_MEAN
//
//#include "constants.h"
//
//#include "tile.h";
//#include "textureManager.h"
//#include "image.h"
//#include <vector>
//
//namespace tileMapNS
//{
//	const int MAP_WIDTH = 5;
//	const int MAP_HEIGHT = 5;
//	int map[tileMapNS::MAP_WIDTH][tileMapNS::MAP_HEIGHT] =
//	{
//		{ 0, 0, 0, 0, 0 },
//		{ 0, 0, 0, 0, 0 },
//		{ 0, 0, 0, 0, 0 },
//		{ 0, 0, 0, 0, 0 },
//		{ 1, 1, 1, 1, 1 }
//	};
//	
//	
//	const int TileHEIGHT = 96;
//	const int TileWIDTH = 96;
//	const int TileTEXTURE_COLS = 0;
//}
//
//class TileMap : public Entity
//{
//private:
//	TextureManager tileTexture;
//	Image tile;
//	std::vector<Tile> tileVector;
//
//public:
//	// constructor
//	TileMap();
//	void createMap();
//	void checkTile();
//	void draw();
//};
//
//#endif