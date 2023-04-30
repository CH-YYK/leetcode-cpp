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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
		vector<vector<int>> redGraph(n), blueGraph(n);
		for(vector<int>& edge : redEdges) 
			redGraph[edge[0]].push_back(edge[1]);
		for(vector<int>& edge : blueEdges)
			blueGraph[edge[0]].push_back(edge[1]);
		queue<pair<int,int>> q;  // <node, isRed>

		// A node can be reached through either blue line or red line
		vector<vector<int>> visited(n, vector<int>(2, INT_MAX));
		for(int i : redGraph[0]) {
			q.emplace(i, 1);
			visited[i][1] = 1;
		}

		for(int i : blueGraph[0]) {
			q.emplace(i, 0);
			visited[i][0] = 1;
		}

		int step = 1;
		while(!q.empty()) {
			int size = q.size();
			step++;
			while(size--) {
				auto [curr, isRed] = q.front();
                q.pop();
				if(isRed) { // not red
					for(int nxt : blueGraph[curr]) {						
						if(visited[nxt][0] != -1 && step >= visited[nxt][0])
							continue;
						visited[nxt][0] = step;
						q.emplace(nxt, 0);
					}
				} else {
					for(int nxt : redGraph[curr]) {
						if(visited[nxt][1] != -1 && step >= visited[nxt][1])
							continue;
						visited[nxt][1] = step;
						q.emplace(nxt, 1);
					}
				}
			}
		}

		vector<int> answers(n, 0);
		for(int i = 1; i < n; ++i) {
			int tmp = min(visited[i][0], visited[i][1]);
            if(tmp < INT_MAX)
                answers[i] = tmp;
            else 
                answers[i] = -1;
        }
		return answers;
    }
};