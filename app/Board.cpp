#include "Board.hpp"
#include <sstream>
#include <iomanip>
#include "InvalidInput.hpp"


namespace
{
  // check if the user-input row is valid
  // if the entered row is not valid, throw InvalidInput error
  // otherwise, the function passes
  void check_row(unsigned int targetRow, unsigned int sourceRow)
  {
    if ((targetRow < 1) || (targetRow > sourceRow))
      {
	throw InvalidInput{};
      }
  }

  // check if the user-input column is valid
  // if the entered column is not valid, throw InvalidInput error
  // otherwise, the function passes
  void check_column(unsigned int targetColumn, unsigned int sourceColumn)
  {
    if ((targetColumn < 1) || (targetColumn > sourceColumn))
      {
	throw InvalidInput{};
      }
  }
}


Board::Board(unsigned int row, unsigned int column)
  :row{row}, column{column}
{
  // initialize the empty board
  // create the first row
  std::vector<std::string> v0;
  for (unsigned int i = 0; i <= column; i++)
    {
      v0.push_back(std::to_string(i));
    }
  v0.push_back("\n");
  board.push_back(v0);
  // create the following rows
  for (unsigned int i = 1; i <= row; i++)
    {
      std::vector<std::string> v;
      v.push_back(std::to_string(i));
      for (unsigned int j = 1; j <= column; j++)
	{
	  v.push_back("*");
	}
      v.push_back("\n");
      board.push_back(v);
    }
}


std::string Board::get_current_board() const
{
  std::ostringstream out;
  unsigned int width = std::to_string(column).size() + 1;
  for( const std::vector<std::string>& innerRow : board)
    {
      for (const std::string& cell : innerRow)
	{
	  out << std::setw(width) << cell;
	}
    }
  return out.str();
}


void Board::drop(unsigned int row, unsigned int column,
		 const std::string& piece)
{
  check_row(row, this->row);
  check_column(column, this->column);
  board[row][column] = piece;
  // TODO: check if the user entered position already exist
  // if already exist, throw InvalidIput from here.
}



// TODO: check if the game is over.
