// coding challenge: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        /* important: speed is in km/min */
        int monstersKilledCounter = 0;
        int amountOfMonsters = dist.size();
        vector<int> timeOfArrival(amountOfMonsters); /* time in minutes */

        /* calculate time of arrival for each monster */
        for (int t=0; t < dist.size(); t++){
            timeOfArrival[t] = ceil(float(dist[t]) / float(speed[t]) ); /* distance / speed */
        }

        /* sorting monsters per minute from close to far */
        sort(timeOfArrival.begin(), timeOfArrival.end());  

        /* checking how many monsters we can kill */
        int time = 1;
        for(int m = 0; m < amountOfMonsters; m++){
            if(time > timeOfArrival[m]){  /* monsters are sorted per minute, gun needs 1 minute to charge. If monster time is bigger than recharge time we loose */
                return m;
            }
            time++;
        }

        /* in case we can kill all monsters in time*/
        return amountOfMonsters;  
    }
};
