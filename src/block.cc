#include "block.h"

void Block::initCells(size_t r, size_t c) {
	std::vector<std::vector<int>> newCoords = getCoords(r, c);
	for (int i = 0; i < 4; i++) {
		cells.emplace_back(Cell(newCoords[i][1], newCoords[i][0])); // May need to double check for off-by-1 errors
	}
}

void Block::removeCell(size_t r, size_t c) {
	for (int i = 0; i < 4; i++) {
		if (cells[i] == {c, r}) {
			cells.erase(cells.begin() + i);
		}
	}
}

void Block::remapCell(size_t r1, size_t c1, size_t r2, size_t c2) {
	for (int i = 0; i < 4; i++) {
		if (cells[i] == {c1, r1}) {
			cells[i] == {c2, r2};
		}
	}
}

int Block::cellCount() {
	return cells.size();
}

Block* Block::clockwise(Block *b) {
	b->rotation = (b->rotation + 1) % 4;
	return b;
}

Block* Block::counterclockwise(Block *b) {
	b->rotation = (b->rotation - 1) % 4;
	return b;
}

std::vector<std::vector<int>> Block::getCoords(size_t r, size_t c) {
	std::vector<std::vector<int>> newCoords = this->coords[this->rotation];
	for (int i = 0; i < 4; i++) {
		newCoords[i][0] += c;
		newCoords[i][1] += r;
	}
	return newCoords;
}

std::vector<std::vector<int>> Block::getRotatedCoords(size_t r, size_t c, Rotate rot) {
	std::vector<std::vector<int>> newCoords;
	int rotateIndex = this->rotation;
	if (rot == Counterclockwise) {
		rotateIndex = (rotateIndex + 1) % 4;
		newCoords = = this->coords[rotateIndex];
	}
	else {
		rotateIndex = (rotateIndex - 1) % 4;
		newCoords = = this->coords[rotateIndex];
	} 
	for (int i = 0; i < 4; i++) {
		newCoords[i][0] += c;
		newCoords[i][1] += r;
	}
	return newCoords;
}