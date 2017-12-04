#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include "observer.h"
#include "state.h"
#include "cell.h"

/* 
	Note that for each Block's coords, the values are in respect to the bottom left cell
	of each Block
*/

class Block{
	bool heavy = false;
	int level = 0;
	std::vector<Cell> cells;
protected:
	Type type;
	std::vector<std::vector<std::vector<int>>> coords;
public:
	int rotation = 0; 
	void toggleHeavy();
	int getLevel();
	int getSize();
	Type getType();
	void initCells(size_t r, size_t c);
	void removeCell(size_t r, size_t c);
	void remapCell(size_t r1, size_t c1, size_t r2, size_t c2);
	int cellCount();
	Block* clockwise(Block *b);
	Block* counterclockwise(Block *b);
	std::vector<std::vector<int>> getCoords(size_t r, size_t c);
	std::vector<std::vector<int>> getRotatedCoords(size_t r, size_t c, Rotate rot);
	Block(); // initialize the observed cells in constructor
			 // I need to refer back to my grid implementation
};

class Block_Single : public Block{
public:
	Block_Single();
};

class Block_I : public Block{ 
public:
	Block_I();
};

class Block_J : public Block{
public:
	Block_J();
};

class Block_L : public Block{
public:
	Block_L();
};

class Block_S : public Block{
public:
	Block_S();
};

class Block_Z : public Block{
public:
	Block_Z();
};

class Block_T : public Block{
public:
	Block_T();
};

class Block_O : public Block{
public:
	Block_O();
};

#endif
