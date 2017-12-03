#include "block.h"

Block* Block::clockwise(Block *b) {
	b->rotation = (b->rotation + 1) % 4;
	return b;
}

Block* Block::counterclockwise(Block *b) {
	b->rotation = (b->rotation - 1) % 4;
	return b;
}

vector<vector<int>> Block::getCoords(vector<int> absCoord) {
	vector<vector<int>> newCoords = this->coords[this->rotation];
	for (int i = 0; i < 4; i++) {
		newCoords[i][0] += absCoord[0];
		newCoords[i][1] += absCoord[1];
	}
	return newCoords;
}