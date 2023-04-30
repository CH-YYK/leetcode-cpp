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

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
  		// O(N)
  		// left >= right
  		// both left and right are non-decreasing subarray
  		bool pivot = false;

  		for(int i = 1; i < nums.size(); ++i) {
  			if(nums[i] < nums[i - 1]) {
  				if(pivot) return false;
  				else if(nums[i] > nums[0])
                    return false;
                else pivot = true;
  			} else {
  				if(pivot && nums[i] > nums[0])
  					return false;
  			}
  		}
  		return true;
    }
};

int main() {
    
}
