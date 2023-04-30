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
    vector<int> shuffle(vector<int>& nums, int n) {
    	int i = 0, j = n;
    	while(i < n) {
    		nums[i] *= 10000;    		
    		nums[i++] += nums[j++];
    	}
        j = 2 * n - 1, i = n - 1;
    	while(j > 0) {
    		nums[j] = nums[i] % 10000;
    		nums[j - 1] = nums[i] / 10000;
    		j -= 2;
    		i--;
    	}
    	return nums;
    }
};