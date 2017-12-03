#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include "cell.h"

/* 
	Note that for each Block's coords, the values are in respect to the bottom left cell
	of each Block
*/

// abstract class
class Block : public Observer<Info, State>{
	bool heavy = false;
	int level = 0;
public:
	int rotation = 0;
	void toggleHeavy();
	Block* clockwise(Block *b);
	Block* counterclockwise(Block *b);
	vector<vector<int>> getCoords(vector<int>);
	Block(); // initialize the observed cells in constructor
			 // I need to refer back to my grid implementation
};

class Block_single : public Block {
	vector<int> coords = { { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } } };
	
	const Colour colour = Brown;
public:
	void notify(Subject<Info, State> &whoFrom) override;
};

class Block_I : public Block{ 
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } } };
	
	const Colour colour = LBlue;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_J : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 0, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 2 } },
	{ { 0, 1 },{ 1, 1 },{ 2, 1 },{ 2, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 1, 2 } } };
	
	const Colour colour = DBlue;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_L : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 2, 1 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 2 },{ 1, 2 },{ 1, 1 },{ 1, 0 } } };
	
	const Colour colour = Orange;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_S : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 0, 2 },{ 1, 1 },{ 1, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 0, 2 },{ 1, 1 },{ 1, 0 } } };
	
	const Colour colour = Green;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_Z : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 1 },{ 1, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 1 },{ 1, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } } };
	
	const Colour colour = Red;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_T : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 1 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 1, 0 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 1, 1 } } };
	
	const Colour colour = Purple;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_O : public Block{
	// Coords for Block_O are the same for each rotation
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } } };
	
	const Colour colour = Yellow;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

#endif