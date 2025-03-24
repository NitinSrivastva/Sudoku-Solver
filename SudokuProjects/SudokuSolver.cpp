#include <iostream>
#include <vector>
using namespace std;

//Print Board
void printSudoku(vector<vector<int>> sudoku) {
    cout<<("----------Sudoku Solver-------")<<endl;
    int n = sudoku.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

//IS SAFE FNX
bool isSafe(vector<vector<int>> sudoku, int row, int col, int digit) {
//Vertical
for(int i = 0; i <= 8; i++) {
    if(sudoku[i][col] == digit) {
        return false;
    }
}

//Horizontal
for(int j = 0; j <= 8; j++) {
    if(sudoku[row][j] == digit) {
        return false;
    }
}

//3*3 Grid
int sRow = (row/3)*3;
int sCol = (col/3)*3;

//Loop On Grid Check
for(int i = sRow; i <= sRow+2; i++) {
    for(int j = sCol; j <= sCol+2; j++) {
        if(sudoku[i][j] == digit) {
            return false;
        }
    }
}

return true;
}

//Sudoku Solver
bool sudokuSolver(vector<vector<int>> &sudoku, int row, int col) {
if(row == 9) { //BASE CASE
    printSudoku(sudoku);
    return true;
}

int nextRow = row;
int nextCol = col+1;

if(col+1 == 9) {//Line BY Line Change(IMP)
    nextCol = 0;
    nextRow= row+1;
}

if(sudoku[row][col] != 0) {
    return sudokuSolver(sudoku, nextRow, nextCol);
}

for(int digit = 1; digit <= 9; digit++) {
    if(isSafe(sudoku, row, col, digit)) {
        sudoku[row][col] = digit;
        if(sudokuSolver(sudoku, nextRow, nextCol)) {//Solution Exist
            return true;
        }
        sudoku[row][col] = 0; //BackTracking
    }
}

return false;
}

int main() {
   vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout<<sudokuSolver(sudoku, 0, 0);
    return 0;
}