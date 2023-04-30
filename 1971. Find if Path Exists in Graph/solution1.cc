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

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    	if(source == destination) return true;
    	vector<vector<int>> graph(n);
    	for(vector<int>& edge : edges) {
    		graph[edge[0]].push_back(edge[1]);
    		graph[edge[1]].push_back(edge[0]);
    	}

    	// 
    	queue<int> q;
    	q.push(source);
    	vector<int> visited(n, 0);
    	visited[source] = 1;

    	while(!q.empty()) {
    		int curr = q.front();
    		q.pop();

    		for(int nxt : graph[curr]) {
    			if(visited[nxt]) continue;
    			if(nxt == destination) return true;
    			visited[nxt] = 1;
    			q.push(nxt);
    		}
    	}
    	return false;
    }
};