#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "grid.h"
#include "observer.h"
#include "textdisplay.h"
#include "subject.h"
//#include "window.h"
//#include "graphicsdisplay.h"
#include "command.h"
#include "state.h"

int main(int argc, char *argv[]){
	cin.exceptions(ios::eofbit|ios::failbit);
	string cmd;
	Grid game;
	game.init(); // initialize game
	if (argc > 1){
		if (argv[1] == "-seed"){
			game.seed = argv[2];
		} else if (argv[1] == "-scriptfile"){
			file = argv[2];
			string b;
  			ifstream file;
  			vector<string> seq;
  			while (file >> b){
    			seq.push_back(b);
    		}
  		} else if (argv[1] == "-startlevel"){
			int lev = argv[2];
			if (lev == 1){
				Level1 start;
				g.setLevel(start);
			} else if (lev == 2){
				Level3 start;
				g.setLevel(start);
			} else if (lev == 3){
				Level0 start;
				g.setLevel(start);
			} else if (lev == 4){
				Level0 start;
				g.setLevel(start);
			} else {
				Level0 start;
				g.setLevel(start);
			}
		}
	} else if (argc > 0){
		if (argv[1] == "-text"){
			game.textmode = true; //text only 
		}
	}
    // lef, ri, do, cl, co, dr, levelu, leveld, n, ra, 
    // se, re, ri, do, cl, co, dr, ra
    // I, J, L, Z, T, O, S, n
    // switch for the single letter and double letter cmds
    // then check individual lef, levelu, leveld.
	try {
		while(true){
			if (game.seq){
				while (game.seqind < seq.size()){
					cmd = seq[seqind];
					seqind += 1; 
				}
			} else {
				cin >> cmd;
			}
			int i = 0;
			int rep = 0;
			bool gravity = false;
			bool highLevel = false;
			if (game.getLevel().num >= 3){
				highLevel = true;
			}
			Command command;
			command.g = game;
			command.level = game.getLevel();
			while (isdigit(cmd[i])){
				rep = rep * 10 + cmd[i];
				i += 1;
			}
			cmd.erase(0, i);
			if (cmd.length() > 0){
				string check = cmd[0];
				if (check == "I") command.type = "I";
				if (check == "J") command.type = "J";
				if (check == "L") command.type = "L";
				if (check == "Z") command.type = "Z";
				if (check == "T") command.type = "T";
				if (check == "O") command.type = "O";
				if (check == "S") command.type = "S";
				if (check == "n") {
					if (highLevel){
							rep = 1;
							command.type = "n";
							string file;
							cin >> file;
							command.file = file;
						}
					}
				if (check == "h"){
					rep = 1; 
					command.type = "h";
				} 
			} else if (cmd.length() > 1){
				string check = cmd.substr(0, 2);
				if (check == "se") command.type = "se";
				if (check == "re"){
					rep = 1;
					command.type = "re";
				}
				if (check == "ri"){
					gravity = true;
					command.type = "re";
				}
				if (check == "do"){
					command.type = "do";
				}
				if (check == "cw"){
					gravity = true;
					command.type = "cw";
				}
				if (check == "co"){
					gravity = true;;
					command.type = "ccw";
				}
				if (check == "dr"){
					command.type = "dr";
				}
				if (check == "ra"){
					if (highLevel){
						rep = 1;
						command.type = "ra";
					}
				}
			} else if (cmd.length() > 2 && cmd.substr(0, 3) == lef){
				command.type = "lef";
			} else if (cmd.length() > 5){
				switch(cmd.substr(0, 6)){
					case 'levelu': command.type = "levelu";
					case 'leveld': command.type = "leveld";
				}
			} else {
				command.type = "none";
			}
			while (rep > 0){
				command.execute();
				rep -= 1;
			}
			if (gravity && highLevel){
				Command heavy;
				heavy.type = "down";
				heavy.execute();
			}
		}

	}
	catch (ios::failure &) {}  // Any I/O failure quits
}