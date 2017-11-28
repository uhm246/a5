#include <iostream>
#include "block.h"
#include "level.h"

using namespace std;

int main(){
  string s;
  Level0 l0;
  Level1 l1;
  Level2 l2;
  Level3 l3;
  Level4 l4;
  Block b;
  while (cin >> s) {
    if (s == "0"){
      b = l0.getBlock();
    } else if (s == "1"){
      b = l1.getBlock();
    } else if (s == "2"){
      b = l2.getBlock();
    } else if (s == "3"){
      b = l3.getBlock();
    } else if (s == "4"){
      b = l4.getBlock();
    }
    cout << b.getType() << endl;
  }
}
