#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "grid.h"
#include "observer.h"
#include "textdisplay.h"
#include "subject.h"
//#include "window.h"
//#include "graphicsdisplay.h"
#include "command.h"
#include "state.h"

using namespace std;

int main(int argc, char *argv[]){
	vector<string> seq;
	cin.exceptions(ios::eofbit|ios::failbit);
	string cmd;
	Grid game;
	TextDisplay* td = new TextDisplay(0,0,0);
	game.setTextDisplay(td);
	game.init(); // initialize game
	cout << game;
	if (argc > 2){
		string argv1 = argv[1];
		if (argv1 == "-seed"){
			string seed = argv[2];
			game.setSeed(stoi(seed));
		} else if (argv1 == "-scriptfile"){
			string filename;
			filename = argv[2];
			string b;
  		ifstream f(filename);
  		while (f >> b){
    		seq.push_back(b);
    	}
  	} else if (argv1 == "-startlevel"){
  		string l = argv[2];
			int lev = stoi(l);
			if (lev == 1){
				Level1 start;
				game.setLevel(start);
			} else if (lev == 2){
				Level3 start;
				game.setLevel(start);
			} else if (lev == 3){
				Level1 start;
				//Level0 start { "sequence" };
				game.setLevel(start);
			} else if (lev == 4){
				//Level0 start { ;
				Level1 start;
				game.setLevel(start);
			} else {
				//evel0 start;
				Level1 start;
				game.setLevel(start);
			}
		}
	} else if (argc > 1){
		string argv1 = argv[1];
		if (argv1 == "-text"){
			game.setTextMode(true); //text only 
		}
	}
    // lef, ri, do, cl, co, dr, levelu, leveld, n, ra, 
    // se, re, ri, do, cl, co, dr, ra
    // I, J, L, Z, T, O, S, n
    // switch for the single letter and double letter cmds
    // then check individual lef, levelu, leveld.
	try {
		while(true){
			cout << game;
			if (game.getSeq()){
				int size = seq.size();
				while (game.getSeqInd() < size){
					cmd = seq[game.getSeqInd()];
					game.incrementSeqInd(); 
				}
			} else {
				cin >> cmd;
			}
			int i = 0;
			int rep = 0;
			bool gravity = false;
			bool highLevel = false;
			if (game.getLevel().num() >= 3){
				highLevel = true;
			}
			Command command;
			command.setGrid(&game); 
			command.setLevel(&game.getLevel());
			while (isdigit(cmd[i])){
				rep = rep * 10 + cmd[i];
				i += 1;
			}
			cmd.erase(0, i);
			if (cmd.length() > 0){
				string check = cmd.substr(0,1);
				if (check == "I") command.setType("I"); 
				if (check == "J") command.setType("J");
				if (check == "L") command.setType("L");
				if (check == "Z") command.setType("Z");
				if (check == "T") command.setType("T");
				if (check == "O") command.setType("O");
				if (check == "S") command.setType("S");
				if (check == "n") {
					if (highLevel){
							rep = 1;
							command.setType("n");
							string file;
							cin >> file;
							command.setFile(file);
						}
					}
				if (check == "h"){
					rep = 1; 
					command.setType("h");
				} 
			} else if (cmd.length() > 1){
				string check = cmd.substr(0, 2);
				if (check == "se") command.setType("se");
				if (check == "re"){
					rep = 1;
					command.setType("re");
				}
				if (check == "ri"){
					gravity = true;
					command.setType("re");
				}
				if (check == "do"){
					command.setType("do");
				}
				if (check == "cw"){
					gravity = true;
					command.setType("cw");
				}
				if (check == "co"){
					gravity = true;;
					command.setType("ccw");
				}
				if (check == "dr"){
					command.setType("dr");
				}
				if (check == "ra"){
					if (highLevel){
						rep = 1;
						command.setType("ra");
					}
				}
			} else if (cmd.length() > 2 && cmd.substr(0, 3) == "lef"){
				command.setType("lef");
			} else if (cmd.length() > 5){
				if (cmd.substr(0, 6) == "levelu"){
					command.setType("levelu");
				} else if (cmd.substr(0, 6) == "leveld"){
					command.setType("leveld");
				}
			} else {
				command.setType("none");
			}
			while (rep > 0){
				command.execute();
				rep -= 1;
			}
			if (gravity && highLevel){
				Command heavy;
				heavy.setType("down");
				heavy.execute();
			}
		}

	}
	catch (ios::failure &) {}  // Any I/O failure quits
}