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

bool ConnectM::play(int input, int column) { // inputs the player's move
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

  if (this->leftDiagonal(row, column, input)) {
    return true;
  }

  if (this->rightDiagonal(row, column, input)) {
    return true;
  }

  if (this->vertical(row, column, input)) {
    return true;
  }

  if (this->leftHorizontal(row, column, input)) {
    return true;
  }

  if (this->rightHorizontal(row, column, input)) {
    return true;
  }

  return false;
}

bool ConnectM::leftDiagonal(int row, int column, int input) {// left diagonal winner
  int j = column;
  int inputCount = 0;

  for (int i = row; i < this->row && j < this->column; ++i) {
    if (input == matrix[i][j]) {
      ++inputCount;

      if (inputCount == winningDiskNum) {
       return true;
      }
    }
    else {
      break;
    }
    --j;
  }

  return false;
}

bool ConnectM::rightDiagonal(int row, int column, int input) { // right diagonal winner
  int inputCount = 0;
  int j = column;

  for (int i = row; i < this->row && j < this->column; ++i) {
    if (input == matrix[i][j]) {
      ++inputCount;

      if (inputCount == winningDiskNum) {
        return true;
      }
    }
    else {
      break;
    }
    ++j;
  }

  return false;
}

bool ConnectM::vertical(int row, int column, int input) { // vertical check winner
  int j = column;
  int inputCount = 0;

  for (int i = row; i < this->row; ++i) {
    if (input == matrix[i][j]) {
      ++inputCount;
      if (inputCount == winningDiskNum) {
        return true;
      }
    }
    else {
      break;
    }
  }

  return false;
}

bool ConnectM::leftHorizontal(int row, int column, int input) { // left most horizontal winner
  int i = row;
  int inputCount = 0;

  for (int j = column; j >= 0; --j) {
    if (matrix[i][j] == input) {
      ++inputCount;

      if (inputCount == winningDiskNum) {
        return true;
      }
    }
    else {
      break;
    }
  }

  return false;
}

bool ConnectM::rightHorizontal(int row, int column, int input) { // right most horizontal winner
  int i = row;
  int inputCount = 0;

  for (int j = column; j < this->column; ++j) {
    if (matrix[i][j] == input) {
      ++inputCount;
      
      if (inputCount == winningDiskNum) {
        return true;
      }
    }
    else {
      break;
    }
  }

  return false;
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