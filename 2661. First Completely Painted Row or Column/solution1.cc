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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    	// get the last index for each row and column
    	unordered_map<int,int> index;
    	for(int i = 0; i < arr.size(); ++i) 
    		index[arr[i]] = i;
    	int m = mat.size(), n = mat[0].size();
    	vector<int> rows(m, -1), cols(n, -1);
    	for(int i = 0; i < m; ++i) {
    		for(int j = 0; j < n; ++j) {
    			int ind = index[mat[i][j]];
    			rows[i] = max(rows[i], ind);
    			cols[j] = max(cols[j], ind);
    		}
    	}

    	int ans = m * n;
    	for(int i = 0; i < m; ++i) {
    		for(int j = 0; j < n; ++j) {
    			ans = min(ans, min(rows[i], cols[j]));
    		}
    	}
    	return ans;
    }
};