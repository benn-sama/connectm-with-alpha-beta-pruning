#include "node.hpp"

void Node::addChild(Node* newChild) {
  if (!newChild) { // prevents adding a null child into the tree
    std::cout << "adding a newChild as a pointer is prohibited!\n";
    exit(1);
  }

  newChild->parent = this; // new child's parents is pointed towards current node

  if (!firstChild) { // checks if it is the first child
    firstChild = newChild;
  }
  else {
    Node* sibling = firstChild; // start with the first child

    while (sibling->nextSibling) { // cycles through siblings until finding the last one
      sibling = sibling->nextSibling;
    }
    sibling->nextSibling = newChild; // adds the new child on the farthest right
  }
}

int Node::getUtility() { 
  return utility;
}

int Node::getWinningCount() {
  return winningCount;
}

void Node::getCurrentState() {
    state.displayCurrentGame();
}