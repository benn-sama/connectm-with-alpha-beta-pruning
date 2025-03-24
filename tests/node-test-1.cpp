#include "./game/node.hpp"
/* 
* This file tests the node class in node.hpp only adding different utility and winningCount values
* This file only adds nodes that have no input
* This uses the First-Child Next Sibling Tree
*/
#include <iostream>

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

void addChildren(Node* node, ConnectM* connect, int start, int end) { // a function to add children
  if (!node || (connect == nullptr)) {
    return;
  }
  
  for (int i = start; i < end + 1; ++i) {
    Node* newChild = new Node(i, i, *connect);
    node->addChild(newChild);
  }
}



void adding_node_0_depth_no_play_return_utility_and_winningCount() { // tests only one node which is the root node
std::cout << "TESTING: adding_node_0_depth_no_play_return_utility_and_winningCount()" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  if (root->getUtility() != 0) { 
    std::cout << "FAILED: adding_node_0_depth_no_play_return_utility_and_winningCount()" << std::endl;
    std::cout << "Root node utility value is incorrect\n" << "Value: " << root->getUtility() << std::endl;
    exit(1);
  }

  if (root->getWinningCount() != 0) {
    std::cout << "FAILED: adding_node_0_depth_no_play_return_utility_and_winningCount() FAILED" << std::endl;
    std::cout << "Root node winningCount value is incorrect\n" << "Value: " << root->getWinningCount() << std::endl;
    exit(1);
  }

  std::cout << "PASSED: adding_node_0_depth_no_play_return_utility_and_winningCount()\n" << std::endl;

  delete root;
}

void adding_node_1_depth_no_play_return_utility_and_winningCount() { // tests nodes up to the first depth
  std::cout << "TESTING: adding_node_1_depth_no_play_return_utility_and_winningCount()" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  // adds two children to the root. basically adds one new layer
  addChildren(root, &connect, 1, 2);

  // first test the root node
  if (root->getUtility() != 0) {
    std::cout << "FAILED: Root node utility value is incorrect\n";
    std::cout << "Expected: 0, Got: " << root->getUtility() << std::endl;
    exit(1);
  }

  if (root->getWinningCount() != 0) {
    std::cout << "FAILED: Root node winningCount value is incorrect\n";
    std::cout << "Expected: 0, Got: " << root->getWinningCount() << std::endl;
    exit(1);
  }

  // testing each child's node
  Node* child = root->firstChild;
  int expectedIndex = 1;
  
  while (child) {
    if (child->getUtility() != expectedIndex) {
      std::cout << "FAILED: Child node utility value is incorrect\n";
      std::cout << "Expected: " << expectedIndex << ", Got: " << child->getUtility() << std::endl;
      exit(1);
    }

    if (child->getWinningCount() != expectedIndex) {
      std::cout << "FAILED: Child node winningCount value is incorrect\n";
      std::cout << "Expected: " << expectedIndex << ", Got: " << child->getWinningCount() << std::endl;
      exit(1);
    }

    child = child->nextSibling;
    expectedIndex++;
  }

  std::cout << "PASSED: adding_node_1_depth_no_play_return_utility_and_winningCount()\n" << std::endl;
  
  // cleans up memory
  deleteTree(root);
}

void adding_node_2_depth_no_play_return_utility_and_winningCount() {
  std::cout << "TESTING: adding_node_2_depth_no_play_return_utility_and_winningCount()" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  addChildren(root, &connect, 1, 2);

  Node* depth1 = root->firstChild;
  addChildren(depth1, &connect, 3, 4);

  // first test the root node
  if (root->getUtility() != 0) {
    std::cout << "FAILED: Root node utility value is incorrect\n";
    std::cout << "Expected: 0, Got: " << root->getUtility() << std::endl;
    exit(1);
  }

  if (root->getWinningCount() != 0) {
    std::cout << "FAILED: Root node winningCount value is incorrect\n";
    std::cout << "Expected: 0, Got: " << root->getWinningCount() << std::endl;
    exit(1);
  }

  Node* child = root->firstChild->firstChild;
  int expectedIndex = 3;

  while (child) {
    if (child->getUtility() != expectedIndex) {
      std::cout << "FAILED: Child node utility value is incorrect\n";
      std::cout << "Expected: " << expectedIndex << ", Got: " << child->getUtility() << std::endl;
      exit(1);
    }

    if (child->getWinningCount() != expectedIndex) {
      std::cout << "FAILED: child node winningCount value is incorrect\n";
      std::cout << "Expected: " << expectedIndex << ", Got: " << child->getWinningCount() << std::endl;
      exit(1);
    }

    child = child->nextSibling;
    ++expectedIndex;
  }

  std::cout << "PASSED: adding_node_2_depth_no_play_return_utility_and_winningCount\n" << std::endl;

  // cleans up memory
  deleteTree(root);
}

