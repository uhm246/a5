#include "command.h"

void redraw(Grid* g, Block *b_cur, Block *b, size_t old_r, size_t old_c, size_t r, size_t c){
	g->voidBlock(*b_cur, old_r, old_c);
	b_cur = b;
	g->drawBlock(*b_cur, r, c);
}

void Command::execute(){
// I, J, L, Z, T, O, S, norandom, hint, seq, restart
// right, down, cw, ccw, drop, left, levelup, level down, random
	size_t old_r = r;
	size_t old_c = c;
	if (type == "I"){
			Block_I *b;
			b->initCells(14,0);
			old_r = r;
			old_c = c;
			r = 14;
			c = 0;
			redraw(g, b_cur, b, old_r, old_c, r, c);
	} else if (type == "J"){
		Block_J *b;
		b->initCells(13,0);
		r = 13;
		c = 0;
		redraw(g, b_cur, b, old_r, old_c, r, c);
	} else if (type == "L"){
		Block_L *b;
		b->initCells(13,0);
		old_r = r;
		old_c = c;
		r = 13;
		c = 0;
		redraw(g, b_cur, b, old_r, old_c, r, c);
	} else if (type == "Z"){
		Block_Z *b;
		b->initCells(13,0);
		old_r = r;
		old_c = c;
		r = 13;
		c = 0;
		redraw(g, b_cur, b, old_r, old_c, r, c);
	} else if (type == "T"){
		Block_T *b;
		b->initCells(13,0);
		old_r = r;
		old_c = c;
		r = 13;
		c = 0;
		redraw(g, b_cur, b, old_r, old_c, r, c);
	} else if (type == "O"){
		Block_O *b;
		b->initCells(13,0);
		old_r = r;
		old_c = c;
		r = 13;
		c = 0;
		redraw(g, b_cur, b, old_r, old_c, r, c);
	} else if (type == "S"){
		Block_S *b;
		b->initCells(13,0);
		old_r = r;
		old_c = c;
		r = 13;
		c = 0;
		redraw(g, b_cur, b, old_r, old_c, r, c);
	} else if (type == "norandom"){
		level->random = false;
	} else if (type == "hint"){

	} else if (type == "seq"){
		g->seq = true;
		g->seqind = 0;

	} else if (type == "restart"){
		g->init();
	} else if (type == "right"){
		if (g->verifyMove(*b_cur, Move::Right, r, c)){
			c += 1;
		} 
		redraw(g, b_cur, b_cur, old_r, old_c, r, c);
	} else if (type == "down"){
		if (g->verifyMove(*b_cur, Move::Down, r, c)){
				r -= 1;
			}
		redraw(g, b_cur, b_cur, old_r, old_c, r, c);
		
	} else if (type == "cw"){
		if (g->verifyRotate(*b_cur, Rotate::Clockwise, r, c)){
				Block* b = b_cur->clockwise(b_cur);
				redraw(g, b_cur, b, old_r, old_c, r, c);	
			}
	} else if (type == "ccw"){
		if (g->verifyRotate(*b_cur, Rotate::Counterclockwise, r, c)){
				Block* b = b_cur->counterclockwise(b_cur);
				redraw(g, b_cur, b_cur, old_r, old_c, r, c);
			}
		
	} else if (type == "drop"){
		while (g->verifyMove(*b_cur, Move::Down, r, c )){
				r -= 1;
			}
			g->setBlock(*b_cur, r, c);
			g->voidBlock(*b_cur, old_r, old_c);
			g->drawBlock(*b_cur, r, c);
			b_cur = b_next;
			Block next = level->getBlock();	
			b_next = &next;	
	} else if (type == "lef"){
		if (g->verifyMove(*b_cur, Move::Left, r, c)){
				c -= 1;
			}
		redraw(g, b_cur, b_cur, old_r, old_c, r, c);	
	} else if (type == "levelu"){
		switch(level->num){
				case(0):
				{
					Level1 l;
					g->setLevel(l);
					level = &l;
				}
				case(1):
				{
					Level2 l;
					g->setLevel(l);
					level = &l;
				}
				case(2):
				{
					Level3 l;
					g->setLevel(l);
					level = &l;
				}
				case(3):
				{
					Level4 l;
					g->setLevel(l);
					level = &l;
				}
				case(4):
				{
					Level4 l;
					g->setLevel(l);
					level = &l;
				}
			}		
	} else if (type == "leveld"){
		switch(level->num){
				case(1):
				{
					Level0 l;
					g->setLevel(l);
					level = &l;
				}
				case(2):
				{
					Level1 l;
					g->setLevel(l);
					level = &l;
				}
				case(3):
				{
					Level2* l;
					g->setLevel(*l);
					level = l;
				}
				case(4):
				{
					Level3 l;
					g->setLevel(l);
					level = &l;
				}
				case(0):
				{
					Level0 l;
					g->setLevel(l);
					level = &l;
				}
			}
	} else if (type == "ra"){
		level->random = true;
	} else if (type == "none"){

	}
}