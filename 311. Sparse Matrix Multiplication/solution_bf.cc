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
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        // brute force: m*n, n*z -> m * n * z
        // Time complexity: O(M*N*Z)
        int m = mat1.size(), n = mat1[0].size(), z = mat2[0].size();
        vector<vector<int>> ans(m, vector<int>(z, 0));
        for(int i = 0; i < m; ++i) {
        	for(int j = 0; j < z; ++j) {
        		for(int k = 0; k < n; ++k) {
        			ans[i][j] += (mat1[i][k] * mat2[k][j]);
        		}
        	}
        }
        return ans;
    }
};