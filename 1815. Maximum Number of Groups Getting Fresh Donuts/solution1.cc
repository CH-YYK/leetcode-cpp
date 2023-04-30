// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
		// how many subsequences whose sum is multiplier of batchSize         
		// can we find.		
		buckets = vector<int>(batchSize, 0);
		int res = 0;
		for(int num : groups)
			if(num % batchSize == 0)
				res++;
			else if(buckets[batchSize - num % batchSize] > 0) {
				--buckets[batchSize - num % batchSize];
				++res;
			} else
				buckets[num % batchSize]++;
		return res + numWays(buckets, 0);
    }
private:
	vector<int> buckets;
	map<vector<int>, int> memo;
	int numWays(vector<int>& buckets, int sum) {
		// consume 1 from buckets each time and find the maximum number
		// of batches can we have by consuming all buckets
		auto it = memo.find(buckets);
		if(it != memo.end())
			return it->second;
		int res = 0, bz = buckets.size();
        for(int i = 1; i < bz; ++i) {
        	if(buckets[i] == 0) continue;
        	buckets[i]--;        	
        	// if(sum == 0): open a new batch and the current first group will be happy
       		res = max(res, (sum == 0) + numWays(buckets, (bz + sum - i) % bz));        	
        	buckets[i]++;
		}
		return memo[buckets] = res;
	}
};