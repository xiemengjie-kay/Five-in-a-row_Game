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
  
  /*
  winH() returns a bool value that indicates whether the piece has five in
  a horizontal line. True means there are. False means there aren't.
  
  @param boardPtr a pointer that points to the first element of the 
         2-D vector board.
  @param piece the piece you want to check.
  @param col the number of columns of the game board

  @return bool
  */
  bool winH(const std::vector<std::vector<std::string>>* boardPtr, 
            const std::string& piece, unsigned int col)
  {
    for (auto v : *boardPtr)
    {
        unsigned int count = 0;
        for (unsigned int i = 1; i <= col; i++)
        {
            if (v[i] == piece)
            {
                count++;
                if (count == 5)
                {
                    return true;
                }
            }
            else
            {
                count = 0;
            }
        }
    }
    return false;
  }


  /*
  winV() returns a bool value that indicates whether the piece has five in
  a vertical line. True means there are. False means there aren't.
  */
  bool winV(const std::vector<std::vector<std::string>>* boardPtr, 
            const std::string& piece, unsigned int col)
  {
    for (unsigned int i = 1; i <= col; i++)
      {
	unsigned int count = 0;
	for (auto v : *boardPtr)
	  {
	    if (v[i] == piece)
	      {
		count++;
		if (count == 5)
		  {
		    return true;
		  }
	      }
	    else
	      {
		count = 0;
	      }
	  }
      }
    return false;
  }

  /*
  winLeftD() returns a bool value that indicates whether the piece has five in
  a left diagonal line. True means there are. False means there aren't.
  */
  bool winLeftD(const std::vector<std::vector<std::string>>& board, 
		const std::string& piece, unsigned int row, unsigned int col)
  {
    // loop through the rows that need to be checked (1 ~ row-4)
    for (unsigned int i = 1; i <= row - 4; i++)
      {
	// loop through the column that needs to be checked (1 ~ col-4)
	for (unsigned int j = 1; i <= col - 4; j++)
	  {
	    if (board[i][j] == piece && board[i+1][j+1] == piece &&
		board[i+2][j+2] == piece && board[i+3][j+3] == piece &&
		board[i+4][j+4] == piece)
	      {
		// five in a row
		return true;
	      }
	  }
      }
    return false;
  }

  /*
  winRightD() returns a bool value that indicates whether the piece has five in
  a right diagonal line. True means there are. False means there aren't.
  */
  bool winRightD(const std::vector<std::vector<std::string>>& board, 
		const std::string& piece, unsigned int row, unsigned int col)
  {
    for (unsigned int i = 1; i <= row - 4; i++)
      {
	for (unsigned int j = col; i >= 5; j--)
	  {
	    if (board[i][j] == piece && board[i+1][j-1] == piece &&
		board[i+2][j-2] == piece && board[i+3][j-3] == piece &&
		board[i+4][j-4] == piece)
	      {
		return true;
	      }
	  }
      }
    return false;
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
  // check if the position is already occupied
  if (board[row][column] == "*")
  {
    board[row][column] = piece;
  }
  else
  {
    throw InvalidInput{};
  }
}


bool Board::win(const std::string& piece) const
{
    // check the horizontal
    bool h = winH(&board, piece, column);

    // check the vertical
    bool v = winV(&board, piece, column);
    
    // check the right diagonal
    bool lD = winLeftD(board, piece, row, column);
    
    // check the left diagonal
    bool rD = winRightD(board, piece, row, column);
    
    return h or v or lD or rD;
}
