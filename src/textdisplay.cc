#include <iostream>
#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(int level, int score, int hiScore): 
level(level), score(score), hiscore(hiScore) {
	theDisplay.emplace_back("Level:    ");
	theDisplay.emplace_back(std::to_string(level));
	theDisplay.emplace_back("Score:    ");
	theDisplay.emplace_back(std::to_string(score));
	theDisplay.emplace_back("Hi Score:    ");
	theDisplay.emplace_back(std::to_string(hiScore));
	theDisplay.emplace_back("-----------");
	// Creates space for main gameplay
	for (int j = 0; j < (gridHeight * gridWidth); j++) {
		theDisplay.emplace_back(" ");
	}
	theDisplay.emplace_back("-----------");
	theDisplay.emplace_back("Next:");
	// Creates space for next block
	for (int j = 0; j < (2 * gridWidth); j++) { // 4 or 11 for gridWidth
		theDisplay.emplace_back(" ");
	}
}

void TextDisplay::notify(Subject<State> &whoFrom) {
	// Update level, score, and hiscore
	theDisplay[1] = (std::to_string(level));
	theDisplay[3] = (std::to_string(score));
	theDisplay[5] = (std::to_string(hiscore));

	State s = whoFrom.getState();
	BlockType blocktype = s.blocktype;
	Type cellType = s.type;
	size_t col = s.c;
	size_t row = s.r;

	// Displaying blocks in the gameplay grid
	if (blocktype == BlockType::Current) {
		if (cellType == Type::I) {
			theDisplay[(row * gridWidth) + col + 7] = "I";
		}
		else if (cellType == Type::J) {
			theDisplay[(row * gridWidth) + col + 7] = "J";
		}
		else if (cellType == Type::L) {
			theDisplay[(row * gridWidth) + col + 7] = "L";
		}
		else if (cellType == Type::S) {
			theDisplay[(row * gridWidth) + col + 7] = "S";
		}
		else if (cellType == Type::Z) {
			theDisplay[(row * gridWidth) + col + 7] = "Z";
		}
		else if (cellType == Type::T) {
			theDisplay[(row * gridWidth) + col + 7] = "T";
		}
		else if (cellType == Type::O) {
			theDisplay[(row * gridWidth) + col + 7] = "O";
		}
		else if (cellType == Type::Single) {
			theDisplay[(row * gridWidth) + col + 7] = "B";
		}
		else {
			theDisplay[(row * gridWidth) + col + 7] = " ";
		}
	}

	// Displaying next block
	else {
		if (cellType == Type::I) { 
			theDisplay[(row * gridWidth) + col + 200] = "I";
		}
		else if (cellType == Type::J) {
			theDisplay[(row * gridWidth) + col + 200] = "J";
		}
		else if (cellType == Type::L) {
			theDisplay[(row * gridWidth) + col + 200] = "L";
		}
		else if (cellType == Type::S) {
			theDisplay[(row * gridWidth) + col + 200] = "S";
		}
		else if (cellType == Type::Z) {
			theDisplay[(row * gridWidth) + col + 200] = "Z";
		}
		else if (cellType == Type::T) {
			theDisplay[(row * gridWidth) + col + 200] = "T";
		}
		else {
			theDisplay[(row * gridWidth) + col + 200] = "O";
		}
	}
	
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
	out << td.theDisplay[0] << td.theDisplay[1] << endl;	// Prints level
	out << td.theDisplay[2] << td.theDisplay[3] << endl;	// Prints score
	out << td.theDisplay[4] << td.theDisplay[5] << endl;	// Prints hi score
	out << td.theDisplay[6] << endl;						// Prints line
	// Prints gameplay grid
	for (int j = 0; j < td.gridHeight; j++) {
		for (int k = 0; k < td.gridWidth; k++) {
			out << td.theDisplay[(j * td.gridWidth) + k + 7];
		}
		out << endl;
	}
	out << td.theDisplay[198] << endl;						// Prints line
	out << td.theDisplay[199] << endl;						// Prints next
	// Prints next block
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < td.gridWidth; k++) {
			out << td.theDisplay[(j * td.gridWidth) + k + 200];
		}
		out << endl;
	}
	return out;
}