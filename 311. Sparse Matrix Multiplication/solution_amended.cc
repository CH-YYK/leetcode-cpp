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
    	// Sparse matrix 
    	// compress the sparse matrix, 
    	// 	  for mat1 and for each row, only save the index of non zeros
    	//	  for mat2 and for each column, only save the index of non zeros
    	// 
    	// Complexity: O(M*Z*k) k <<< n
    	int m = mat1.size(), n = mat1[0].size(), z = mat2[0].size();
    	vector<vector<int>> spmat1(m), spmat2(z);
    	for(int i = 0; i < m; ++i) 
    		for(int j = 0; j < n; ++j) {
    			if(mat1[i][j] != 0)
    				spmat1[i].push_back(j);
    		}

    	for(int i = 0; i < n; ++i) 
    		for(int j = 0; j < z; ++j) {
    			if(mat2[i][j] != 0)
    				spmat2[j].push_back(i);
    		}

    	// m*n x n*z = m*z
    	vector<vector<int>> ans(m, vector<int>(z, 0));
    	for(int i = 0; i < m; ++i) 
    		for(int j = 0; j < z; ++j) {
    			int it1 = 0, it2 = 0;
    			while(it1 < spmat1[i].size() && it2 < spmat2[j].size()) {
    				int ind1 = spmat1[i][it1];
    				int ind2 = spmat2[j][it2];
    				if(ind1 == ind2) {
    					ans[i][j] += mat1[i][ind1] * mat2[ind2][j];
    					it1++, it2++;
    				} else if(ind1 < ind2)
    					it1++;
    				else 
    					it2++;
    			}
    		}
    	return ans;
    }
};