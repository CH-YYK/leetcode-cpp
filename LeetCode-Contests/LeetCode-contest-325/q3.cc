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
    int maximumTastiness(vector<int>& price, int k) {
        // at most k
        // binary search
        // tasteness rely min(price[i] - price[i-1])
        int ans = 0;
        sort(price.begin(), price.end());
        int l = 0, r = price.back() - price.front();
        while(l < r) {
        	int m = (l + r + 1) / 2;
        	int num = 1;
        	int candy = price[0];
        	for(int i = 1; i < price.size(); ++i)
        		if(price[i] - candy >= m) {
                    candy = price[i];
                    // cout << price[i] << endl;
        			num++;
                }
        	// more tasteness -> less candies
            // cout << l <<' ' <<  m << ' ' << r  << " num: " << num << endl;;
        	if(num >= k) { // increase taste
        		l = m;
        	} else {
        		r = m - 1;
        	}
        }
        return l;
    }
};
