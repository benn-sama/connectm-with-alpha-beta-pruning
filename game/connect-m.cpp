#include "connect-m.hpp"

ConnectM::ConnectM(int row, int winningDiskNum) { // default constructor which calls the initalize matrixs
  this->row = row;
  column = this->row;
  this->winningDiskNum = winningDiskNum;

  this->initialize(); // initializes matrix for connectm game
}

void ConnectM::initialize() { // initializes the matrix
  matrix = new int*[row];

  for (int i = 0; i < row; ++i) { // creates a 2d pointer array
    matrix[i] = new int[column];

    for (int j = 0; j < column; ++j) {
      matrix[i][j] = 0;
    }
  }

  // initializes selectedColumn to be the row size
  selectedColumn = new int[row];

  for (int j = 0; j < row; ++j) {
    selectedColumn[j] = row - 1;
  }
}

bool ConnectM::play(int input, int column) { // inputs the player's move, returns true if column is not full
  column -= 1; // to correctly access the array

  if (!this->isColumnFull(column)) { // checks if column is full, if not, place player input
    matrix[selectedColumn[column]][column] = input;
    selectedColumn[column] -= 1;
    return true;
  }
  else {
    return false;
  }
}


void ConnectM::displayCurrentGame() { // displays current situation of game
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      std::cout << matrix[i][j];

      if (j < column - 1) { // prevents an extra space at the end of the line
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
}

bool ConnectM::isColumnFull(int column) { // checks if the column is full
  if (selectedColumn[column] >= 0) {
        return false;
    }
    
    return true;
}

bool ConnectM::checkForWinner(int input, int column) { // checks for winner
  column -= 1;
  int row = selectedColumn[column] + 1;
  if (row == -1) {
    row = 0;
  }

  if (this->horizontal(row, column, input))  {
    return true;
  }

  if (this->leftVertical(row, column, input)) {
    return true;
  }

  return false;
}

bool ConnectM::horizontal(int row, int column, int input) {
  int count = winningDiskNum - 1; 
  int k = 0;
  int winningCount = 0;
  int i = row;
  
  while (count >= 0) {
    for (int j = column - count; j <= column + k; ++j) {
      if (j >= 0 && j <= this->column) {
        if (matrix[i][j] == input) {
          ++winningCount;
        }
      }
      std::cout << "[" << i << "]" << "[" << j << "]" << " winningCount: " << winningCount << std::endl;
    }

    if (winningCount == winningDiskNum) {
      return true;
    }
    else {
      winningCount = 0;
    }
    std::cout << "CLEARED\n";
    --count;
    ++k;
  }

  return false;
}

bool ConnectM::leftVertical(int row, int column, int input) { // vertical check winner
  int count = winningDiskNum - 1;
  int k = 0;
  int winningCount = 0;

  if (row + winningDiskNum - 1 > this->row) {
    return false;
  }

  while (count >= 0) {
    int i = row + count;
    for (int j = column - count; j <= column + k; ++j) {
      if ((j >= 0 && j <= this->column) && (i >= 0 && i <= this->column)) {
        if (matrix[i][j] == input) {
          ++winningCount;
        }
        std::cout << "[" << i << "]" << "[" << j << "]" << " winningCount: " << winningCount << "; input: " << matrix[i][j] << std::endl;
      }
      --i;
    }

    if (winningCount == winningDiskNum) {
      return true;
    }
    else {
      winningCount = 0;
    }
    std::cout << "CLEARED\n";
    --count;
    ++k;
  }
}

bool ConnectM::rightVertical(int row, int column, int input) {

}

bool ConnectM::checkForDraw() { // checks for a draw
  int count = 0;
  for (int j = 0; j < column; ++j) {
    if (matrix[0][j] == 0) {
        ++count;
    }

    if (count == column) {
        return false;
    }
  }

  return true;
}

int** ConnectM::copyGame() { // returns a copy of the game matrix for computer
  int** copyMatrix;

  copyMatrix = new int*[row];

  for (int i = 0; i < row; ++i) {
    copyMatrix[i] = new int[column];
    for (int j = 0; j < column; ++j) {
      copyMatrix[i][j] = matrix[i][j];
    }
  }

  return copyMatrix;
}

ConnectM::ConnectM(const ConnectM& other) {
    // copy primitive members
    this->row = other.row;
    this->column = other.column;
    this->winningDiskNum = other.winningDiskNum;
    
    // deep copy the matrix
    matrix = new int*[row];
    for (int i = 0; i < row; ++i) {
        matrix[i] = new int[column];
        for (int j = 0; j < column; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    
    // deep copy the selectedColumn array
    selectedColumn = new int[row];  // make sure this is being allocated
    for (int j = 0; j < row; ++j) {
        selectedColumn[j] = other.selectedColumn[j];
    }
}

ConnectM::~ConnectM() { // destructor for memory cleanup
  for (int i = 0; i < row; ++i) {
    delete[] matrix[i];
  }

  delete[] matrix;

  delete[] selectedColumn;
}