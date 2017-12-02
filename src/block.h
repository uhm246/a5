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
public:
  void toggleHeavy();
  Block(); // initialize the observed cells in constructor
           // I need to refer back to my grid implementation
};

class Block_I : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } } };
	Rotation rotation = 0;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_J : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 0, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 2 } },
	{ { 0, 1 },{ 1, 1 },{ 2, 1 },{ 2, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 1, 2 } } };
	Rotation rotation = 0;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_L : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 2, 0 },{ 2, 1 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 2 },{ 1, 2 },{ 1, 1 },{ 1, 0 } } };
	Rotation rotation = 0;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_S : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 0, 2 },{ 1, 1 },{ 1, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 0, 2 },{ 1, 1 },{ 1, 0 } } };
	Rotation rotation = 0;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_Z : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 1 },{ 1, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 1 },{ 1, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } } };
	Rotation rotation = 0;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_T : public Block{
	vector<vector<vector<int>>> coords = { { { 0, 1 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 1 },{ 1, 0 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 1, 1 } } };
	Rotation rotation = 0;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_O : public Block{
	// Coords for Block_O are the same for each rotation
	vector<vector<vector<int>>> coords = { { { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } } };
	Rotation rotation = 0;
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

#endif