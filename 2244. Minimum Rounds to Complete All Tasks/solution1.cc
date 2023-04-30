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
    int minimumRounds(vector<int>& tasks) {
		unordered_map<int,int> mp;
		for(int t : tasks)
			mp[t]++;
		int ans = 0;
		for(auto [k,v] : mp) {
			if(v == 1)
				return -1;
			int num = v / 3;
			int res = v % 3;
			if(res == 0)
				ans += num;
			else 
				ans += num + 1;
		}
		return ans;
    }
};