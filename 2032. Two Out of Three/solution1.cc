// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
 public:
  vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                            vector<int>& nums3) {
  	vector<int> ans;
  	unordered_map<int,int> mp;
  	for(int num : nums1)
  		mp[num] |= 1;
  	for(int num : nums2)
  		mp[num] |= 2;
  	for(int num : nums3)
  		mp[num] |= 4;
  	for(auto& [k,v] : mp) {
  		if(v & (v - 1))
  			ans.push_back(k);
  	}
    return ans;
  }
};