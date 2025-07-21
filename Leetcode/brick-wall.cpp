// coding challenge: https://leetcode.com/problems/brick-wall/description/

// note: only solves initial test cases, but is too complex and runs into runtime error for other test cases

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        /* wall info */
        int heightWall = wall.size();
        int lenWall = accumulate(wall[0].begin(),wall[0].end(),0);
        
        /* edge counter variables */
        unordered_map<int, int> edgeCntr;
        //vector<int> edgeCntr(lenWall-1, 0); //-> doesn't work
        //int edgeCntr[lenWall-1] = {0};
        int maxEdges = 0;

        /* iterating over rows, then edges */
        for(int row = 0; row < heightWall; row++)
        {
            int nRowElements = wall[row].size();
            int curEdge = 0;
            
            for(int n = 0; n < nRowElements - 1; n++) /* leave out ending edge of wall */
            {
                curEdge = curEdge + wall[row][n]; /* leaving out starting edge of wall */
                edgeCntr[curEdge-1]++;
                maxEdges = max(edgeCntr[curEdge-1], maxEdges);
            }
        }

        int nBrickCrossings = heightWall - maxEdges; /* converting crossed edges to crossed bricks */
        return nBrickCrossings;
    }
};
