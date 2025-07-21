// coding challenge: https://leetcode.com/problems/lru-cache/

// note: logic seems to work, but exceeds time limit

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class LRUCache {
private:
	int cacheCapacity;
	int calls = 0;
	int LRU;
	std::vector<int> keyVec;
	std::vector<int> valueVec;
	std::vector<int> usageVec;

public:
	/* Initialize the LRU cache with positive size capacity */
	LRUCache(int capacity) {
		/* store size of cache */
		cacheCapacity = capacity; 
		/* initialize cache with -1 */
		for(int i = 0; i < capacity; i++) {
			valueVec.push_back(-1);
			keyVec.push_back(-1);
			usageVec.push_back(-1);
		}
	}

	/* Return the value of the key if the key exists, otherwise return -1 */
	int get(int key) {
		calls++;
		for(int ele = 0; ele < cacheCapacity; ele++) {
			if(key == keyVec[ele]) {
			usageVec[ele] = calls;
			return valueVec[ele];
			}
		}
		return -1;
	}

	void put(int key, int value) {
		calls++;

		/* case 1: Update the value of the key if the key exists */
		for(int ele = 0; ele < cacheCapacity; ele++) {

			if(keyVec[ele] == key) {
				valueVec[ele] = value;
				usageVec[ele] = calls;
				return;
			} 
		}


		/* case 2: Add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key. */
		LRU = std::min_element(usageVec.begin(),usageVec.end()) - usageVec.begin();
		keyVec[LRU] = key;
		valueVec[LRU] = value;
		usageVec[LRU] = calls;
	}

};
