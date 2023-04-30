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
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int num : gifts)
            pq.push(num);
        while(k--) {
        	int curr = pq.top();
        	pq.pop();
        	pq.push(sqrt(curr));
        }
        long long ans = 0;
        while(!pq.empty()) {
        	ans += pq.top();
        	pq.pop();
        }
        return ans;
    }
};