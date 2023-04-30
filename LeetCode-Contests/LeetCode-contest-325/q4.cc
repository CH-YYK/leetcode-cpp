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

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        K = k;
        Sum = accumulate(nums.begin(), nums.end(), 0l);
        memo = vector<vector<int>>(nums.size(), vector<int>(K + 2, -1));
        return dfs(nums, 0, 0l);
    }
private:
	int K;
	long Sum;
	vector<vector<int>> memo;
	// number of ways to ditribute nums[i:], with currnt sum
	int dfs(vector<int>& nums, int i, long sum) {
		if(sum >= K && Sum - sum >= K) {
			return 1 << (nums.size() - i);
		}
		if(Sum - sum < K) return 0;
		if(i == nums.size()) return sum >= K;
		if(memo[i][sum] > sum) 

		return memo[i][] dfs(nums, i + 1, sum + nums[i]) +
			dfs(nums, i + 1, sum);
	}
};