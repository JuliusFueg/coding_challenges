// coding challenge: https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    int minMutation(string startMutation, string endMutation, vector<string>& bank) {
        // possible genes
        char genes[] = {'A', 'T', 'C', 'G'};
        char curGene;
        int mutationCntr=0, size;
        string curMutation;

        // queue with all mutations to be checked
        queue<string> checkMutations;
        checkMutations.emplace(startMutation);

        while(!checkMutations.empty()){
            size = checkMutations.size();
            for(int i=0; i < size; i++){ // loop over all mutations that need checking
                curMutation = checkMutations.front();
                checkMutations.pop();
                if(curMutation == endMutation){
                    return mutationCntr;
                }

                for(int j=0; j < 8; j++){ // loop over all 8 genes of mutation
                    curGene = curMutation[j];
                    for(int k=0; k < 4; k++){ // loop over all four possible genes 
                        curMutation[j] = genes[k];
                        if((std::find(bank.begin(), bank.end(), curMutation) != bank.end()) == true ){
                            bank.erase(std::remove(bank.begin(), bank.end(), curMutation), bank.end());
                            checkMutations.emplace(curMutation);
                        }
                    }
                    curMutation[j] = curGene;
                }
            }
            mutationCntr++;
        }

        return -1;
    }
};
