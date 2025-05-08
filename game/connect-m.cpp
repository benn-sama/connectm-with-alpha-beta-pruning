#include "connect-m.hpp"

ConnectM::ConnectM(int row, int winningDiskNum) { // default constructor which calls the initalize matrixs
  this->row = row;
  column = this->row;
  this->winningDiskNum = winningDiskNum;

  this->initialize(); // initializes matrix for connectm game
  drawCondition = this->column * this->row;
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

  for (int j = 0; j < row; ++j) { // filsl the column tracker
    selectedColumn[j] = row - 1;
  }
}

bool ConnectM::play(int input, int column) { // inputs the player's move, returns true if column is not full
  column -= 1; // to correctly access the array

  if (!this->isColumnFull(column)) { // checks if column is full, if not, place player input
    lastRowPlay = selectedColumn[column];
    lastColumnPlay = column;
    matrix[selectedColumn[column]][column] = input;
    selectedColumn[column] -= 1;
    ++totalInputs;
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

  if (this->horizontal(row, column, input))  { // checks for horizontal win condition
    return true;
  }


  if (this->leftDiagonal(row, column, input)) { // checks for diagonal win condition (bottom left to top right)
    return true;
  }

  if (this->rightDiagonal(row, column, input)) { // checks for diagonal win condition (bottom right to top left)
    return true;
  }

  if (this->vertical(row, column, input)) { // checks for vertical win condition
    return true;
  }

  return false;
}

bool ConnectM::horizontal(int row, int column, int input) { // returns true for vertical win condition
  int count = winningDiskNum - 1; 
  int k = 0;
  int winningCount = 0;
  int const i = row;

  while (count >= 0) { // sliding window algorithm to check win condition
    for (int j = column - count; j <= column + k; ++j) {
      if (j >= 0 && j <= this->column) { // a check here to prevent out of bounds errors
        if (matrix[i][j] == input) {
          ++winningCount;
        }
      }
    }

    if (winningCount == winningDiskNum) { // returns true if winning disk number is met
      return true;
    }
    else {
      winningCount = 0;
    }

    --count;
    ++k;
  }

  return false;
}

bool ConnectM::leftDiagonal(int row, int column, int input) { // returns true for left diagonal win condition
  int count = winningDiskNum - 1;
  int k = 0; // keeps track of the last cell check
  int winningCount = 0;

  if (row + winningDiskNum - 1 > this->row) { // returns false if row depth is less than winningDiskNum
    return false;
  }

  while (count >= 0) { // sliding window algorithm
    int i = row + count;

    for (int j = column - count; j <= column + k; ++j) { // actual sliding window algorithm
      if ((j >= 0 && j <= this->column) && (i >= 0 && i <= this->column)) { // checks for out of bounds
        if (matrix[i][j] == input) {
          ++winningCount;
        }
      }

      --i;
    }

    if (winningCount == winningDiskNum) { // returns true if winning disk number is met
      return true;
    }
    else {
      winningCount = 0;
    }

    --count;
    ++k;
  }

  return false;
}

bool ConnectM::rightDiagonal(int row, int column, int input) { // returns true for right diagonal condition 
  int count = winningDiskNum - 1;
  int k = 0; // keeps track of the last cell check
  int winningCount = 0;

  if (row + winningDiskNum - 1 > this->row) { // returns false if row depth is less than winningDiskNum
    return false;
  }

  while (count >= 0) { // sliding window algorithm
    int i = row + count;

    for (int j = column + count; j >= column - k; --j) { // actual sliding window algorithm
      if ((j >= 0 && j <= this->column) && (i >= 0 && i <= this->column)) { // a check here to prevent out of bounds errors
        if (matrix[i][j] == input) {
          ++winningCount;
        }
      }

      --i;
    }

    if (winningCount == winningDiskNum) { // returns true if winning disk number is met
      return true;
    }
    else {
      winningCount = 0;
    }

    --count;
    ++k;
  }

  return false;
}

bool ConnectM::vertical(int row, int column, int input) { // returns true for vertical condition
  int count = winningDiskNum - 1;
  int winningCount = 0;
  int const j = column; // column number never changes because we're only checking the row

  if (row + winningDiskNum - 1 > this->row) {
    return false;
  }

  while (count >= 0) { // sliding window algorithm
    for (int i = row + count; i >= column; --i) { // actual sliding window
      if (i >= 0 && i <= this->column) {
        if (matrix[i][j] == input) {
          ++winningCount;
        }
      }
    }

    if (winningCount == winningDiskNum) { // returns true if winning disk number is met
      return true;
    }
    else {
      winningCount = 0;
    }

    --count;
  }

  return false;
}

bool ConnectM::checkForDraw() { // checks for a draw
  if (totalInputs == drawCondition) { return true; }

  return false;
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

int ConnectM::returnCell(int row, int column) {
  if (row >= 0 && row <= this->row) {
    throw std::runtime_error("ACCESSING ROW OUT OF BOUNDS");
  }

  if (column >= 0 && column <= this->column) {
    throw std::runtime_error("ACCESSING COLUMN OUT OF BOUNDS");
  }

  return matrix[row][column];
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