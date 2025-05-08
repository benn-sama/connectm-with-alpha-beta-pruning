#include "computer.hpp"

Computer::Computer(ConnectM const connect, int maxDepth, int winningDiskNum) { // default constructor to initialize root
  root = new Node(0, 0, connect);
  this->maxDepth = maxDepth;
  this->winningDiskNum = winningDiskNum;
}

int Computer::determineWinningCount(ConnectM* connect) { // determines how many ways the computer can win in that current state
  
}

int Computer::horizontal(Node* currentNode, int row, int column, int input) {
  int count = winningDiskNum - 1;
  int k = 0;
  int winningCount = 0;
  int potentialWinningCount = 0;
  int const i = row;

  while (count >= 0) {
    for (int j = column - count; j <= column + k; ++j) {
      if (j >= 0 && j <= currentNode->state.getColumnSize()) {
        int currentCell = currentNode->state.returnCell(row, column);
        if ((currentCell == input) || (currentCell == 0)) {
          ++winningCount;
        }
      }
    }
  }

  if (winningCount == winningDiskNum) {
    ++potentialWinningCount;
  }
  winningCount = 0;
  --count;
  ++k;
}

int Computer::vertical(Node* currentNode, int row, int column, int input) {
  int count = winningDiskNum - 1;
  int winningCount = 0;
  int const j = column;

  // STOPPED HERE 05/08/25
}

int Computer::leftDiagonal(Node* currentNode, int row, int column, int input) {

}

int Computer::rightDiagonal(Node* currentNode, int row, int column, int input) {

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

Computer::~Computer() { // destructor

}