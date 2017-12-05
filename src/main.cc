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

string block2cmd(Block b){
  Type t = b.getType();
  switch(t){
    case Type::Single:
      return "Single";
    case Type::I:
      return "I";
    case Type::J:
      return "J";
    case Type::L:
      return "L";
    case Type::S:
      return "S";
    case Type::Z:
      return "Z";
    case Type::O:
      return "O";
    case Type::T:
      return "T";
    default:
      return "none";
  }
}

int main(int argc, char *argv[]){
	vector<string> seq;
	cin.exceptions(ios::eofbit|ios::failbit);
	string cmd;
	Grid game;
	TextDisplay* td = new TextDisplay(0,0,0);
	game.setTextDisplay(td);
	game.init(); // initialize game
	int argind = 1;
	while (argind < argc - 1){
		string argv1 = argv[argind];
		if (argv1 == "-seed"){
			string seed = argv[argind + 1];
			game.setSeed(stoi(seed));
			argind += 2;
		} else if (argv1 == "-scriptfile"){
			string filename;
			filename = argv[argind + 1];
			string b;
			argind += 2;
  			ifstream f(filename);
  			while (f >> b){
    			seq.push_back(b);
    		}

	  	} else if (argv1 == "-startlevel"){
	  		string l = argv[argind + 1];
			int lev = stoi(l);
			game.getLevel().setLevel(lev);
			argind += 2;
		}
	}
	if (argind < argc){
		string argv1 = argv[argind];
		if (argv1 == "-text"){
			game.setTextMode(true); //text only 
		}
		argind += 1;
	}
    // lef, ri, do, cl, co, dr, levelu, leveld, n, ra, 
    // se, re, ri, do, cl, co, dr, ra
    // I, J, L, Z, T, O, S, n
    // switch for the single letter and double letter cmds
    // then check individual lef, levelu, leveld.
  try {
    // Initialize Command class
    Command command;
    command.setGrid(&game); 
    Block b1 = game.getLevel().getBlock();
    Block b2 = game.getLevel().getBlock();
    command.init(b1, b2);
    command.block(block2cmd(b1));

    while(true){
      cmd = "";
      // Update Board
      cout << game;
      command.setType("none");

      // If sequence is on, then take blocks in from seq
      //   else take in from stdin
      if (game.getSeq()){
        int size = seq.size();
        if (game.getSeqInd() < size){
          cmd = seq[game.getSeqInd()];
          game.incrementSeqInd(); 
        }
      } else {
        cin >> cmd;
      }

      int i = 0;
      int rep = 1;
      bool gravity = false;
      bool highLevel = false;

      if (game.getLevel().num() >= 3){
        highLevel = true;
      }

      // Initialize rep if first char is digit
      if (isdigit(cmd[i])){
        rep = 0;
      }

      // Increment rep as needed
      while (isdigit(cmd[i])){
        int inc = cmd[i] - 48;
        rep = rep * 10 + inc;
        i += 1;
      }

      // First class of commands: 1 Letter
      if (cmd.length() > 0){
        //cout << ">0" << endl;
        string check = cmd.substr(i, 1);
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
              command.setType("norandom");
              string file;
              cin >> file;
              command.setFile(file);
            }
          }
        if (check == "h"){
          rep = 1; 
          command.setType("hint");
        } 
      } 
      
      if (cmd.length() > 1){
        //cout << ">1 i: " << i << endl;
        string check = cmd.substr(i, 2);
        cout << check << endl;
        if (check == "se") command.setType("seq");
        if (check == "re"){
          rep = 1;
          command.setType("restart");
        }
        if (check == "ri"){
          gravity = true;
          command.setType("right");
        }
        if (check == "do"){
          command.setType("down");
        }
        if (check == "cl"){
          gravity = true;
          command.setType("cw");
        }
        if (check == "co"){
          gravity = true;
          command.setType("ccw");
        }
        if (check == "dr"){
          command.setType("drop");
          command.execute();
          rep = 0;
          command.block(block2cmd(command.getCur()));
        }
        if (check == "ra"){
          if (highLevel){
            rep = 1;
            command.setType("random");
          }
        }
      } 

      if (cmd.length() > 2 && cmd.substr(i, 3) == "lef"){
        command.setType("left");
      } 
      

      if (cmd.length() > 5){
        if (cmd.substr(i, 6) == "levelu"){
          command.setType("levelup");
        } else if (cmd.substr(i, 6) == "leveld"){
          command.setType("leveldown");
        }
      }
      cout << rep << endl;
      while (rep > 0){
        cout << "EXEC" << endl;
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
