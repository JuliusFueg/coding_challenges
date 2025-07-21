// coding challenge: https://leetcode.com/problems/gas-station/

// note: logic works but hits time limit

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int amountGasStations = gas.size();

        /* check if there is any solution */
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;

        /* brute force approach */
        for(int startGasStation=0; startGasStation < amountGasStations; startGasStation++){ /* iterate over all possible starting points*/
            int gasTank = 0; /* always start with empty gas tank */
            int wrapAroundIndex = startGasStation; /* variable to shift starting point and wrap around */
            
            for(int iterateGasStation = 0; iterateGasStation < amountGasStations; iterateGasStation++){ /* iterate over all gas stations from starting point */
                gasTank = gasTank + gas[(wrapAroundIndex + iterateGasStation) % amountGasStations] - cost[(wrapAroundIndex + iterateGasStation) % amountGasStations]; 

                if(gasTank < 0) { /* if gas is negative then next gas station can't be reached */
                    break;
                }

            }
            
            if(gasTank >= 0) { /* if gas tank is fully after visiting all gas stations, then the according start gas station is the answer*/
                return startGasStation;
            }

        }
        return -1;
    }
};
