#include "Board.hpp"
#include <iostream>



int main()
{
  unsigned int row;
  unsigned int column;
  std::cout << "Please specify how many rows you want:";
  std::cin >> row;
  std::cout << "Please specify how many columns you want:";
  std::cin >> column;
  Board board{row, column};
  std::cout << board.get_current_board();
  return 0;
}
