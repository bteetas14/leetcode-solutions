class Solution {
public:
    bool isValid(int row, int col, char c, vector<vector<char>>& board){
        
        // check row
        for(int j=0;j<9;j++){
            if(board[row][j] == c) return false;
        }

        // check col
        for(int i=0;i<9;i++){
            if(board[i][col] == c) return false;
        }

        // check box
        int boxRowStart = 3 * (row / 3);
        int boxColStart = 3 * (col / 3);

        // Check the 3x3 sub-box for duplicate character
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // If character found in sub-box, not valid
                if (board[boxRowStart + i][boxColStart + j] == c)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(i, j, c, board)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false; // no valid number fits
                }
            }
        }
        return true; // board completely filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};