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
    int uniquePathsIII(vector<vector<int>>& grid) {
        // simple bfs
        // bitmap
        int m = grid.size();
        int n = grid[0].size();
        // 
        int endstate = (1 << m * n) - 1;

       	vector<int> dirs = {-1, 0, 1, 0, -1};
       	int ans = 0;
       	queue<pair<int,int>> q;  // <state, loc>
       	// use grid to record visiting

       	int initialState = 0, loc;
       	for(int i = 0; i < m; ++i)
       		for(int j = 0; j < n; ++j)
       			if(grid[i][j] == 1) {
       				loc = i * n + j;
       				initialState |= 1 << loc;       			
       				break;
       			} else if(grid[i][j] == -1) {
       				initialState |= (1 << (i * n + j));
       			}
       	q.emplace(initialState, loc);

       	while(!q.empty()) {
       		auto [state, loc] = q.front();
       		int i = loc / n;
       		int j = loc % n;
       		q.pop();
       		for(int d = 0; d < 4; ++d) {
       			int ni = i + dirs[d], nj = j + dirs[d + 1];
       			int nextLoc = ni * n + nj;
       			if(ni < 0 || nj < 0 || ni == m || nj == n)
       				continue;
       			if(grid[ni][nj] == 2 
       				&& (state | (1 << nextLoc)) == endstate) {
       				ans++;
       				continue;
       			}
       			if(grid[ni][nj] != 0) 
       				continue;
       			if(state & (1 << nextLoc)) 
       				continue;
       			q.emplace(state | (1 << nextLoc), nextLoc);
       		}
       	}
       	return ans;
    }
};