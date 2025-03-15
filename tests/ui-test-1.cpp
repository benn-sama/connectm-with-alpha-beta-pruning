#include "./game/UI.hpp"
#include "./game/connect-m.hpp"

#include <cassert>

void test_ui_display_no_input() {
  std::cout << "Testing one display with no input plays..." << std::endl;
  ConnectM connectm(3, 3);
  UI ui;

  ui.UIDisplay(connectm.copyGame(), 3);
  std::cout << "One display with no input: PASS OR FAIL?" << std::endl << std::endl;
}

void test_multiple_ui_display_no_input() {
  std::cout << "Testing eight displays with no input plays but different sizes..." << std::endl;
  UI ui;
  ConnectM connectm1(1, 1);
  ConnectM connectm2(2, 2);
  ConnectM connectm3(3, 3);
  ConnectM connectm4(4, 4);
  ConnectM connectm5(5, 5);
  ConnectM connectm6(6, 6);
  ConnectM connectm7(7, 7);
  ConnectM connectm8(8, 8);

  std::cout << "Connect #1: ";
  ui.UIDisplay(connectm1.copyGame(), 1);
  std::cout << "\n";

  std::cout << "Connect #2: ";
  ui.UIDisplay(connectm2.copyGame(), 2);
  std::cout << "\n";

  std::cout << "Connect #3: ";
  ui.UIDisplay(connectm3.copyGame(), 3);
  std::cout << "\n";

  std::cout << "Connect #4: ";
  ui.UIDisplay(connectm4.copyGame(), 4);
  std::cout << "\n";

  std::cout << "Connect #5: ";
  ui.UIDisplay(connectm5.copyGame(), 5);
  std::cout << "\n";

  std::cout << "Connect #6: ";
  ui.UIDisplay(connectm6.copyGame(), 6);
  std::cout << "\n";

  std::cout << "Connect #7: ";
  ui.UIDisplay(connectm7.copyGame(), 7);
  std::cout << "\n";

  std::cout << "Connect #8: ";
  ui.UIDisplay(connectm8.copyGame(), 8);
  std::cout << "\n";

  std::cout << "Eight displays with no input with different sizes: PASS OR FAIL?" << std::endl << std::endl;
}

void test_ui_display_with_vertical_input() {
  std::cout << "Testing one display with input plays..." << std::endl;
  ConnectM connectm(5, 3);
  UI ui; 

  connectm.play(1, 1);
  connectm.play(2, 1);
  connectm.play(1, 1);
  connectm.play(2, 1);
  connectm.play(1, 1);

  ui.UIDisplay(connectm.copyGame(), 5);
  std::cout << "One display with vertical input play: PASS OR FAIL?" << std::endl << std::endl;
}

void test_ui_display_with_horizontal_input() {
  std::cout << "Testing display with horizontal input play..." << std::endl;
  ConnectM connectm(5, 3);
  UI ui;
  
  // Player 1 places three disks in a row
  connectm.play(1, 1);
  connectm.play(2, 2);
  connectm.play(1, 3);
  connectm.play(2, 4);
  connectm.play(1, 5);
  
  ui.UIDisplay(connectm.copyGame(), 5);
  std::cout << "One display with horizontal input play: PASS OR FAIL?" << std::endl << std::endl;
}

void test_ui_display_with_left_diagonal_input() {
  std::cout << "Testing display with left diagonal input play..." << std::endl;
  ConnectM connectm(5, 3);
  UI ui;
  
  // Player 1 places three disks in a row
  connectm.play(1, 3); // Bottom piece
  
  connectm.play(2, 2); // Bottom piece
  connectm.play(1, 2); // Middle piece
  
  connectm.play(1, 1); // Bottom piece
  connectm.play(2, 1);
  connectm.play(1, 1); // Top piece
  
  ui.UIDisplay(connectm.copyGame(), 5);
  std::cout << "One display with left input play: PASS OR FAIL?" << std::endl << std::endl;
}

void test_ui_display_with_right_diagonal_input() {
  std::cout << "Testing displays with right diagonal input play..." << std::endl;
  ConnectM connectm(5, 3);
  UI ui;
  
  // Set up a board for right diagonal win (down and right)
  connectm.play(1, 1); // Bottom piece
  
  connectm.play(2, 2); // Bottom piece 
  connectm.play(1, 2); // Middle piece
  
  connectm.play(1, 3); // Bottom piece
  connectm.play(2, 3);
  connectm.play(1, 3); // Top piece
  
  ui.UIDisplay(connectm.copyGame(), 5);
  std::cout << "One display with right input play: PASS OR FAIL?" << std::endl << std::endl;
}

void test_ui_display_with_fully_filled_game() {
  std::cout << "Testing displays with a fully filled input play..." << std::endl;
  ConnectM connectm(5, 3);
  UI ui;
  
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
  
  ui.UIDisplay(connectm.copyGame(), 5);
  std::cout << "One display with fully filled input play: PASS OR FAIL?" << std::endl << std::endl;
}

int main() {
  test_ui_display_no_input();
  test_multiple_ui_display_no_input();
  test_ui_display_with_vertical_input();
  test_ui_display_with_horizontal_input();
  test_ui_display_with_left_diagonal_input();
  test_ui_display_with_right_diagonal_input();
  test_ui_display_with_fully_filled_game();

  return 0;
}