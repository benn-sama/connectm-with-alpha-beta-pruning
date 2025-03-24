#include "./game/node.hpp"
/* 
* This file tests the node class in node.hpp only adding different utility and winningCount values
* This file only added nodes have different input for each node
* This uses the First-Child Next Sibling Tree
*/

void deleteTree(Node* node) {
  if (!node) {
    return;
  }

  Node* child = node->firstChild;
  while (child) {
    Node* next = child->nextSibling; // holds the next child
    deleteTree(child); // recursively delete the sub tree
    child = next; // assigns child to the next
  }

  delete node; // delete node
}

void addChildren(Node* node, ConnectM* connect, int start, int end) { // adds children and onen input play
  int column = 1;
  int input = 1;
  
  if (!node || (connect == nullptr)) {
    return;
  }
  
  for (int i = start; i < end + 1; ++i) {
    if (!connect->play(input, column)) {
      column++;
      connect->play(input, column);
    }

    Node* newChild = new Node(i, i, *connect);
    node->addChild(newChild);
    
    if (input == 1) {
      input = 2;
    }
    else {
      input = 1;
    }
  }
}

void displayAllGames(Node* node) { // displays all games. doesn't work if there is only the root node in tree
  Node* current = node->firstChild;
  int expectedIndex = 0;

  while (current) {
    std::cout << std::endl << "Node: " << expectedIndex << std::endl;
    current->getCurrentState();
    std::cout << std::endl;

    if (!current->nextSibling) { // checks if nextSibling is a nullptr, if not traverse to the next depth
      current = current->parent;
      current = current->firstChild;
      current = current->firstChild;
    }
    else {
      current = current->nextSibling; // traverses to the next sibling
    }

    ++expectedIndex;
  }
}


void depth_0() {
  std::cout << "TESTING: depth_0" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  std::cout << std::endl << "Node: " << 0 << std::endl;
  root->getCurrentState();
  std::cout << std::endl;

  std::cout << "PASSED: depth_0\n" << std::endl;
  deleteTree(root);
}

void depth_1() {
  std::cout << "TESTING: depth_1" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  addChildren(root, &connect, 1, 3); // adds children

  displayAllGames(root);
  
  std::cout << "PASSED: depth_1\n" << std::endl;

  deleteTree(root); // delete the tree
}

void depth_2() {
  std::cout << "TESTING: depth_2" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  addChildren(root, &connect, 1, 4); // adds 1st depth
  addChildren(root, &connect, 5, 8); // adds 2nd depth

  displayAllGames(root); // dislays game tree
  
  std::cout << "PASSED: depth_2\n" << std::endl;

  deleteTree(root); // delete the tree
}

void depth_3() {
  std::cout << "TESTING: depth_3" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  addChildren(root, &connect, 1, 4); // adds 1st depth
  addChildren(root, &connect, 5, 8); // adds 2nd depth
  addChildren(root, &connect, 9, 14); // adds 3rd depth

  displayAllGames(root); // dislays game tree
  
  std::cout << "PASSED: depth_3\n" << std::endl;

  deleteTree(root); // delete the tree
}

void depth_4() {
  std::cout << "TESTING: depth_4" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  addChildren(root, &connect, 1, 4); // adds 1st depth
  addChildren(root, &connect, 5, 8); // adds 2nd depth
  addChildren(root, &connect, 9, 14); // adds 3rd depth
  addChildren(root, &connect, 15, 22); // adds 4th depth

  displayAllGames(root); // dislays game tree
  
  std::cout << "PASSED: depth_4\n" << std::endl;

  deleteTree(root); // delete the tree
}

int main() {
  std::cout << "-----------TESTING: TREE WITH ONLY DIFFERENT UTILITY AND WINNING COUNT-----------" << std::endl << std::endl;
  depth_0();
  depth_1();
  depth_2();
  depth_3();
  depth_4();
  std::cout << "-----------FINSHED: TREE WITH ONLY DIFFERENT UTILITY AND WINNING COUNT-----------" << std::endl << std::endl;
  return 0;
  
}