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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // cannot perform simulation due to high cost
        // use a matrix to record how many region has covered [i,j];
        // num(up-left) - num(bottom-right)
        // Prefix sum
        // for a query [r1, c1, r2, c2], 
        //  set mat[r1:r2][c1]++ and mat[r1:r2][c2 + 1]--
        // mat[r1:r2][c1]:= total contributions from the queries
        // mat[r1:r2][c2+1]:= offsets from the queries
        vector<vector<int>> mat(n, vector<int>(n + 1, 0));        
        for(vector<int>& query : queries) {
        	for(int r = query[0]; r <= query[2]; ++r){
        		mat[r][query[1]]++;
        		mat[r][query[3] + 1]--;
        	}
        }

        for(int r = 0; r < n; ++r) {
        	int sum = 0;
        	for(int c = 0; c < n; ++c) {
        		sum += mat[r][c];
        		mat[r][c] = sum;         	
        	}
        	mat[r].pop_back();        	
        }        
        return mat;
    }
};