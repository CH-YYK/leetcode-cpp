#include <vector>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int row = -1, col = -1;
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
        if(matrix[i][j] == 0) {
          row = i;
          col = j;
          break;
        }
    if(row == -1 || col == -1) return;
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
        if (matrix[i][j] == 0) {
          matrix[row][j] = 0;
          matrix[i][col] = 0;
        }
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j) {
        if(i == row || j == col) continue;
        if(matrix[row][j] == 0)
          matrix[i][j] = 0;
        if(matrix[i][col] == 0)
          matrix[i][j] = 0;
      }
    for(int i = 0; i < m; ++i) matrix[i][col] = 0;
    for(int j = 0; j < n; ++j) matrix[row][j] = 0;
  }
};
