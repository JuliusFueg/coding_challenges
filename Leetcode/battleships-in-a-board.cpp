//coding challenge:  https://leetcode.com/problems/battleships-in-a-board/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {

        int row, column, i, shipCtr=0;
        
        /* loop over all elements */
        for(row=0; row < board.size(); row++){
            for(column=0; column < board[0].size(); column++){

                /* search for the beginning of a ship */
                if(board[row][column] == 'X'){
                    
                    shipCtr++; /* increase ship counter */
                    //board[row][column] = '.'; /* set element as visited */

                    /* check whether boat is longer horizontally */
                    if(column < board[0].size()){ /* check if current position is the end of the board */
                        for(i=column+1; i<board[0].size(); i++){
                            if(board[row][i] == 'X'){
                                board[row][i] = '.';
                            }else{
                                break;
                            }
                        }
                    }
                
                    /* check whether boat is longer vertically */
                    if(row < board.size()){ /* check if current position is the end of the board */
                        for(i=row+1; i<board.size(); i++){
                            if(board[i][column] == 'X'){
                                board[i][column] = '.';
                            }else{
                                break;
                            }
                        }
                    }
                }
            }
        }

        return shipCtr;
    }
};
