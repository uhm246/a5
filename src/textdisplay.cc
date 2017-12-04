#include <iostream>
#include "textdisplay.h"

TextDisplay::TextDisplay(int n) : gridSize{ n } {
	for (int i = 0; i < gridSize; ++i) {
		theDisplay.emplace_back(std::vector<char>(n));
	}
	for (int j = 0; j < gridSize; j++) {
		for (int k = 0; k < gridSize; k++) {
			theDisplay[j][k] = '-';
		}
	}
}

void TextDisplay::notify(Subject<State> &whoNotified) {
	
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
	out << "Level:     " << 
	for (int j = 0; j < td.gridSize; j++) {
		for (int k = 0; k < td.gridSize; k++) {
			out << td.theDisplay[j][k];
		}
		out << std::endl;
	}
	return out;
}