// coding challenge: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/

class Solution {
public:
vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {

		vector<vector<int>> vectorOfPairs;

	for(int a=1; a <= 1000; a++) // do not start with 0 index
	{
		for(int b=1; b <= 1000; b++){ // do not start with 0 index

			int result = customfunction.f(a,b);

			if(result > z) {
				break;
			}

			if(result == z)
			{

				vector<int> pair;
				pair.push_back(a);
				pair.push_back(b);

			vectorOfPairs.push_back(pair);

			break;
			}

		}

	}

	return vectorOfPairs;

	}
};
