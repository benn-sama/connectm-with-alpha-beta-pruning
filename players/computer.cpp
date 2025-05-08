#include "computer.hpp"

Computer::Computer(ConnectM const connect, int maxDepth, int winningDiskNum, int input) { // default constructor to initialize root
  root = new Node(0, 0, connect);
  this->maxDepth = maxDepth;
  this->winningDiskNum = winningDiskNum;
  rowSize = connect.getColumnSize();
  columnSize = connect.getRowSize();
  this->input = input;
}

int Computer::determineWinningCount(Node* currentNode) { // determines how many ways the computer can win in that current state
  int row = currentNode->state.getLastRowPlay();
  int column = currentNode->state.getLastColumnPlay();

  int totalPotentialWins = this->horizontal(currentNode, row, column, input);
  totalPotentialWins += this->vertical(currentNode, row, column, input);
  totalPotentialWins += this->leftDiagonal(currentNode, row, column, input);
  totalPotentialWins += this->rightDiagonal(currentNode, row, column, input);

  return totalPotentialWins;
}

int Computer::horizontal(Node* currentNode, int row, int column, int input) { // checks for potential wins horizontally
  int count = winningDiskNum - 1;
  int k = 0;
  int winningCount = 0;
  int potentialWinCount = 0; // keeps count of how many potential wins can occur for the current play
  int const i = row;

  while (count >= 0) { // sliding window algorithm
    for (int j = column - count; j <= column + k; ++j) { // actual sliding window
      if (this->outOfBoundsCheck(j, columnSize)) {  // checks out of bounds
        int currentCell = currentNode->state.returnCell(i, j); // holds the input of that specific cell input/play

        if ((currentCell == input) || (currentCell == 0)) { // checks for potential play. If the cell is already occupied, we assume we can't win using that line
          ++winningCount;
        }
        else {
          break;
        }
      }
    }

    if (winningCount == winningDiskNum) { // checks if the line has potential to win
      ++potentialWinCount;
    }

    winningCount = 0;
    --count;
    ++k;
  }

  return potentialWinCount;
}

int Computer::vertical(Node* currentNode, int row, int column, int input) { // checks for potential vertical
  int count = winningDiskNum - 1;
  int winningCount = 0;
  int potentialWinCount = 0;
  int const j = column;

  while (count >= 0) { // sliding window algorithm
    for (int i = row + count; i >= column; --i) { // actual sliding window
      if (this->outOfBoundsCheck(i, columnSize)) { // checks for out of bounds
        int currentCell = currentNode->state.returnCell(i, j); // holds the input of that specific cell input/play

        if (currentCell == input || (currentCell == 0)) { // checks for potential play. If the cell is already occupied, we assume we can't win using that line
          ++winningCount;
        }
        else {
          break;
        }
      }
    }

    if (winningCount == winningDiskNum) {
      ++potentialWinCount;
    }

    winningCount = 0;
    --count;
  }

  return potentialWinCount;
}

int Computer::leftDiagonal(Node* currentNode, int row, int column, int input) {
  int count = winningDiskNum - 1;
  int k = 0;
  int winningCount = 0;
  int potentialWinCount = 0;

  while (count >= 0) { // sliding window algorithm
    int i = row + count;

    for (int j = column - count; j <= column + k; ++j) { // actual sliding window
      if ((this->outOfBoundsCheck(j, columnSize)) && (this->outOfBoundsCheck(i, columnSize))) { // checks for out of bounds
        int currentCell = currentNode->state.returnCell(i, j); // holds that specific cell input/play

        if (currentCell == input || currentCell == 0) { // checks for potential play. If the cell is already occupied, we assume we can't win using that line
          ++winningCount;
        }
        else {
          break;
        }
      }

      --i;
    }

    if (winningCount == winningDiskNum) {
      ++potentialWinCount;
    }
    
    winningCount = 0;

    --count;
    ++k;
  }

  return potentialWinCount;
}

int Computer::rightDiagonal(Node* currentNode, int row, int column, int input) {
  int count = winningDiskNum - 1;
  int k = 0;
  int winningCount = 0;
  int potentialWinCount = 0;

  while (count >= 0) { // sliding window algorithm
    int i = row + count;

    for (int j = column + count; j >= columnSize - k; --j) { // actual sliding window
      if ((this->outOfBoundsCheck(j, columnSize)) && (this->outOfBoundsCheck(i, columnSize))) { // checks for out of bounds
        int currentCell = currentNode->state.returnCell(i, j);

        if (currentCell == input || currentCell == 0) {// checks for potential play. If the cell is already occupied, we assume we can't win using that line
          ++winningCount;
        }
        else {
          break;
        }
      }
      --i;
    }

    if (winningCount == winningDiskNum) {
      ++potentialWinCount;
    }

    winningCount = 0;
    --count;
    ++k;
  }
}


int Computer::actions(ConnectM* connect) { // returns all possible moves the agent can make

}


int Computer::abSearch(ConnectM* connect) { // starts from initial state and tries all possible actions and returns final column play

}

int Computer::minValue(Node* node, ConnectM* connect, int alpha, int beta) { // minimal value

}

int Computer::maxValue(Node* node, ConnectM* connect, int alpha, int beta) { // max value

}

int Computer::utility(Node* node, ConnectM* connect) { // returns a win (1), loss (-1), draw (0), in-play(2)

}

bool Computer::outOfBoundsCheck(int index, int maxSize) {
  if (index >= 0 && index <= maxSize) { 
   return true; 
  }

  return false;
}

Computer::~Computer() { // destructor

}