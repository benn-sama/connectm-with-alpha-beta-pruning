# ConnectM Game

[Project 1 Computer Game.pdf](https://github.com/user-attachments/files/18935021/Project.1.Computer.Game.pdf)

## Overview
ConnectM is a strategic game played on an M×M grid, where **M** determines the board size. In this game, a human player competes against the computer. The computer leverages an alpha-beta pruning algorithm that evaluates each move by maximizing the number of potential wins it can create.

## How It Works
- **Game Board:** The board is displayed as an M×M grid.
- **Player vs. Computer:** The human makes moves against a computer opponent.
- **Alpha-Beta Pruning:** The computer's AI uses an alpha-beta pruning algorithm to search for optimal moves. It prioritizes moves that generate the most potential winning configurations.

## Running the Program

### To Run Tests
The tests for this project are located in the `tests` folder. Execute the following command to run all tests:
```sh
make run-test
