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

int main() {
    
}

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
    	int n = nums.size();
  		sort(nums.begin(), nums.end(), greater<int>());
  		unordered_map<long,int> mp;
  		vector<int> dp(n, 1);
  		mp[nums[0]] = 0;
  		int res = 0;

  		for(int i = 1; i < n; ++i) {
  			long tmp = (long)nums[i] * nums[i];
  			if(mp.count(tmp)) {
  				dp[i] = dp[mp[tmp]] + 1;
  			}
  			mp[nums[i]] = i;
  			res = max(res, dp[i]);
  		}
  		return res == 1 ? -1 : res;
    }
};