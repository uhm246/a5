#include <iostream>
#include "graphicsdisplay.h"
#include "info.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int level, int score, int hiScore): xw{winWidth, winHeight} {
  xw.fillRectangle(0, 0, winWidth, winHeight, Xwindow::Black); // Draws black background
  xw.drawString(5, 5, "Level:");
  xw.drawString(20, 5, to_string(level));
  xw.drawString(5, 35, "Score:");
  xw.drawString(20, 35, to_string(score));
  xw.drawString(5, 65, "Hi Score:");
  xw.drawString(20, 65, to_string(hiScore));
  xw.drawString(0, 75, "--------------------------------");
  xw.drawString(0, 690, "--------------------------------");
  xw.drawString(5, 715, "Next:");
}


void GraphicsDisplay::notify(Subject<State> &whoNotified, int level, int score, int hiScore) {
	// Update level, score, and hiscore
	xw.drawString(20, 5, to_string(level));
	xw.drawString(20, 35, to_string(score));
	xw.drawString(20, 65, to_string(hiScore));

	State s = whoNotified.getState();
	BlockType blocktype = s.blocktype;
	Type cellType = s.type;
	size_t col = s.c;
	size_t row = s.r;
	int cellSize = 30;
	switch (blocktype) {
	case BlockType::Current:
		switch (cellType) {
		case Type::I:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (4 * cellSize), cellSize, cellSize, Xwindow::DarkTurquoise);
			break;
		case Type::J:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (4 * cellSize), cellSize, cellSize, Xwindow::RoyalBlue);
			break;
		case Type::L:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (4 * cellSize), cellSize, cellSize, Xwindow::Orange);
			break;
		case Type::S:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (4 * cellSize), cellSize, cellSize, Xwindow::LimeGreen);
			break;
		case Type::Z:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (4 * cellSize), cellSize, cellSize, Xwindow::Red);
			break;
		case Type::T:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (4 * cellSize), cellSize, cellSize, Xwindow::DarkOrchid);
			break;
		case Type::O:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (4 * cellSize), cellSize, cellSize, Xwindow::Gold);
			break;
		case Type::B:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (4 * cellSize), cellSize, cellSize, Xwindow::Peru);
			break;
		default:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (4 * cellSize), cellSize, cellSize, Xwindow::Black);
		}
	case BlockType::Next:
		switch (cellType) {
		case Type::I:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (24 * cellSize), cellSize, cellSize, Xwindow::DarkTurquoise);
			break;
		case Type::J:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (24 * cellSize), cellSize, cellSize, Xwindow::RoyalBlue);
			break;
		case Type::L:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (24 * cellSize), cellSize, cellSize, Xwindow::Orange);
			break;
		case Type::S:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (24 * cellSize), cellSize, cellSize, Xwindow::LimeGreen);
			break;
		case Type::Z:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (24 * cellSize), cellSize, cellSize, Xwindow::Red);
			break;
		case Type::T:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (24 * cellSize), cellSize, cellSize, Xwindow::DarkOrchid);
			break;
		case Type::O:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (24 * cellSize), cellSize, cellSize, Xwindow::Gold);
			break;
		case Type::B:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (24 * cellSize), cellSize, cellSize, Xwindow::Peru);
			break;
		default:
			xw.fillRectangle(col * cellSize, (row * cellSize) + (24 * cellSize), cellSize, cellSize, Xwindow::Black);
		}
	}
}
