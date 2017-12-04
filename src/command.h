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
	Level* level;
	Grid* g;
	Block* b_cur;
	Block* b_next;
	size_t r;
	size_t c;
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