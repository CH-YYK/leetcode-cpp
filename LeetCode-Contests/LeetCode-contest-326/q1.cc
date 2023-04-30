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
    int countDigits(int num) {
        // d in num : num % d == 0
        int tmp = num;
        int ans = 0;
        while(num) {
        	if(tmp % (num % 10) == 0)
        		ans++;
        	num /= 10;
        }
        return ans;
    }
};