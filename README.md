# Sudoku Game in C++

## 📌 Overview
This project is a **console-based Sudoku game** written in C++ using an **object-oriented design** and the **STL**.  
It allows the player to:
- Load a Sudoku puzzle (hardcoded or from file).
- Display the Sudoku board in a neat ASCII format.
- Enter moves with validation for rows, columns, and 3×3 subgrids.
- Automatically solve the puzzle using backtracking.
- Save the current puzzle to a file. *(optional)*
- Generate random Sudoku puzzles of varying difficulty. *(optional)*

The project cleanly separates **board logic**, **solver**, and **user interface**, making it easy to extend (e.g., add a GUI in the future).

---

## 🛠️ Features
- 9×9 Sudoku grid stored as `std::vector<std::vector<int>>`.
- Input validation:
  - Rows/columns must be in range `1–9`.
  - Values must be `1–9`.
  - Duplicate checks for row, column, and 3×3 subgrid.
- Backtracking algorithm to solve puzzles.
- Clear console menu for user interaction.
- File I/O for saving/loading puzzles.
- Puzzle generation and advanced solving strategies.

---

## 📂 Project Structure
├── SudokuBoard.hpp # Board representation & basic I/O

├── SudokuBoard.cpp

├── SudokuSolver.hpp # Backtracking solver

├── SudokuSolver.cpp

├── SudokuGame.hpp # Console interface / game loop

├── SudokuGame.cpp

├── main.cpp # Entry point

└── CMakeLists.txt # Build instructions

