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
    long long maxPower(vector<int>& stations, int r, int k) {
        // the pattern: maximum-minimum -> binary search the "minimum"
        // the subproblem is: 
        //  "To make every city > power m, "
        //  "how many additional power stations we'll need to make"
        long long l = 0, h = 1e11;
        while(l < h) {
        	long long m = (l + h + 1) / 2;
        	long long cnt = getMinStations(stations, r, m);
        	if(cnt <= k)  // increase m to increase extra power
        		l = m;
        	else h = m - 1;
        }
        return l;
    }
private:
	long long getMinStations(vector<int>& nums, int range, long long p) {
		// For a city i, it's power is from [i-r, i+r]. 
        // 	Put the station at (i+r) to have more impact on non-visited cities
		long long leftsum = 0, sum = 0;
		int l = 0, m = 0;
		long long ans = 0;
		
		// <i, amount>
		queue<pair<int,int>> q;

		for(int r = 0; r < nums.size(); ++r) {
			sum += nums[r];
			if(r - l > 2*range) {
				if(!q.empty() && l == q.front().first) {
					sum -= q.front().second;
					q.pop();
				}
				sum -= nums[l++];
			}
			if(r - m > range) m++;
			if(r - m == range && sum < p) {
				ans += p - sum;
				q.emplace(r, p - sum);
				sum = p;
			}
		}
		while(l < m) {
			if(!q.empty() && l == q.front().first) {
				sum -= q.front().second;
				q.pop();
			}
			sum -= nums[l++];
		}
		if(sum < p) ans += p - sum;
		return ans;
	}
};