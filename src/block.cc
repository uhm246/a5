#include "block.h"

using namespace std;

Block::Block(){

}

Block_Single::Block_Single(){
	type = Type::Single;
	coords =
	{ { { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 } },
	{ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 } },
	{ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 } },
	{ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 } } };
}

Block_I::Block_I(){
	type = Type::I;
	coords = 
	{ { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } } };
}

Block_J::Block_J(){
	type = Type::J;
	coords = 
	{ { { 0, 0 },{ 0, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 2 } },
	{ { 0, 1 },{ 1, 1 },{ 2, 1 },{ 2, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 1, 2 } } };
}

Block_L::Block_L(){
	type = Type::L;
	coords = 
	{ { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 2, 1 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 2 },{ 1, 2 },{ 1, 1 },{ 1, 0 } } };
}

Block_S::Block_S(){
	type = Type::S;
	coords = 
	{ { { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 0, 2 },{ 1, 1 },{ 1, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 0, 2 },{ 1, 1 },{ 1, 0 } } };
}


Block_Z::Block_Z(){
	type = Type::Z;
	coords = 
	{ { { 0, 1 },{ 1, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 1 },{ 1, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } } };
}

Block_T::Block_T(){
	type = Type::T;
	coords = 
	{ { { 0, 1 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 1, 0 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 1, 1 } } };
}

Block_O::Block_O(){
	type = Type::O;
	coords = 
	{ { { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } } };
}

int Block::getLevel(){
	return level;
}

void Block::setLevel(int l){
	level = l;
}

int Block::getSize(){
	return cells.size();
}

Type Block::getType(){
	return type;
}

void Block::initCells(size_t r, size_t c) {
	std::vector<std::vector<int>> newCoords = getCoords(r, c);
	for (int i = 0; i < 4; i++) {
		cells.emplace_back(Cell(newCoords[i][1], newCoords[i][0])); // May need to double check for off-by-1 errors
	}
}

void Block::removeCell(size_t r, size_t c) {
	for (int i = 0; i < cells.size(); i++) {
		if (cells[i].getCol() == c && cells[i].getRow() == r) {
			cells.erase(cells.begin() + i);
			return;
		}
	}
}

void Block::remapCell(size_t r1, size_t c1, size_t r2, size_t c2) {
	for (int i = 0; i < cells.size(); i++) {
		if (cells[i].getCol() == c1 && cells[i].getRow() == r1) {
			cells.erase(cells.begin() + i);
			cells.emplace_back(Cell(r2, c2));
			return;
		}
	}
}

int Block::cellCount() {
	return cells.size();
}

Block Block::clockwise(Block b) {
	b.rotation = (b.rotation + 1) % 4;
	return b;
}

Block Block::counterclockwise(Block b) {
	b.rotation = (b.rotation - 1) % 4;
	return b;
}

std::vector<std::vector<int>> Block::getCoords(size_t r, size_t c) {
	std::vector<std::vector<int>> newCoords = this->coords[this->rotation];
	for (int i = 0; i < 4; i++) {
		newCoords[i][0] += r;
		newCoords[i][1] += c;
	}
	return newCoords;
}

std::vector<std::vector<int>> Block::getRotatedCoords(size_t r, size_t c, Rotate rot) {
	std::vector<std::vector<int>> newCoords;
	int rotateIndex = this->rotation;
	if (rot == Rotate::Counterclockwise) {
		rotateIndex = (rotateIndex + 1) % 4;
		newCoords = this->coords[rotateIndex];
	}
	else {
		rotateIndex = ((rotateIndex - 1) + 4) % 4;
		newCoords = this->coords[rotateIndex];
	} 
	for (int i = 0; i < 4; i++) {
		newCoords[i][0] += r;
		newCoords[i][1] += c;
	}
	return newCoords;
}