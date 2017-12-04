#include "command.h"

using namespace std;

void Command::init(Block b1, Block b2){
	b_cur = b1;
	b_next = b2;
}

void Command::setGrid(Grid *grid){
	g = grid;
}

void Command::setType(string s){
	type = s;
}

void Command::setFile(string s){
	file = s;
}

Block Command::getCur(){
	return b_cur;
}

void Command::execute(){
// I, J, L, Z, T, O, S, norandom, hint, seq, restart
// right, down, cw, ccw, drop, left, levelup, level down, random
	
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
	} 

	else if (type == "norandom"){
		g->getLevel().setRandom(false);

	} 

	else if (type == "hint"){

	} 

	else if (type == "seq"){
		g->setSeq(true);
		g->setSeqInd(0);

	} 

	else if (type == "restart"){
		g->init();
	} 

	else if (type == "right"){
		if (g->verifyMove(b_cur, Move::Right, r, c)){
			g->voidBlock(b_cur, r, c);
			c += 1;
			g->drawBlock(b_cur, r, c);
		} 
	} 

	else if (type == "left"){
		cout << "LEFT" << endl;
		if (g->verifyMove(b_cur, Move::Left, r, c)){
			g->voidBlock(b_cur, r, c);
			c -= 1;
			g->drawBlock(b_cur, r, c);
		} 
	} 

	else if (type == "down"){
		if (g->verifyMove(b_cur, Move::Down, r, c)){
			g->voidBlock(b_cur, r, c);
			r -= 1;
			g->drawBlock(b_cur, r, c);
		} 
	} 

	else if (type == "cw"){
		if (g->verifyRotate(b_cur, Rotate::Clockwise, r, c)){
			g->voidBlock(b_cur, r, c);
			b_cur = b_cur.clockwise(b_cur);
			g->drawBlock(b_cur, r, c);
		}
	} 

	else if (type == "ccw"){
		if (g->verifyRotate(b_cur, Rotate::Counterclockwise, r, c)){
			g->voidBlock(b_cur, r, c);
			b_cur = b_cur.clockwise(b_cur);
			g->drawBlock(b_cur, r, c);
		}
	} 

	else if (type == "drop"){
		size_t old_r = r;
		size_t old_c = c;
 		while (g->verifyMove(b_cur, Move::Down, r, c )){
			r -= 1;
		}
		g->voidBlock(b_cur, old_r, old_c);
		g->setBlock(b_cur, r, c);
		b_cur = b_next;
		b_next = g->getLevel().getBlock();
	} 

	else if (type == "levelup"){
		g->getLevel().increaseLevel();
	} 

	else if (type == "leveldown"){
		g->getLevel().decreaseLevel();
	} 

	else if (type == "random"){
		g->getLevel().setRandom(true);
	} 

	else if (type == "none"){
		// None
	}
}