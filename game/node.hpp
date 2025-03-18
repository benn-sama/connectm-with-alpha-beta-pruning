#ifndef NODE_HPP
#define NODE_HPP
// the "memory" of the computer
/* Data Structure: First-Child Next-Sibling Representation
            1
          / | \
         2  3  4
        / \
       5   6

*/
#include "connect-m.hpp"

class Node {
  private:
    int utility; // if this node is a winner(1), loss(0), or a tie(0.5)
    int winningCount; // stores how many potential wins for current move
    ConnectM state; // holds the current state of the board
    Node* parent; // holds the parent of this node
    Node* firstChild; // holds the left-most child of this node
    Node* nextSibling; // holds the next right child
  public:
    Node(int utility, int winningCount, ConnectM state) : utility(utility), winningCount(winningCount), state(state) {} // paramterized constructor
    void addChild(Node* parent, Node* firstChild, Node* nextSibling); // adds a child
    int getUtility(); // returns utility
    int getWinningCount(); // returns winningCount
};

#endif