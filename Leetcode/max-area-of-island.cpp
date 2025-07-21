// coding challenge: https://leetcode.com/problems/max-area-of-island/

class Solution {
public:

    int searchLand(vector<vector<int>>& grid,int numRows,int numColumns,int row,int column){
        /* look for land, check if neighboured field is outside of grid or is water */
        if(row<0 || column<0 || row>=numRows || column>=numColumns || grid[row][column]==0){
            return 0;
        }

        /* if land was found, set it to 0 in order to not find it again */
        grid[row][column] = 0;
        
        return searchLand(grid, numRows, numColumns, row+1, column) /* down */
              +searchLand(grid, numRows, numColumns, row-1, column) /* up */
              +searchLand(grid, numRows, numColumns, row, column+1) /* right */
              +searchLand(grid, numRows, numColumns, row, column-1) /* left */
              + 1; /* increase counter for found land */
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxIsland = 0;
        int numColumns = grid[0].size();
        int numRows = grid.size();

        /* go through grid row by row */
        for(int row=0; row < numRows; row++)
        {
            for(int column=0; column < numColumns; column++)
            {
                if(grid[row][column] == 1)
                {
                    maxIsland = std::max(maxIsland, searchLand(grid, numRows, numColumns, row, column));
                }
            }
        }

        return maxIsland;
    }
};
