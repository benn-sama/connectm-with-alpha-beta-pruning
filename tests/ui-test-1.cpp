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

int main() {
  test_ui_display_no_input();
  test_multiple_ui_display_no_input();

  return 0;
}