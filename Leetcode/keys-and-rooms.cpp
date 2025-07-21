// coding challenge: https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(const vector<vector<int>>& rooms) {

        /* initialize variables */
        int nRooms = rooms.size();
        int roomCtr = 0;

        /* create vector to store all keys to check */
        vector<int> keys;
        keys.insert(keys.begin(),0); /* adding first room */

        /* create vector to store all keys that were checked */
        vector<int> usedKeys;

        /* check rooms for keys as long as there are keys to use */
        while(keys.size() != 0){
            int curRoom = keys[0]; /* use key that is in first element */

            /* check if key was already used */
            if(std::find(usedKeys.begin(), usedKeys.end(), curRoom) != usedKeys.end()) {
                keys.erase(keys.begin()); /* erase key because room was already visited */
            } else {
                usedKeys.push_back(curRoom);
                keys.erase(keys.begin()); /* erase currently visited room */
                roomCtr++; /* increment counter for currently visited room */
                keys.insert(keys.end(), rooms[curRoom].begin(), rooms[curRoom].end()); /* add found keys */
            }
        }

        /* check if all rooms could be visited */
        return nRooms == roomCtr;
    }
};
