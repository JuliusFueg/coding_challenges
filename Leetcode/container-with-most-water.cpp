// coding challenge: https://leetcode.com/problems/container-with-most-water/description/

Solution 1:
===========
class Solution {
public:
	int maxArea(std::vector<int>& height) {
    	int max_area = 0;
	    int n = height.size();

    for (int i = 0; i < n; ++i) {
        	// Skip if there is no chance of finding a larger area
        	if (height[i] * (n - 1 - i) <= max_area) {
            	continue;
        	}

	        for (int j = i + 1; j < n; ++j) {
            	int area = std::min(height[i], height[j]) * (j - i);
            	max_area = std::max(max_area, area);
        	}
   		}
    	return max_area;
	}
};

Solution 2:
===========
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int smallestHeight = 0;
        int localMaxWater = 0;
        int globalMaxWater = 0;

        while (left < right) {
            smallestHeight = (height[left] < height[right]) ? height[left] : height[right];
            localMaxWater = smallestHeight * (right - left);
            globalMaxWater = (globalMaxWater > localMaxWater) ? globalMaxWater : localMaxWater;

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return globalMaxWater;
    }
};
