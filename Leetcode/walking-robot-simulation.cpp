// coding challenge: https://leetcode.com/problems/walking-robot-simulation/

class Solution {
public:

    int unwrap(int angleDegree){
        if (angleDegree < -180){
            while (angleDegree < -180){angleDegree += 360;}
        }else if (angleDegree > 180){
            while (angleDegree > 180){angleDegree -= 360;}
        }

        return angleDegree;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0; /* initial position */
        int orientation = 0; /* 0 = up, +/- 180 =  down, -90 = left, 90 = right */
        int maxDist = 0;
        int tmpX, tmpY;

        set<pair<int,int>> obst;
        for(auto obstacle:obstacles){
            obst.insert({obstacle[0],obstacle[1]});
        }

        for(int c=0; c<commands.size(); c++)
        {
            if(commands[c] == -1){
                orientation = unwrap(orientation + 90); /* update orientation, right rotation = +90 */
            }
            else if(commands[c] == -2)
            {
                orientation = unwrap(orientation - 90); /* update orientation, left rotation = -90 */
            }
            else
            {
                /* update position */
                tmpX=x;
                tmpY=y;

                for(int d=0; d<commands[c]; d++){
                    if(orientation == 0) /* up */
                    {
                        tmpY++;
                    }
                    else if(orientation == 180 || orientation == -180) /* down */
                    {
                        tmpY--;
                    }
                    else if(orientation == -90) /* left */
                    {
                        tmpX--;
                    }
                    else if(orientation == 90) /* right */
                    {
                        tmpX++;
                    }

                    if(obst.find({tmpX,tmpY})==obst.end())
                    {
                        x=tmpX;
                        y=tmpY;
                    }
                    else{
                        break;
                    }
                }

                /* update max distance */
                maxDist = (maxDist < pow(x,2) + pow(y,2)) ? (pow(x,2) + pow(y,2)) : maxDist;
            }
        }

        return maxDist;
    }
};  
