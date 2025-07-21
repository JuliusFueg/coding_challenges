// coding challenge: https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {

        int numsSize = nums.size();
        
        /* handling of edge cases */ 
        if (numsSize == 1 ){
            return nums[0];
        }                
        if (numsSize == 2 ){
            return max(nums[0],nums[1]);
        }
        
        /* front */
        int evenFront = 0, unevenFront=0;
        for(int h = 0; h < numsSize-1; h++){
            if(h % 2 == 0) {
                evenFront = max(unevenFront, evenFront+nums[h]);
            }else{
                unevenFront = max(evenFront, unevenFront+nums[h]);
            }
        }

        /* back */
        int evenBack = 0, unevenBack = 0;
        for(int h = numsSize-1; h > 0; h--){
            if(h % 2 == 0) {
                evenBack = max(unevenBack, evenBack+nums[h]);
            }else{
                unevenBack = max(evenBack, unevenBack+nums[h]);
            }
        }

        return max(max(evenFront, unevenFront), max(evenBack, unevenBack));

    }
};
