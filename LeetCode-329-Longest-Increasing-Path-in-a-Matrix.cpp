#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        if(matrix.front().size() == 0) return 0;
        m = matrix.size(), n = matrix[0].size();
        record = vector<vector<int>> (m, vector<int>(n, -1));

        int max_num = 0, tmp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                tmp = dfs(matrix, i, j);
                max_num = max(tmp, max_num);
            }
        }
        return max_num + 1;
    }
private:
    vector<vector<int>> record;
    int m, n;

    int dfs(vector<vector<int>> &matrix, int i, int j) {
        if(record[i][j] >= 0) return record[i][j];

        int max_num = -1;
        if(i > 0 && matrix[i][j] > matrix[i-1][j])
            max_num = max(max_num, dfs(matrix, i-1, j));
        if(i < m-1 && matrix[i][j] > matrix[i+1][j])
            max_num = max(max_num, dfs(matrix, i+1, j));
        if(j > 0 && matrix[i][j] > matrix[i][j-1])
            max_num = max(max_num, dfs(matrix, i, j-1));
        if(j < n-1 && matrix[i][j] > matrix[i][j+1])
            max_num = max(max_num, dfs(matrix, i, j+1));
        /*
        if(max_num == -1) 
            record[i][j] = 0;
        else */
        record[i][j] = max_num + 1;
        return record[i][j];
    }
};