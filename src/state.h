#ifndef STATE_H
#define STATE_H
#include <cstdlib>

enum class Colour { LBlue, DBlue, Orange, Green, Red, Purple, Yellow, Brown };
enum class Fill { Empty, Temp, Solid, Hint };
enum class Move { Down, Left, Right };
enum class Rotate { Clockwise, Counterclockwise };
enum class Type { I, J, L, S, Z, T, O, Single, None };
enum class BlockType { Current, Next };

struct State {
  size_t r;
  size_t c;
  Fill status;
  Type type;
  BlockType blocktype;
};

#endif
