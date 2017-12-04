#include "command.h"

using namespace std;

void Command::init(Block b1, Block b2){
	b_cur = b1;
	b_next = b2;
}

void Command::setGrid(Grid *grid){
	g = grid;
}

void Command::setLevel(Level *l){
	level = l;
}

void Command::setType(string s){
	type = s;
}

void Command::setFile(string s){
	file = s;
}

void Command::execute(){
// I, J, L, Z, T, O, S, norandom, hint, seq, restart
// right, down, cw, ccw, drop, left, levelup, level down, random
	size_t old_r = r;
	size_t old_c = c;
	
	// Block spawn commands
	if (type == "I"){
		Block_I b;
		g->voidBlock(b_cur, r, c);
		this->b_cur = b;
		this->r = 14;
		this->c = 0;
		g->drawBlock(b_cur, r, c);
	} else if (type == "J"){
		Block_J b;
		g->voidBlock(b_cur, r, c);
		this->b_cur = b;
		this->r = 13;
		this->c = 0;
		g->drawBlock(b_cur, r, c);
	} else if (type == "L"){
		Block_L b;
		g->voidBlock(b_cur, r, c);
		this->b_cur = b;
		this->r = 13;
		this->c = 0;
		g->drawBlock(b_cur, r, c);
	} else if (type == "Z"){
		Block_Z b;
		g->voidBlock(b_cur, r, c);
		this->b_cur = b;
		this->r = 13;
		this->c = 0;
		g->drawBlock(b_cur, r, c);
	} else if (type == "T"){
		Block_T b;
		g->voidBlock(b_cur, r, c);
		this->b_cur = b;
		this->r = 13;
		this->c = 0;
		g->drawBlock(b_cur, r, c);
	} else if (type == "O"){
		Block_O b;
		g->voidBlock(b_cur, r, c);
		this->b_cur = b;
		this->r = 13;
		this->c = 0;
		g->drawBlock(b_cur, r, c);
	} else if (type == "S"){
		Block_S b;
		g->voidBlock(b_cur, r, c);
		this->b_cur = b;
		this->r = 13;
		this->c = 0;
		g->drawBlock(b_cur, r, c);

	} else if (type == "norandom"){
		level->setRandom(false);

	} else if (type == "hint"){

	} else if (type == "seq"){
		g->setSeq(true);
		g->setSeqInd(0);

	} else if (type == "restart"){
		g->init();

	} else if (type == "right"){
		cout << "START RIGHT " << endl;
		if (g->verifyMove(b_cur, Move::Right, r, c)){
			cout << "GO RIGHT" << endl;
			g->voidBlock(b_cur, r, c);
			c += 1;
			g->drawBlock(b_cur, r, c);
		} 
		cout << "END RIGHT" << endl;
	} else if (type == "down"){
		if (g->verifyMove(b_cur, Move::Down, r, c)){
				r -= 1;
			}
		//redraw(g, b_cur, b_cur, old_r, old_c, r, c);
		
	} else if (type == "cw"){
		if (g->verifyRotate(b_cur, Rotate::Clockwise, r, c)){
				//Block* b = b_cur.clockwise(b_cur);
				//redraw(g, b_cur, b, old_r, old_c, r, c);	
			}

	} else if (type == "ccw"){
		if (g->verifyRotate(b_cur, Rotate::Counterclockwise, r, c)){
				//Block* b = b_cur.counterclockwise(b_cur);
				//redraw(g, b_cur, b, old_r, old_c, r, c);
			}
		
	} else if (type == "drop"){
		while (g->verifyMove(b_cur, Move::Down, r, c )){
				r -= 1;
			}
			g->setBlock(b_cur, r, c);
			g->voidBlock(b_cur, old_r, old_c);
			g->drawBlock(b_cur, r, c);
			//b_cur = b_next;
			Block next = level->getBlock();	
			//b_next = &next;	

	} else if (type == "left"){
		if (g->verifyMove(b_cur, Move::Left, r, c)){
				c -= 1;
			}
		//redraw(g, b_cur, b_cur, old_r, old_c, r, c);	

	} else if (type == "levelup"){
		switch(level->num()){
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
					//Level4 l;
					Level1 l;
					g->setLevel(l);
					level = &l;
				}
				case(4):
				{
					//Level4 l;
					Level1 l;
					g->setLevel(l);
					level = &l;
				}
			}		

	} else if (type == "leveldown"){
		switch(level->num()){
				case(1):
				{
					Level0 l { "sequence" };
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
					Level2 l;
					g->setLevel(l);
					level = &l;
				}
				case(4):
				{
					Level3 l;
					g->setLevel(l);
					level = &l;
				}
				case(0):
				{
					Level0 l { "sequence" };
					g->setLevel(l);
					level = &l;
				}
			}

	} else if (type == "random"){
		level->setRandom(true);

	} else if (type == "none"){
		// None
	}
}