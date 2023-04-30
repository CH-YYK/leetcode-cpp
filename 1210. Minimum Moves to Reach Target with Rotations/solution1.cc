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
    int minimumMoves(vector<vector<int>>& grid) {
		// level-by-level BFS
		// right, down, rotate-clockwise, rotate-counterclockwise
		// [y,x]
		// if horizontal
		// 	right: no block right to x
		// 	down: no block down to x/y  **
		// 	clockwise: no block down to x/y  **
		//  counterclockwise: N/A
		// if vertical
		// 	right: no block right to x/y  **
		// 	down: no block down to x
		// 	clockwise: N/A
		//	counterclockwise: no block right to x/y  **
		queue<pair<int,int>> q; // x, isHorizontal
		int m = grid.size(), n = grid[0].size();
		q.emplace(1, 1);
		vector<vector<int>> visited(m * n, vector<int>(2, 0));
		visited[1][1] = 1;

		int move = 0;
		while(!q.empty()) {
			int size = q.size();
			while(size--) {
				auto [head, h] = q.front();
				q.pop();
				if(head == m * n - 1 && h)
					return move;
				int i = head / n, j = head % n;
				int next;
				if(h) {
					// move right
					if(j + 1 < n && grid[i][j+1] == 0) {
						next = i * n + j + 1;
						if(!visited[next][h]) {
							visited[next][h] = 1;
							q.emplace(next, h);
						}
					}
					// move down or clockwise
					if(i + 1 < m && grid[i + 1][j - 1] == 0 && grid[i + 1][j] == 0) {
						next = (i + 1) * n + j;
						if(!visited[next][h]) {
							visited[next][h] = 1;
							q.emplace(next, h);
						}
						next = (i + 1) * n + j - 1;
						if(!visited[next][h ^ 1]) {
							visited[next][h ^ 1] = 1;
							q.emplace(next, h ^ 1);
						}
					}
				} else {
					// move down
					if(i + 1 < m && grid[i + 1][j] == 0) {
						next = (i + 1) * n + j;
						if(!visited[next][h]) {
							visited[next][h] = 1;
							q.emplace(next, h);
						}
					}
					// move right or counterclockwise
					if(j + 1 < n && grid[i-1][j + 1] == 0 && grid[i][j+1] == 0) {
						next = i * n + j + 1;
						if(!visited[next][h]) {
							visited[next][h] = 1;
							q.emplace(next, h);
						}
						next = (i - 1) * n + j + 1;
						if(!visited[next][h ^ 1]) {
							visited[next][h ^ 1] = 1;
							q.emplace(next, h ^ 1);
						}
					}
				}
			}
			move++;
		}
		return -1;
    }
};
