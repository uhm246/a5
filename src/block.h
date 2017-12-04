#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include "cell.h"

/* 
	Note that for each Block's coords, the values are in respect to the bottom left cell
	of each Block
*/

class Block : public Observer<State>{
	bool heavy = false;
	int level = 0;
	std::vector<Cell&> cells;
public:
	int rotation = 0; 
	void toggleHeavy();
	void initCells(size_t r, size_t c);
	void removeCell(size_t r, size_t c);
	void remapCell(size_t r1, size_t c1, size_t r2, size_t c2);
	int cellCount();
	Block* clockwise(Block *b);
	Block* counterclockwise(Block *b);
	std::vector<std::vector<int>> getCoords(std::vector<int> absCoord);
	std::vector<std::vector<int>> getRotatedCoords(std::vector<int> absCoord, Rotate r);
	Block(); // initialize the observed cells in constructor
			 // I need to refer back to my grid implementation
};

class Block_single : public Block {
	std::vector<int> coords = { { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } } };
	
	const Colour colour = Colour::Brown;
public:
	void notify(Subject<State> &whoFrom) override;
};

class Block_I : public Block{ 
	std::vector<std::vector<std::vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } } };
	
	const Colour colour = Colour::LBlue;
public:
  void notify(Subject<State> &whoFrom) override;
};

class Block_J : public Block{
	std::vector<std::vector<std::vector<int>>> coords = { { { 0, 0 },{ 0, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 2 } },
	{ { 0, 1 },{ 1, 1 },{ 2, 1 },{ 2, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 1, 2 } } };
	
	const Colour colour = Colour::DBlue;
public:
  void notify(Subject<State> &whoFrom) override;
};

class Block_L : public Block{
	std::vector<std::vector<std::vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 2, 1 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 2 },{ 1, 2 },{ 1, 1 },{ 1, 0 } } };
	
	const Colour colour = Colour::Orange;
public:
  void notify(Subject<State> &whoFrom) override;
};

class Block_S : public Block{
	std::vector<std::vector<std::vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 0, 2 },{ 1, 1 },{ 1, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 0, 2 },{ 1, 1 },{ 1, 0 } } };
	
	const Colour colour = Colour::Green;
public:
  void notify(Subject<State> &whoFrom) override;
};

class Block_Z : public Block{
	std::vector<std::vector<std::vector<int>>> coords = { { { 0, 1 },{ 1, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 1 },{ 1, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } } };
	
	const Colour colour = Colour::Red;
public:
  void notify(Subject<State> &whoFrom) override;
};

class Block_T : public Block{
	std::vector<std::vector<std::vector<int>>> coords = { { { 0, 1 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 1, 0 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 1, 1 } } };
	
	const Colour colour = Colour::Purple;
public:
  void notify(Subject<State> &whoFrom) override;
};

class Block_O : public Block{
	// Coords for Block_O are the same for each rotation
	std::vector<std::vector<std::vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } } };
	
	const Colour colour = Colour::Yellow;
public:
  void notify(Subject<State> &whoFrom) override;
};

#endif