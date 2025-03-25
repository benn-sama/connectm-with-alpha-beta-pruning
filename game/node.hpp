#ifndef NODE_HPP
#define NODE_HPP
// the "memory" of the computer
/* Data Structure: First-Child Next-Sibling Tree
            0
          / | \
         1  2  3
        / \
       4   5
      / \
     6   7
*/
#include "connect-m.hpp"

class Node {
  private:
    int utility; // if this node is a winner(1), loss(-1), tie(0), in-play(2)
    int winningCount; // stores how many potential wins for current move
    ConnectM state; // holds the current state of the board
  public:
    Node* parent; // holds the parent of this node
    Node* firstChild; // holds the left-most child of this node
    Node* nextSibling; // holds the next right child
    Node(int utility, int winningCount, ConnectM state) : utility(utility), winningCount(winningCount), state(state), parent(nullptr), firstChild(nullptr), nextSibling(nullptr) {} // paramterized constructor
    void addChild(Node* newChild); // adds a child
    int getUtility(); // returns utility
    int getWinningCount(); // returns winningCount
    void getCurrentState();
};

#endif