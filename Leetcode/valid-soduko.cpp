// coding challenge: https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int r, c, j, i;
        vector<char> row, &column = row, &subBox = row;

        /* 1. rule: each rows contain 1-9 without repetition */
        for (r = 0; r < 9; r++) {
            for (c = 0; c < 9; c++) {
                if (board[r][c] != '.') { /* if element is a number */
                    /* check if number is duplicate */
                    if (std::find(row.begin(), row.end(), board[r][c]) != row.end()) {
                        return 0;
                    } else {
                        /* else push it into the vector */
                        row.push_back(board[r][c]);
                    }
                }
            }
            row.clear();
        }

        /* 2. rule each columns contain 1-9 */
        for (c = 0; c < 9; c++) {
            for (r = 0; r < 9; r++) {
                if (board[r][c] != '.') { /* if element is a number */
                    /* check if number is duplicate */
                    if (std::find(column.begin(), column.end(), board[r][c]) !=
                        column.end()) {
                        return 0;
                    } else {
                        /* else push it into the vector */
                        column.push_back(board[r][c]);
                    }
                }
            }
            column.clear();
        }

        /* 3. rule each of the 3x3 boxes contains 1-9 without repetition */
        /* within sub box */
        for (j = 0; j < 3; j++) { // incrementing horizontal 3x3 boxes
            for (i = 0; i < 3; i++) { // incrementing vertical 3x3 boxes
                for (r = i * 3; r < (i + 1) * 3; r++) {
                    for (c = j * 3; c < (j + 1) * 3; c++) {
                        if (board[r][c] != '.') { /* if element is a number */
                            /* check if number is duplicate */
                            if (std::find(subBox.begin(), subBox.end(), board[r][c]) !=
                                subBox.end()) {
                                return 0;
                            } else {
                                /* else push it into the vector */
                                subBox.push_back(board[r][c]);
                            }
                        }
                    }
                }
                subBox.clear();
            }
        } 

        /* if all rules were passed */
        return 1;
    
    }
};
