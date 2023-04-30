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
    bool checkXMatrix(vector<vector<int>>& grid) {
    	bool ans = true;
    	int n = grid.size();
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j || n - 1 - i == j)
					ans &= (grid[i][j] != 0);
				else
					ans &= (grid[i][j] == 0);
			}
		}
		return ans;
    }
};