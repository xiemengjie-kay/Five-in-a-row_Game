/* 
This file contains the class Board that will be the model of the game.
By creating an Board class object, you can use the member functions of
Board to control the current game board such as dropping a piece, 
printing the current game board, etc..

Author: Mengjie Xie
*/



#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>


class Board
{
public:
  Board(unsigned int row, unsigned int column);

  ~Board() noexcept  = default;

  unsigned int get_row() const { return row;}

  unsigned int get_column() const { return column;};

  std::string get_current_board() const;

  void drop(unsigned int row, unsigned int column, const std::string& piece);
  
private:
  unsigned int row;
  unsigned int column;
  std::vector<std::vector<std::string>> board;

};



#endif
