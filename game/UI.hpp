#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <iostream>
/*
class displays

-----------------
| X | X | X | X |
-----------------
| X | X | X | X |
-----------------
| X | X | X | X |
-----------------
| X | X | X | X |
-----------------
  1   3   4   5
*/

class UI {
  public:
    UI();
    void UIDisplay(int** matrix, int row); // displays the current state of the board
    std::string checkPlayerElement(int**& matrix, int i, int j); // checks for X, O, ' ' inputs
};

#endif