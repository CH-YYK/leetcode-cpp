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
    int snakesAndLadders(vector<vector<int>>& board) {
		// bfs
		// 6 more steps each step 
		// number -> location
		reverse(board.begin(), board.end());
		int n = board.size();
		queue<int> q;
		q.emplace(0);

		int step = 0;
		while(!q.empty()) {
			int size = q.size();
			while(size--) {
				int curr = q.front();
				q.pop();			
				int i = curr / n;
				int change = i % 2 == 0 ? 1 : -1;
				int j = change == 1 ? curr % n : n - curr % n;

				if(curr == n * n - 1)
					return step + 1;
				int next = curr;
				int nstep = 6;
				while(nstep--) {
					next++;
					j += change;
					if(j < 0) i++, change *= -1, j+=change;
					if(j == n) i++, change *= -1, j+=change;
					if(board[i][j] - 1 > curr)
						q.emplace(board[i][j] - 1);
					if(nstep == 0)
						q.emplace(next);
				}
			}
			step++;
		}
		return -1;
    }
};