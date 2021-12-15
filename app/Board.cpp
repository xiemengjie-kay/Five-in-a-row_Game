#include "Board.hpp"
#include <sstream>


Board::Board(unsigned int row, unsigned int column)
  :row{row}, column{column}
{
  std::vector<std::string> v0;
  for (unsigned int i = 1; i <= column; i++)
    {
      v0.push_back(std::to_string(i));
    }
  v0.push_back("\n");
  board.push_back(v0);

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


std::string Board::get_current_board()
{
  std::ostringstream out;
  // unsigned int numDigits = (dynamic_cast<std::string> (row)).size(); 
  for (unsigned int i = 1; i <= column; i++)
    {
      out << i << " ";
    }
  out << "\n";
  for (unsigned int i = 0; i <= row; i++)
    {
      out << i << " ";
      for (unsigned int j = 1; j <= column; j++)
	{
	  out << "* ";
	}
      out << "\n";
    }

  return out.str();
}
