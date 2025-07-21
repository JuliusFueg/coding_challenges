// coding challenge: https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string &secret, string &guess) {

        /* declare variables */
        int bulls = 0;
        int cows = 0;

        /* check for bulls */
        for(int i=0; i < secret.size(); ){
            if( secret[i] == guess[i] ){
                secret.erase(i,1);
                guess.erase(i,1);
                bulls++;
            }else{
                i++;
            }
        }

        /* check for cows */
        for(int i=0; i < secret.size(); i++){
            for(int j=0; j< guess.size(); j++){
                if( secret[i] == guess[j] ){
                    guess.erase(j,1);
                    cows++;
                    break;
                }
            }
        }

        /* return result */
        return to_string(bulls) + 'A' + to_string(cows) + 'B'; 
    }
};
