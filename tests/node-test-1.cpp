#include "./game/node.hpp"
#include "./game/connect-m.hpp"
/* This file tests the node class in node.hpp
*/
#include <iostream>

void adding_node_0_depth_no_play_return_utility_and_winningCount() { // tests only one node which is the root node
std::cout << "TESTING: adding_node_0_depth_no_play_return_utility_and_winningCount()" << std::endl;
  ConnectM connect(5, 3);
  Node* root = new Node(0, 0, connect);

  if (root->getUtility() != 0) { 
    std::cout << "FAILED: adding_node_0_depth_no_play_return_utility_and_winningCount()" << std::endl;
    std::cout << "Root node utility value is incorrect\n" << "Value: " << root->getUtility();
    exit(1);
  }
  if (root->getWinningCount() != 0) {
    std::cout << "FAILED: adding_node_0_depth_no_play_return_utility_and_winningCount() FAILED" << std::endl;
    std::cout << "Root node winningCount value is incorrect\n" << "Value: " << root->getWinningCount();
    exit(1);
  }

  std::cout << "PASSED: adding_node_0_depth_no_play_return_utility_and_winningCount()\n" << std::endl;
}

void adding_node_1_depth_no_play() {

}

void adding_node_2_depth_no_play() {

}

void adding_node_3_depth_no_play() {

}

void adding_node_4_depth_no_play() {

}

int main() {
  adding_node_0_depth_no_play_return_utility_and_winningCount();
  return 0;
}