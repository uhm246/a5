#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "window.h"
class Cell;

class GraphicsDisplay: public Observer<State> {
	const int gridHeight = 540; // 18 * 30
	const int gridWidth = 330;	// 11 * 30
	const int winHeight = 780;	// (18 + 8) * 30
	const int winWidth = 330;
	Xwindow xw;

 public:
  GraphicsDisplay();

  void notify(Subject<State> &whoFrom) override;
};
#endif
