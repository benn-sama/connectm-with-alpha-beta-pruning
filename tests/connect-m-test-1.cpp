#include "./game/connect-m.hpp"
#include <iostream>
#include <cassert>

void test_vertical_win() {
  std::cout << "Testing vertical win condition..." << std::endl;
  ConnectM connectm(5, 3);
  
  // Player 1 places three disks in column 1
  connectm.play(1, 1);
  connectm.play(1, 1);
  connectm.play(1, 1);
  
  connectm.displayCurrentGame();
  std::cout << "Check #1...\n";
  bool result = connectm.checkForWinner(1, 1);
  std::cout << "Vertical win test: " << (result ? "PASS" : "FAIL") << std::endl << std::endl;
}

void test_horizontal_win() {
  std::cout << "Testing horizontal win condition..." << std::endl;
  ConnectM connectm(5, 3);
  
  // Player 1 places three disks in a row
  connectm.play(1, 1);
  connectm.play(1, 2);
  connectm.play(1, 3);
  
  connectm.displayCurrentGame();
  bool result = connectm.checkForWinner(1, 3);
  std::cout << "Horizontal win test: " << (result ? "PASS" : "FAIL") << std::endl << std::endl;
}

void test_right_diagonal_win() {
  std::cout << "Testing right diagonal win condition..." << std::endl;
  ConnectM connectm(5, 3);
  
  // Set up a board for left diagonal win (down and left)
  connectm.play(1, 3); // Bottom piece
  
  connectm.play(2, 2); // Bottom piece
  connectm.play(1, 2); // Middle piece
  
  connectm.play(1, 1); // Bottom piece
  connectm.play(2, 1);
  connectm.play(1, 1); // Top piece
  
  connectm.displayCurrentGame();
  bool result = connectm.checkForWinner(1, 1);
  std::cout << "Right diagonal win test: " << (result ? "PASS" : "FAIL") << std::endl << std::endl;
}

void test_left_diagonal_win() {
  std::cout << "Testing left diagonal win condition..." << std::endl;
  ConnectM connectm(5, 3);
  
  // Set up a board for right diagonal win (down and right)
  connectm.play(1, 1); // Bottom piece
  
  connectm.play(2, 2); // Bottom piece 
  connectm.play(1, 2); // Middle piece
  
  connectm.play(1, 3); // Bottom piece
  connectm.play(2, 3);
  connectm.play(1, 3); // Top piece
  
  connectm.displayCurrentGame();
  bool result = connectm.checkForWinner(1, 3);
  std::cout << "Left diagonal win test: " << (result ? "PASS" : "FAIL") << std::endl << std::endl;
}

void test_draw() {
  std::cout << "Testing draw condition..." << std::endl;
  ConnectM connectm(5, 3);
  
  // Fill the board in a pattern ensuring no winner
  // First column - fill completely
  connectm.play(1, 1);
  connectm.play(2, 1);
  connectm.play(1, 1);
  connectm.play(2, 1);
  connectm.play(1, 1);  // Top row piece
  
  // Second column - fill completely
  connectm.play(2, 2);
  connectm.play(1, 2);
  connectm.play(2, 2);
  connectm.play(1, 2);
  connectm.play(2, 2);  // Top row piece
  
  // Third column - fill completely
  connectm.play(1, 3);
  connectm.play(2, 3);
  connectm.play(1, 3);
  connectm.play(2, 3);
  connectm.play(1, 3);  // Top row piece
  
  // Fourth column - fill completely
  connectm.play(2, 4);
  connectm.play(1, 4);
  connectm.play(2, 4);
  connectm.play(1, 4);
  connectm.play(2, 4);  // Top row piece
  
  // Fifth column - fill completely
  connectm.play(1, 5);
  connectm.play(2, 5);
  connectm.play(1, 5);
  connectm.play(2, 5);
  connectm.play(1, 5);  // Top row piece
  
  connectm.displayCurrentGame();
  bool result = connectm.checkForDraw();
  std::cout << "Draw test: " << (result ? "PASS" : "FAIL") << std::endl << std::endl;
}

void test_no_win() {
  std::cout << "Testing no win condition..." << std::endl;
  ConnectM connectm(5, 3);
  
  // Player 1 and 2 alternate moves without creating a win
  connectm.play(1, 1);
  connectm.play(2, 2);
  connectm.play(1, 3);
  
  connectm.displayCurrentGame();
  bool result = connectm.checkForWinner(1, 3);
  std::cout << "No win test: " << (!result ? "PASS" : "FAIL") << std::endl << std::endl;
}

void test_copy_game() {
    std::cout << "Testing copy method..." << std::endl;
  ConnectM connectm(5, 3);
  
  // Fill the board in a pattern ensuring no winner
  // First column - fill completely
  connectm.play(1, 1);
  connectm.play(2, 1);
  connectm.play(1, 1);
  connectm.play(2, 1);
  connectm.play(1, 1);  // Top row piece
  
  // Second column - fill completely
  connectm.play(2, 2);
  connectm.play(1, 2);
  connectm.play(2, 2);
  connectm.play(1, 2);
  connectm.play(2, 2);  // Top row piece
  
  // Third column - fill completely
  connectm.play(1, 3);
  connectm.play(2, 3);
  connectm.play(1, 3);
  connectm.play(2, 3);
  connectm.play(1, 3);  // Top row piece
  
  // Fourth column - fill completely
  connectm.play(2, 4);
  connectm.play(1, 4);
  connectm.play(2, 4);
  connectm.play(1, 4);
  connectm.play(2, 4);  // Top row piece
  
  // Fifth column - fill completely
  connectm.play(1, 5);
  connectm.play(2, 5);
  connectm.play(1, 5);
  connectm.play(2, 5);
  connectm.play(1, 5);  // Top row piece

  int **matrix = connectm.copyGame();
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}

int main() {
  test_vertical_win();
  test_horizontal_win();
  test_right_diagonal_win();
  test_left_diagonal_win();
  test_draw();
  test_copy_game();
  test_no_win();
  
  return 0;
}