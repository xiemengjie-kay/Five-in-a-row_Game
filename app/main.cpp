#include "Board.hpp"
#include <iostream>
#include "InvalidInput.hpp"


namespace
{
  // throw InvalidInput error if the user input is an unsigned int
  // that is less than 5
  void checkInput(unsigned int num)
  {
    if (num < 5)
      {
	throw InvalidInput{};
      }
  }
}



int main()
{
  unsigned int row;
  unsigned int column;
  bool flag = true;
  while (flag)
    {
      std::cout << "Please specify how many rows you want:";
      std::cin >> row;
      try
	{
	  checkInput(row);
	  flag = false;
	}
      catch (InvalidInput&)
	{
	  std::cout << "Invalid row number." << std::endl;
	}
    }
  flag = true;
  while (flag)
    {
      std::cout << "Please specify how many columns you want:";
      std::cin >> column;
      try
	{
	  checkInput(column);
	  flag = false;
	}
      catch (InvalidInput&)
	{
	  std::cout << "Invalid column number." << std::endl;
	}
    }
  Board board{row, column};
  std::cout << board.get_current_board();
  
  bool gameOver = false;
  unsigned int row1;
  unsigned int column1;
  unsigned int row2;
  unsigned int column2;
  while (!gameOver)
    {
      bool player1 = true;
      while (player1)
	{
	  std::cout << "Turn to player 1, please input the position ";
	  std::cout << "(row column):";
	  std::cin >> row1 >> column1;
	  try
	    {
	      board.drop(row1, column1, "O");
	      player1 = false;
	    }
	  catch (InvalidInput&)
	    {
	      std::cout << "Invalid position." << std::endl;
	    }
	}
      std::cout << board.get_current_board();
      // TODO: after player1 does an action, check if player 1 wins
      bool player2 = true;
      while (player2)
	{
	  std::cout << "Turn to Player2, please input the position ";
	  std::cout << "(row column)";
	  std::cin >> row2 >> column2;
	  try
	    {
	      board.drop(row2, column2, "X");
	      player2 = false;
	    }
	  catch (InvalidInput&)
	    {
	      std::cout << "Invalid position." << std::endl;
	    }
	}
      std::cout << board.get_current_board();
      // TODO: after player2 does an action, check if player2 wins
    }

  return 0;
}
