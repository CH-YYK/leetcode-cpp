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
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(int num : nums)
        	pq.push(num);
        while(!pq.empty() && k--) {
        	int curr = pq.top();
        	pq.pop();
        	ans += curr;
        	pq.push((curr + 2) / 3);
        }
        return ans;
    }
};