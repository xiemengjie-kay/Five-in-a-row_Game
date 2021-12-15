#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>


class Board
{
public:
  Board(unsigned int row, unsigned int column);

  ~Board() noexcept  = default;

  unsigned int get_row(){ return row;}

  unsigned int get_column(){ return column;};

  std::string get_current_board();
  
private:
  unsigned int row;
  unsigned int column;

  std::vector<std::vector<std::string>> board;

};



#endif
