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
    	// linked list
    	int n = edges.size();
    	vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

		traverse(edges, dist1, node1);
		traverse(edges, dist2, node2);
		int distance = INT_MAX, ans = -1;
		for(int i = 0; i < n; ++i) {
			if(max(dist1[i], dist2[i]) < distance)
				distance = max(dist1[i], dist2[i]), ans = i;			
		}
		return ans;
    }
private:
	void traverse(vector<int>& edges, vector<int>& dist, int src) {
		int curr = src;
		int d = 0;
		while(curr != -1 && d < dist[curr]) {
			dist[curr] = d++;
			curr = edges[curr];
		}
	}
};