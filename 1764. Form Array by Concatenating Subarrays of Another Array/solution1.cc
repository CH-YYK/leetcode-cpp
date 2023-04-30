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

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
    	// O(N^2) brute force
    	// KMP can make it to O(N+M)
  		return canChoose(groups, nums, 0, 0);
    }
private:
	bool canChoose(vector<vector<int>>& groups, vector<int>& nums, int i, int j) {
		if(j == nums.size())
			return i == groups.size();
		if(i == groups.size())
			return true;

		for(;j < nums.size(); ++j) {
			if(nums[j] != groups[i][0])
				continue;
			int p1 = 0, p2 = j;
			while(p2 < nums.size() && 
				p1 < groups[i].size() && 
				nums[p2] == groups[i][p1]) {
					p1++, p2++;
			}
			if(p1 == groups[i].size()) {
				j = p2, i++;
				break;
			}
		}
		return canChoose(groups, nums, i, j);
	}
};

int main() {
    
}
