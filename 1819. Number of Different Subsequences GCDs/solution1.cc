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
    	// 
    	// assume that we had an array whose elements are factors of nums
    	// if we collect all numbers that have factor[i], and if factor[i]
    	// happen to be the GCD of them, we should add 1 to our counter
    	// 
    	// there must be: GCD >= factor[i]
    	// time complexity: O(Sqrt(n) * n)
    	int maxNum = *max_element(nums.begin(), nums.end());
    	vector<int> factors(maxNum + 1, 0);

    	for(int num : nums) {
    		for(int i = 1; i * i <= num; ++i) {
    			if(num % i != 0) continue;
    			int factor1 = i;
    			int factor2 = num / i;

    			factors[factor1] = factors[factor1] ? __gcd(num, factors[factor1]) : num;
    			factors[factor2] = factors[factor2] ? __gcd(num, factors[factor2]) : num;
    		}
    	}

    	int ans = 0;
    	for(int i = 1; i <= maxNum; ++i)
    		ans += factors[i] == i;
    	return ans;
    }
};