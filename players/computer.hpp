#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "./game/node.hpp"

class Computer {
  private:
  Node* root;
  public:
    Computer(ConnectM connect); // default constructor
    int determineWinningCount(ConnectM* connect);  // determines how many ways it can win
    int actions(ConnectM* connect);  // returns all possible moves the agent can make
    int abSearch(ConnectM* connect); // starts from initial state and tries all possible actions and returns final column play
    int minValue(Node* node, ConnectM* connect, int alpha, int beta); // minimal value
    int maxValue(Node* node, ConnectM* connect, int alpha, int beta); // max value
    int utility(Node* node, ConnectM* connect); // returns a win (1), loss (-1), or a draw (0)
    ~Computer(); // destructor
};

#endif