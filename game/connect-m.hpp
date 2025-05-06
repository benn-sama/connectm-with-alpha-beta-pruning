#ifndef CONNECT_M_HPP
#define CONNECT_M_HPP

#include <iostream>

class ConnectM {
private:
    int **matrix;
    int row = 0;
    int column = 0;
    int *selectedColumn; // keeps track if columns are full or not
    int winningDiskNum = 0;
    int totalInputs = 0;
    int drawCondition;

public:
    ConnectM(int row, int winningDiskNum);
    void initialize();
    bool play(int input, int column); // Use player parameter
    void displayCurrentGame();
    bool isColumnFull(int column);

    bool checkForWinner(int input, int column);
    bool leftDiagonal(int row, int column, int input);
    bool rightDiagonal(int row, int column, int input);
    bool horizontal(int row, int column, int input);
    bool vertical(int row, int column, int input);

    bool checkForDraw();
    int* getSelectedColumn() const { return selectedColumn; }
    int** getMatrix() const { return matrix; }
    int getBoardSize() const { return row; }
    int getColumnCount() const { return column; }
    
    int** copyGame();
    ConnectM(const ConnectM& other); // Copy constructor
    ~ConnectM();
};

#endif