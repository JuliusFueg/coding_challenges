// coding challenge: https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
    std::string finalString;

    if (numRows == 1) {
        return s;
    }

    // loop over rows
    for(int r = 0; r < numRows; r++){

        // loop over string
        for (std::string::size_type i = 0; i < s.size(); i++) {

                i = i+r; // set starting point of each row
                if(i < s.size()){
                    finalString.push_back(s[i]);
                }

                // values in diagonals for rows other than first and last
                if(r>0 && r<numRows-1){
                    int tmp = i;
                    i = i + numRows-r-1 + numRows-r-1;
                    // end of column end of diagonal-row
                    if(i < s.size()){
                        finalString.push_back(s[i]);
                    }
                    i = tmp;

                }

                // reseting to start of next column
                i = i+ numRows-r-1 + numRows-2;
                // end of column + end of diagonal

            }
        }

        return finalString;
    }
};
