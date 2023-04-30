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

using namespace std;
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
  		// every time it'll flip a cell and its neightbors
  		// minimum operation -> using BFS
  		// use bitset to save the state of matrix because m * n <= 9

    	int m = mat.size(), n = mat[0].size();
  		function<int(int,int,int)> flip = [&](int state, int x, int y) {
  			state ^= (1 << (n * x + y));
  			for(int d = 0; d < 4; ++d) {
  				int nx = x + dirs[d];
  				int ny = y + dirs[d + 1];
  				if(nx < 0 || ny < 0 || nx == m || ny == n)
  					continue;
  				state ^= (1 << (nx * n + ny));
  			}
  			return state;
  		};

  		unordered_set<int> visited;
  		queue<int> q;

  		// compress the matrix and initialize the queue
  		int state = 0;  		
  		for(int i = 0; i < m; ++i)
  			for(int j = 0; j < n; ++j) 
  				state |= (mat[i][j] << (i * n + j));

  		q.push(state);
  		visited.insert(state);

  		int step = 0;
  		while(!q.empty()) {
  			int size = q.size();
  			while(size--) {
  				int curr = q.front();
                if(curr == 0) return step;
  				q.pop();
  				for(int x = 0; x < m; ++x)
  					for(int y = 0; y < n; ++y) {
  						int nextState = flip(curr, x, y);
  						if(visited.count(nextState))
  							continue;
  						visited.insert(nextState);
  						q.push(nextState);
  					}
  			}
  			step++;
  		}
  		return -1;
    }
private:
	vector<int> dirs = {-1, 0, 1, 0, -1};
};

int main() {
    
}
