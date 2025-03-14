#include "./game/UI.hpp"
#include "./game/connect-m.hpp"

#include <cassert>

void test_ui_display_no_input() {
  std::cout << "Testing display with no input plays..." << std::endl;
  ConnectM connectm(3, 3);
  UI ui;

  ui.UIDisplay(connectm.copyGame(), 3);
}

int main() {
  test_ui_display_no_input();

  return 0;
}