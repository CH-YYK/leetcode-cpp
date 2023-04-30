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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
  		// fun(nums, i, limit) = 
  		// max(find(nums, i-1, limit), find(nums, i-1, limit-nums[i]))
  		// sort and pop_out maximum
    	sort(nums.begin(), nums.end());

    	vector<int> presum(nums.size() + 1, 0);
    	for(int i = 0; i < nums.size(); ++i)
    		presum[i + 1] = presum[i] + nums[i];

    	vector<int> answers;
    	for(int query : queries) {
    		auto it = upper_bound(presum.begin(), presum.end(), query);
    		answers.push_back(it - presum.begin() - 1);
    	}
    	return answers;
    }
};