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
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    	unordered_map<int, unordered_set<int>> mp;
    	for(vector<int>& log : logs) {
    		mp[log[0]].insert(log[1]);
    	}
    	vector<int> answers(k);
    	for(auto& [_,v] : mp) {
    		if((int)v.size() <= k) 
    			answers[v.size() - 1]++;
    	}
    	return answers;
    }
};