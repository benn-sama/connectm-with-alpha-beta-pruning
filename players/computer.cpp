#include "computer.hpp"

Computer::Computer(ConnectM connect) { // default constructor to initialize root
  
}

int Computer::determineWinningCount(ConnectM* connect) { // determines how many ways the computer can win in that current state
  
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