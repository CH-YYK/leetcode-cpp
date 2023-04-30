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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    	// BFS
    	int n = edges.size();
    	vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

		vector<vector<int>> graph(n);
		for(int i = 0; i < n; ++i) 
			if(edges[i] != -1)
			    graph[i].push_back(edges[i]);
		traverse(graph, dist1, node1);
		traverse(graph, dist2, node2);
		int distance = INT_MAX, ans = -1;
		for(int i = 0; i < n; ++i) {
			if(max(dist1[i], dist2[i]) < distance)
				distance = max(dist1[i], dist2[i]), ans = i;			
		}
		return ans;
    }
private:
	void traverse(vector<vector<int>>& graph, vector<int>& dist, int src) {
		queue<int> q;
		dist[src] = 0;
		q.push(src);
		int d = 0;
		while(!q.empty()) {
			int size = q.size();
			while(size--) {
				int curr = q.front();
				q.pop();
				for(int nxt : graph[curr]) {
					if(dist[nxt] < INT_MAX) 
                        continue;
					dist[nxt] = d + 1;
					q.push(nxt);
				}
			}
			d++;
		}
	}
};