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
