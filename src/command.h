#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "level.h"
#include "grid.h"
#include "block.h"

class Command {
	Level* level = nullptr;
	Grid* g = nullptr;
	Block* b_cur = nullptr;
	Block* b_next = nullptr;
	size_t r = 0;
	size_t c = 0;
	std::string type;
	std::string file;
public:
	void setGrid(Grid* grid);
	void setLevel(Level* l);
	void setType(std::string s);
	void setFile(std::string s);
	void execute();
};

#endif