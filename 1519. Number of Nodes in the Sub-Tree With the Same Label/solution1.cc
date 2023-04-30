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
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		graph = vector<vector<int>>(n);
		for(vector<int>& edge : edges) {
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		cnts = vector<int>(n, 0);
		dfs(labels, 0);
		return cnts;
    }
private:
	vector<vector<int>> graph;
	vector<int> cnts;
	vector<int> dfs(string& labels, int curr) {
        cnts[curr] = 1;
		vector<int> freq(26, 0);
		for(int nxt : graph[curr]) {
            if(cnts[nxt] != 0) continue;
			vector<int> nexts = dfs(labels, nxt);
			for(int i = 0; i < 26; ++i) {
				if(i == labels[curr] - 'a' && nexts[i] > 0)
					cnts[curr] += nexts[i];
				freq[i] += nexts[i];
			}
		}
		freq[labels[curr] - 'a']++;
		return freq;
	}
};