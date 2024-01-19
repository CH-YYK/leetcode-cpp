#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // in-place replacement, O(N) time without extra space.
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j){
                int min3 = matrix[i-1][j];
                if(j > 0) min3 = min(min3, matrix[i-1][j-1]);
                if(j < n-1) min3 = min(min3, matrix[i-1][j+1]);
                matrix[i][j] += min3;
            }
        }
        return *min_element(matrix[m-1].begin(), matrix[m-1].end());
    }
};