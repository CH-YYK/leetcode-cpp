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
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq; // <-processingtime, -idx>

        for(int i = 0; i < tasks.size(); ++i)
        	tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());

		long curr = 0;
		int i = 0;
		int n = tasks.size();
		while(ans.size() < n) {
			if(i < n && pq.empty() && curr < tasks[i][0])
				curr = tasks[i][0];
			while(i < n && tasks[i][0] <= curr) 
				pq.emplace(-tasks[i][1], -tasks[i++][2]);	

			if(pq.empty()) break;

			auto [nt, nid] = pq.top();
			pq.pop();
			curr -= nt;
			ans.push_back(-nid);
		}
		return ans;
    }
};