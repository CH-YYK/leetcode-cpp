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
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
    	// time : O(n + max(nums) * log(max(nums)))
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num : nums) {
            occured[num] = true;
        }
        int ans = 0;       
        for (int i = 1; i <= maxVal; i++) { // factors
            int subGcd = 0;
            for (int j = i; j <= maxVal; j += i) { // multipliers
                if (occured[j]) { // if multiplier in `nums`
                    if (subGcd == 0) {
                        subGcd = j;
                    } else { // compute the GCD of all multipliers of i
                        subGcd = __gcd(subGcd, j);
                    }
                    if (subGcd == i) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};