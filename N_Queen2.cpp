#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> result;

bool isValid(vector<string>& board, int row, int col) {
    // Check column upwards
    for (int i = row; i >= 0; i--) {
        if (board[i][col] == 'Q') return false;
    }

    // Check left diagonal upwards
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check right diagonal upwards
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}

void solve(vector<string>& board, int row) {
    if (row == board.size()) {
        result.push_back(board);
        return;
    }
    
    for (int i = 0; i < board.size(); i++) {
        if (isValid(board, row, i)) {
            board[row][i] = 'Q';
            solve(board, row + 1);
            board[row][i] = '.'; // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    result.clear();
    if (n == 0) return {};
    
    vector<string> board(n, string(n, '.')); // Initialize empty board
    solve(board, 0);
    
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (N for N-Queens): ";
    cin >> n;
    
    // Directly call the function and print the result
    for (const auto& solution : solveNQueens(n)) {
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
