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
  		int n = arr.size();
		
  		queue<int> q;
  		vector<int> visited(n, 0);
  		// buckets
		unordered_map<int, vector<int>> values;
		// arrived in buckets
  		unordered_set<int> arrived;
  		for(int i = 0; i < n; ++i)
  			values[arr[i]].push_back(i);
  		q.push(0);

  		int step = 0;

  		// bfs
  		while(!q.empty()) {
  			int size = q.size();
  			step++;
  			while(size--) {
  				int idx = q.front();
  				q.pop();
  				if(idx == n - 1) return step-1;
  				if(idx + 1 == n - 1) return step;
  				// i - 1
  				if(idx > 0 && arr[idx - 1] != arr[idx]) {
  					if(!visited[idx - 1]) {
  						q.push(idx - 1);
  						visited[idx - 1] = 1;
  					}
  				}
  				// i + 1
  				if(idx < n - 1 && arr[idx + 1] != arr[idx]) {
  					if(!visited[idx + 1]) {
  						q.push(idx + 1);
  						visited[idx + 1] = 1;
  					}
  				}
  				// arr[i] == arr[j]
  				if(arrived.count(arr[idx]))
  					continue;
				arrived.insert(arr[idx]);
  				for(int nxt : values[arr[idx]]) {
  					if(nxt == n - 1) return step;
  					if(nxt == idx || visited[nxt]) continue;
  					q.push(nxt);
  					visited[nxt] = 1;
  				}
  			}
  		}
  		return -1;
    }
};