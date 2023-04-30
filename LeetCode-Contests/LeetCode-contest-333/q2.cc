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
    int minOperations(int n) {
        // n -> 10101010; .eg
        vector<int> digits(32, 0);
        for(int i = 0; i < 32; ++i) {
        	if((1 << i) & n)
        		digits[i] = 1;
        }
        // find consecutive 1s 
        int ans = 0;
        for(int i = 0; i < 32; ++i) {
        	if(digits[i] == 0) continue;
        	int j = i;
        	int cnt = 0;
        	while(j < 32 && digits[j] == 1)
        		cnt++, j++;
        	ans += 1;
        	if(cnt > 1)
        		digits[j] = 1;
            i = j - 1;
        }
        return ans;
    }
};