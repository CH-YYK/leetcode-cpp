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
  vector<vector<int>> combine(int n, int k) {
  	// Iteratively simulate dfs process.
  	//
  	// bfs and use the state (path, i) in the queue
  	// 		at each iteration, we have
  	// 			path.push_back(i + 1), (optinally) reverse the last change of i;
  	// 
  	// However, the iterative way may work better with cheaper state,
  	//    lots of time would be wasted on redundant state copying.
  	// 		e.g. when the Sum is asked instead of the whole subsequence.
  	queue<pair<vector<int>, int>> q;
  	q.push({{1}, 1});
  	vector<vector<int>> ans;

  	while(!q.empty()) {
  		auto [path, i] = q.front();
  		q.pop();
  		if(path.size() == k)
  			ans.push_back(path);

  		if(i + 1 <= n) {
  			path.push_back(i + 1);
  			q.push({path, i + 1});

  			path.pop_back();
  			path.pop_back();
  			path.push_back(i + 1);

  			q.push({path, i + 1});
	  	}
  	}
  	return ans;
  }
};
