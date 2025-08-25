#include"SudokuSolver.hpp"

bool SudokuSolver::solve(SudokuBoard &board) {
    // Loop through all cells to find the first empty
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board.getValue(row, col) == 0) {
                // Try all values
                for (int num = 1; num <= 9; num++) {
                    if (board.setValue(row, col, num)) {
                        if (solve(board)) {
                            return true;  // solved down this path
                        }
                        board.clearValue(row,col);  // backtrack
                    }
                }
                // No number fits here → backtrack
                return false;
            }
        }
    }
    // No empty cells left => solved
    return true;
}
