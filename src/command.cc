#include "command.h"

void Command::execute(){
// I, J, L, Z, T, O, S, norandom, hint, seq, restart
// right, down, cw, ccw, drop, left, levelup, level down, random
	bool redraw = false;
	switch(type){
		case "I":
			Block_I *b;
			b->initCells(14,0);
			redraw = true;
			size_t old_r = r;
			size_t old_c = c;
			r = 14;
			c = 0;
		case "J":
			Block_J *b;
			b->initCells(13,0);
			redraw = true;
			r = 13;
			c = 0;
		case "L":
			Block_L *b;
			b->initCells(13,0);
			redraw = true;
			size_t old_r = r;
			size_t old_c = c;
			r = 13;
			c = 0;
		case "Z":
			Block_Z *b;
			b->initCells(13,0);
			redraw = true;
			size_t old_r = r;
			size_t old_c = c;
			r = 13;
			c = 0;
		case "T":
			Block_T *b;
			b->initCells(13,0);
			redraw = true;
			size_t old_r = r;
			size_t old_c = c;
			r = 13;
			c = 0;
		case "O":
			Block_O *b;
			b->initCells(13,0);
			redraw = true;
			size_t old_r = r;
			size_t old_c = c;
			r = 13;
			c = 0;
		case "S":
			Block_S *b;
			b->initCells(13,0);
			redraw = true;
			size_t old_r = r;
			size_t old_c = c;
			r = 13;
			c = 0;
		case "norandom":
			rand = false;
		case "hint":
		case "seq":

		case "restart":
			g->init();
		case "right":
			if (g->verifyMove(b_cur, r, c + 1)){
				c += 1;
			}
		case "down":
			if (g->verifyMove(b_cur, r - 1, c)){
				r -= 1;
			}
		case "cw":
			if (g->verifyRotate(b_cur, Clockwise, r, c)){
				b_cur = b_cur.clockwise();
			}
			redraw = true;
		case "ccw":
			if (g->verifyRotate(b_cur, Counterclockwise, r, c)){
				b_cur = b_cur.counterclockwise();
			}
			redraw = true;
		case "drop":
			while (g->verifyMove(b_cur, r, c )){
				r -= 1;
			}
			g->setBlock(b_cur, r, c);
			g->voidBlock(b_cur, old_r, old_c);
			g->drawBlock(b, r, c);
			b_cur = b_next;
			b_next = level.getBlock();
		case "lef":
			if (g->verifyMove(b_cur, r, c - 1)){
				c -= 1;
			}
			redraw = true;
		case "levelu":
			switch(level->num){
				case(0):
					Level1* l;
				case(1):
					Level2* l;
				case(2):
					Level3* l;
				case(3):
					Level4* l;
				case(4):
					Level4* l;
			}
			g.setLevel(l);
			level = l;
		case "leveld":
			switch(level->num){
				case(1):
					Level0* l;
				case(2):
					Level1* l;
				case(3):
					Level2* l;
				case(4):
					Level3* l;
				case(0):
					Level0* l;
			}
			g->setLevel(l);
			level = l;
		case "ra":
			rand = true;
		case "none":
	}
	if (redraw){
		g->voidBlock(b_cur, old_r, old_c);
		g->drawBlock(b, r, c);
	}
}