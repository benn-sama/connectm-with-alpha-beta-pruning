#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <iostream>
/*
-----
| X |
-----
| X | X | X | X |
-----------------
| X | X | X | X |
-----------------
| X | X | X | X |
-----------------

*/

class UI {
  public:
    UI();
    void UIDisplay(int** matrix, int row); // displays the current state of the board
    std::string checkPlayerElement(int**& matrix, int i, int j);
};

#endif