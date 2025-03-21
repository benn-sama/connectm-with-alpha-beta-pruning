#include "./game/node.hpp"
#include "./game/connect-m.hpp"
/* This file tests the node class in node.hpp
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
  for (int i = 0; i < 2; ++i) {
    Node* child = new Node(i, i, connect);
    root->addChild(child);
  }

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
  int expectedIndex = 0;
  
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

  for (int i = 0; i < 2; ++i) { // adds two children to the root node (added children to the first depth)
    Node* child = new Node(i, i, connect);
    root->addChild(child);
  }

  Node* depth1 = root->firstChild;
  for (int i = 0; i < 3; ++i) { // adds three children to the 2nd depth
    Node* child = new Node(i, i, connect);
    depth1->addChild(child);
  }

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

  Node* child = root->firstChild;
  child->firstChild;
  int expectedIndex = 0;

  while (child) {
    if (child->getUtility() != expectedIndex) {
      std::cout << "FAILED: Child node utility value is incorrect\n";
      std::cout << "Exepected: " << expectedIndex << ", God: " << child->getUtility() << std::endl;
      exit(1);
    }

    if (child->getWinningCount() != expectedIndex) {
      std::cout << "FAILED: child node winningCount value is incorrect\n";
      std::cout << "Expected: " << expectedIndex << ", God: " << child->getWinningCount() << std::endl;
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
}

void adding_node_4_depth_no_play_return_utility_and_winningCount() {
  std::cout << "TESTING: adding_node_4_depth_no_play_return_utility_and_winningCount()" << std::endl;
}

int main() {
  adding_node_0_depth_no_play_return_utility_and_winningCount();
  adding_node_1_depth_no_play_return_utility_and_winningCount();
  adding_node_2_depth_no_play_return_utility_and_winningCount();
  return 0;
}