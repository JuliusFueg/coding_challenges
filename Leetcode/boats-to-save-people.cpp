// coding challenge: https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    
int numRescueBoats(vector<int>& people, int limit) {

    sort(people.begin(), people.end()); // sorting people from smallest weight to biggest weight

    int minWeight = 0; // starts at beginning of people vector
    int maxWeight = people.size() - 1; // starts at end of people vector
    int nBoats = 0; // counts number of boats

    while(minWeight <= maxWeight)
    {

        // case 1: sum of of person with smallest weight and person with biggest weight is > limit, then the person with biggest weight can fill a boat alone
        // note: a person can not be heavier than the limit
        // current maxWeight is most important, because it dictates whether it needs to fill a boat alone or can take another person with minWeight
        if(people[minWeight] + people[maxWeight] > limit)
        {
            maxWeight--;
        } else { // case 2: if sum of person with smallest weight and person with biggest weight <= limit, then they can fill a boat together
            minWeight++;
            maxWeight--;
        }

        nBoats++;
    }

    return nBoats;

    }

};
