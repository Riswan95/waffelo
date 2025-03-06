//#include "tileMap.h"
//
//
//TileMap::TileMap()
//{
//	tileVector.resize(30);
//}
//
//void TileMap::createMap()
//{
//	int n = 0;
//
//	for (int h = 0; h < 5; h++)
//	{
//		for (int w = 0; w < 5; w++)
//		{
//			if (tileMapNS::map[h][w] == 1)
//			{
//				
//				/*if (tileVector.size() == n)
//				{
//					tileVector.resize(n + 10);
//				}
//				tileVector[n] = Tile();
//				tileMapNS::map[h][w] = n; //set the tilemap to reference the 
//				n++;*/
//				
//			}
//		}
//	}
//}
//
//void TileMap::draw()
//{
//	/*for (int i = 0; i < tileVector.size(); i++)
//	{
//		tileVector[i].draw();
//	}*/
//}
//
//
////for (int row = 0; row< levelDesignNS::MAP_HEIGHT; row++)						// for each row of map
////{
////	tile.setY((float)(row * levelDesignNS::TEXTURE_SIZE));						// set tile Y
////	for (int col = 0; col < levelDesignNS::MAP_WIDTH; col++)					// for each column of map
////	{
////		// if spike is present
////		if (levelDesignNS::tileMap[row][col] == 1)
////		{
////			tile.setX((float)(col * levelDesignNS::TEXTURE_SIZE) + mapX);		// set tile X
////
////			// if spike on screen
////			if (tile.getX() > -levelDesignNS::TEXTURE_SIZE && tile.getX() < GAME_WIDTH)
////			{
////				// collision between spike and player - player disappears and spawn a new character at the starting point
////				if (tile.collidesWith(player, collisionVector))
////				{
////					player.setX(25);
////tile.draw();
////					player.setY(GAME_HEIGHT - 45);
////				}
////			}
////		}