#pragma once
#include "tile.h"

class AI
{
public:
	AI();
	void copyTilemap();
	void convertTilemap();
	int getTile(int, int);
	~AI();

private:
	int tileMap[tileNS::MAP_HEIGHT][tileNS::MAP_WIDTH];

};