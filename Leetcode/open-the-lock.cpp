// coding challenge: https://leetcode.com/problems/open-the-lock/description/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        /* variables */
        int turns = 0;
        queue<string> queue{{"0000"}}; /* store combinations that need checking */
        unordered_set<string> visited{deadends.begin(), deadends.end()}; /* store visited neighbours */

        /* special cases */
        if(target == "0000"){ /* solved */
            return 0;
        }     

        if (visited.count("0000")){
            return -1; /* not solvable */
        }

        /* breadth first search */
        while( !queue.empty() ){
            turns++;

            int queueSize = queue.size();
            for(int n = 0; n < queueSize; n++){
                string code = queue.front();
                queue.pop();

                for(int i = 0; i < 4; ++i){
                    /* save initial code digit */
                    char cache = code[i];
                    
                    /* increase digit by 1 */
                    code[i] = (code[i] == '9') ? '0' : (code[i] + 1);
                    if (code == target){
                        return turns;
                    }
                    if (!visited.count(code)) {
                        queue.push(code);
                        visited.insert(code);
                    }
                    code[i] = cache; /* reset digit */

                    /* decrease digit by 1 */
                    code[i] = (code[i] == '0') ? '9' : (code[i] - 1);
                    if (code == target){
                        return turns;
                    }
                    if (!visited.count(code)) {
                        queue.push(code);
                        visited.insert(code);
                    }
                    code[i] = cache; /* reset digit */

                } /* for */
            } /* for */
        } /* while */

        return -1; /* not solvable */
    }
};
