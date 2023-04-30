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
    int waysToMakeFair(vector<int>& nums) {
  		int oddsum = 0, evensum = 0;      
  		for(int i = 0; i < nums.size(); ++i) {
  			if(i & 1) oddsum += nums[i];
  			else evensum += nums[i];
  		}
  		int oddsum2 = 0, evensum2 = 0;
        int ans = 0;
  		for(int i = 0; i < nums.size(); ++i) {
  			// after removing an index, for the rest of array
  			//  the evenSum -> oddSum
  			// 	the oddSum -> evenSum
  			int newOdd = oddsum2 + evensum - evensum2;
  			int newEven = evensum2 + oddsum - oddsum2;
  			if(i & 1) {
  				// nums[i] is removed from the previous oddSum
  				if(newEven - nums[i] == newOdd)
  					ans++;
  				oddsum2 += nums[i];
  			} else {
  				// nums[i] is removed from the previous evenSum
  				if(newOdd - nums[i] == newEven)
  					ans++;
  				evensum2 += nums[i];
  			}
  		}
  		return ans;
    }
};