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
    int maximumCount(vector<int>& nums) {
		int nEven = 0, nOdd = 0;
		for(int num : nums) 
			if(num > 0) nOdd++;
			else if(num < 0) nEven++;
		return max(nOdd, nEven);
    }
};