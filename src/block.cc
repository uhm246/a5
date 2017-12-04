#include "block.h"

void Block::removeCell(size_t r, size_t c) {

}

void Block::remapCell(size_t r1, size_t c1, size_t r2, size_t c2) {

}

int Block::cellCount() {

}

Block* Block::clockwise(Block *b) {
	b->rotation = (b->rotation + 1) % 4;
	return b;
}

Block* Block::counterclockwise(Block *b) {
	b->rotation = (b->rotation - 1) % 4;
	return b;
}

std::vector<std::vector<int>> Block::getCoords(std::vector<int> absCoord) {
	std::vector<std::vector<int>> newCoords = this->coords[this->rotation];
	for (int i = 0; i < 4; i++) {
		newCoords[i][0] += absCoord[0];
		newCoords[i][1] += absCoord[1];
	}
	return newCoords;
}

std::vector<std::vector<int>> Block::getRotatedCoords(std::vector<int> absCoord, Rotate r) {
	std::vector<std::vector<int>> newCoords;
	int rotateIndex = this->rotation;
	if (r == Counterclockwise) {
		rotateIndex = (rotateIndex + 1) % 4;
		newCoords = = this->coords[rotateIndex];
	}
	else {
		rotateIndex = (rotateIndex - 1) % 4;
		newCoords = = this->coords[rotateIndex];
	} 
	for (int i = 0; i < 4; i++) {
		newCoords[i][0] += absCoord[0];
		newCoords[i][1] += absCoord[1];
	}
	return newCoords;
}