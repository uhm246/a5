#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "grid.h"
#include "observer.h"
#include "textdisplay.h"
#include "subject.h"
#include "window.h"
#include "graphicsdisplay.h"
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
			game.scriptfile = argv[2];
		} else if (argv[1] == "-startlevel"){
			game.level = argv[2];
		}
	} else if (argc > 0){
		if (argv[1] == "-text"){
			game.mode = "text"; //text only 
		}
	}
    // lef, ri, do, cl, co, dr, levelu, leveld, n, ra, 
    // se, re, ri, do, cl, co, dr, ra
    // I, J, L, Z, T, O, S, n
    // switch for the single letter and double letter cmds
    // then check individual lef, levelu, leveld.
	try {
		while(true){
			cin >> cmd;
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
				switch(cmd[0]){
				case 'I': command.type = "I";
				case 'J': command.type = "J";
				case 'L': command.type = "L";
				case 'Z': command.type = "Z";
				case 'T': command.type = "T";
				case 'O': command.type = "O";
				case 'S': command.type = "S";
				case 'n':
					if (highLevel){
							rep = 1;
							command.type = "n";
							string file;
							cin >> file;
							command.file = file;
						}
				case 'h':
					rep = 1;
					command.type = "h";
			} else if (cmd.length() > 1){
				switch(cmd.substr(0,2)){
					case 'se': command.type = "se";
					case 're':
						rep = 1; 
						command.type = "re";
					case 'ri': 
						command.type = "ri";
						gravity = true;
					case 'do': command.type = "do";
					case 'cl': 
						command.type = "cw";
						gravity = true;
					case 'co': 
						command.type = "ccw";
						gravity = true;
					case 'dr': 
						command.type = "dr";
					case 'ra':
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