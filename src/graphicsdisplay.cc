#include <iostream>
#include "graphicsdisplay.h"
#include "info.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int level, int score, int hiScore): xw{winWidth, winHeight} {
  xw.fillRectangle(0, 0, winWidth, winHeight, Xwindow::Black); // Draws black background
}


void GraphicsDisplay::notify(Subject<State> &whoNotified) {
	State s = whoNotified.getState();
	BlockType blocktype = s.blocktype;
	Type cellType = s.type;
	size_t col = s.c;
	size_t row = s.r;
	int cellSize = 30;
	switch(blocktype) {
	case BlockType::Current:
		switch (cellType) {
		case Type::I:
			xw.fillRectangle(col * cellSize, (row * cellSize), cellSize, cellSize, Xwindow::DarkTurquoise);
			break;
		}
		xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, Xwindow::Black);
		break;
	case Colour::White:
		xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::White);
		break;
	default:
		xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Blue);
  }
}
