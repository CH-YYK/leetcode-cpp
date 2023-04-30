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
    int minJumps(vector<int>& arr) {
  		// 1. i+1,  2. i-1,  3. arr[i] == arr[j]      
  		// option 3 is always the best one
  		// buckets
  		// Dijkstra O(E + NlogN)
  		int n = arr.size();
  		vector<int> dist(n, INT_MAX);
  		dist[0] = 0;
  		// maxheap: <-dist, idx>
  		priority_queue<pair<int,int>> pq;
  		unordered_map<int, vector<int>> values;
  		unordered_map<int, int> prestep;
  		for(int i = 0; i < n; ++i)
  			values[arr[i]].push_back(i);
  		pq.emplace(0, 0);

  		// dijkstra
  		while(!pq.empty()) {
  			auto [nd, idx] = pq.top();
  			pq.pop();
  			// i-1
  			int d = -nd + 1;
  			if(idx == n - 1) return -nd;
  			if(idx + 1 == n - 1) return d;
  			if(idx > 0 && arr[idx-1] != arr[idx]) {
  				if(d < dist[idx - 1]) {
  					dist[idx - 1] = d;
  					pq.emplace(-d, idx - 1);
  				}
  			}

  			// i + 1
  			if(idx < n - 1 && arr[idx + 1] != arr[idx]) {
  				if(d < dist[idx + 1]) {
  					dist[idx + 1] = d;
  					pq.emplace(-d, idx + 1);
  				}
  			}
  			// arr[i] == arr[j]  			
  			if(prestep.count(arr[idx]) && d >= prestep[arr[idx]]) 
  				continue;
  			prestep[arr[idx]] = d;
  			for(int nxt : values[arr[idx]]) {
  				if(nxt == n - 1) return d;
  				if(nxt == idx) continue;
  				if(d < dist[nxt]) {
  					dist[nxt] = d;
  					pq.emplace(-d, nxt);
  				}
  			}
  		}
  		return -1;
    }
};