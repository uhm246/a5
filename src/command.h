#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "info.h"

class Command {
	int max_level = 4;
	Level& level;
	Grid& g;
	Block& b_cur;
	Block& b_next;
	size_t r;
	size_t c;
	const std::string type;
	const std::string file;
	bool rand = true;
public:
	void execute();
}

#endif