void adding_node_3_depth_no_play_return_utility_and_winningCount() {
  std::cout << "TESTING: adding_node_3_depth_no_play_return_utility_and_winningCount()" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  addChildren(root, &connect, 1, 2); // adds children to the root (zeroth depth)

  Node* depthi = root->firstChild;
  addChildren(depthi, &connect, 3, 5); // adds children in the 1st depth

  depthi = depthi->firstChild;
  addChildren(depthi, &connect, 6, 8); // adds children in the 2nd depth

  // first test the root node
  if (root->getUtility() != 0) {
    std::cout << "FAILED: Root node utility value is incorrect\n";
    std::cout << "Expected: 0, Got: " << root->getUtility() << std::endl;
    exit(1);
  }

  if (root->getWinningCount() != 0) {
    std::cout << "FAILED: Root node winningCount value is incorrect\n";
    std::cout << "Expected: 0, Got: " << root->getWinningCount() << std::endl;
    exit(1);
  }

  Node* current = root->firstChild;
  int expectedIndex = 1;

  while (current) {
    if (current->getUtility() != expectedIndex) {
      std::cout << "FAILED: Child node utility value is incorrect\n";
      std::cout << "Expected: " << expectedIndex << ", Got: " << current->getUtility() << std::endl;
      exit(1);
    }

    if (current->getWinningCount() != expectedIndex) {
      std::cout << "FAILED: child node winningCount value is incorrect\n";
      std::cout << "Expected: " << expectedIndex << ", Got: " << current->getWinningCount() << std::endl;
      exit(1);
    }

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

  std::cout << "PASSED: adding_node_3_depth_no_play_return_utility_and_winningCount()\n" << std::endl;

  deleteTree(root);
}

void adding_node_4_depth_no_play_return_utility_and_winningCount() {
  std::cout << "TESTING: adding_node_4_depth_no_play_return_utility_and_winningCount()" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  addChildren(root, &connect, 1, 2); // adds children to the root (zeroth depth)

  Node* depthi = root->firstChild;
  addChildren(depthi, &connect, 3, 5); // adds children in the 1st depth

  depthi = depthi->firstChild;
  addChildren(depthi, &connect, 6, 8); // adds children in the 2nd depth
  
  depthi = depthi->firstChild;
  addChildren(depthi, &connect, 9, 12); // adds chilrden to the 3rd depth

  // first test the root node
  if (root->getUtility() != 0) {
    std::cout << "FAILED: Root node utility value is incorrect\n";
    std::cout << "Expected: 0, Got: " << root->getUtility() << std::endl;
    exit(1);
  }

  if (root->getWinningCount() != 0) {
    std::cout << "FAILED: Root node winningCount value is incorrect\n";
    std::cout << "Expected: 0, Got: " << root->getWinningCount() << std::endl;
    exit(1);
  }

  Node* current = root->firstChild;
  int expectedIndex = 1;

  while (current) {
    if (current->getUtility() != expectedIndex) {
      std::cout << "FAILED: Child node utility value is incorrect\n";
      std::cout << "Expected: " << expectedIndex << ", Got: " << current->getUtility() << std::endl;
      exit(1);
    }

    if (current->getWinningCount() != expectedIndex) {
      std::cout << "FAILED: child node winningCount value is incorrect\n";
      std::cout << "Expected: " << expectedIndex << ", Got: " << current->getWinningCount() << std::endl;
      exit(1);
    }

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

  std::cout << "PASSED: adding_node_4_depth_no_play_return_utility_and_winningCount()\n" << std::endl;

  deleteTree(root); // deletes tree
}

int main() {
  std::cout << "-----------TESTING: TREE WITH ONLY DIFFERENT UTILITY AND WINNING COUNT-----------" << std::endl << std::endl;
  adding_node_0_depth_no_play_return_utility_and_winningCount();
  adding_node_1_depth_no_play_return_utility_and_winningCount();
  adding_node_2_depth_no_play_return_utility_and_winningCount();
  adding_node_3_depth_no_play_return_utility_and_winningCount();
  adding_node_4_depth_no_play_return_utility_and_winningCount();
    std::cout << "-----------FINISHED: TREE WITH ONLY DIFFERENT UTILITY AND WINNING COUNT-----------" << std::endl << std::endl;
  return 0;
}