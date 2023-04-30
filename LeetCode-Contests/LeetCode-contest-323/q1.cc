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
    int deleteGreatestValue(vector<vector<int>>& grid) {
  		int m = grid.size();
  		int n = grid[0].size();
  		for(int i = 0; i < m; ++i)      
  			sort(grid[i].begin(), grid[i].end());
  		int ans = 0;
  		while(n--) {
  			int max_ = 0;
  			for(int i = 0; i < m; ++i) {
  				max_ = max(max_, grid[i][n]);
  			}
  			ans += max_;
  		}
  		return ans;
    }
};

int main() {
    
}
