#include "AI.h"
AI::AI()
{
	copyTilemap();
	convertTilemap();
}

void AI::copyTilemap()
{
	for (int i = 0; i < tileNS::MAP_HEIGHT; i++)
	{
		for (int j = 0; j < tileNS::MAP_WIDTH; j++)
		{
			if (tileNS::mapDesignTut[i][j] == 1 || tileNS::mapDesignTut[i][j] == 2)
			{
				tileMap[i][j] = tileNS::mapDesignTut[i][j];
			}
			else
			{
				tileMap[i][j] = 0;
			}
		}
	}
}

void AI::convertTilemap()
{
	//0 is empty, 1 is normal tiles, 2 is water tile, 3 is left edge, 4 is right edge, 5 is freestanding
	for (int y = 0; y < tileNS::MAP_HEIGHT; y++)
	{
		for (int x = 0; x < tileNS::MAP_WIDTH; x++)
		{
			if (tileMap[y][x] == 1 && tileMap[y-1][x] == 0)
			{
				if ((tileMap[y][x - 1] == 0 || tileMap[y][x + 1] == 2) && tileMap[y][x + 1] == 1) //check if left is empty and right tile
				{
					tileMap[y][x] = 3; //left tile
				}

				if (tileMap[y][x - 1] == 1 && (tileMap[y][x + 1] == 0 || tileMap[y][x + 1] == 2)) //check if left is tile and right is empty
				{
					tileMap[y][x] = 4; //right tile
				}
				if (tileMap[y][x - 1] == 0 && tileMap[y][x + 1] == 0)
				{
					tileMap[y][x] = 5; // freestanding
				}
			}
		}
	}
}

int AI::getTile(int x, int y)
{
	return tileMap[x][y];
}

AI::~AI()
{
}
