#include "UI.hpp"

UI::UI() {}

void UI::UIDisplay(int** matrix, int row) { // display the current state of the board
  int column = row;
  int numOfDashesInHorizontalLine = (4 * row) + 1; // decides how much elements are in the horizontal seperator "--------" or "----"
  std::string matrixCopy = "";

  matrixCopy.append(numOfDashesInHorizontalLine, '-'); // adds '----' first
  
  for (int i = 0; i < row; ++i) { // formats the rest of the board
    matrixCopy.append(1, '\n');

    for (int j = 0; j < column; ++j) { 
      matrixCopy.append("| "); 
      matrixCopy.append(this->checkPlayerElement(matrix, i, j)); // checks for 0, 1, 2 in the board and replaces with 'X', 'O', and empty space
      matrixCopy.append(1, ' ');
    }
    matrixCopy.append(1, '|');
    matrixCopy.append(1, '\n');
    matrixCopy.append(numOfDashesInHorizontalLine, '-');
  }

  // adds the column numbers at the end of the string
  matrixCopy.append(1, '\n');  
  matrixCopy.append("  ");
  for (short i = 0; i < row; ++i) {
    matrixCopy.append(std::to_string(i + 1));
    matrixCopy.append("   ");
  }

  std::cout << std::endl << matrixCopy << std::endl; // copys the whole matrix
  
} 

std::string UI::checkPlayerElement(int**& matrix, int i, int j) { // checks for X, O, ' ' inputs
      if (std::to_string(matrix[i][j]) == "1") {
        return "X";
      }
      else if (std::to_string(matrix[i][j]) == "2") {
        return "O";
      }
      else {
        return " ";
      }
}