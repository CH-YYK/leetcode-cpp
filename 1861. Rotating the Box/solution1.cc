#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
    // For stones in the middle of any two obstacles, apply two pointers to swap
    // a stone (l) with a space (r).
    // Once an obstacle is encountered, reset the two pointers to skip the
    // obstacle.
    // Time: O(m * n)
    // Space: O(1) except for the answer.
    int m = box.size();
    int n = box[0].size();
    for (int i = 0; i < m; ++i) {
      int l = n - 1, r = n - 1;
      while (l >= 0) {
        if (box[i][l] == '*') {
          // Reset the two pointers to skip the obstacle.
          r = --l;
        } else {
          // Find the next space.
          while (r > l && box[i][r] != '.')
            --r;
          // Swap a stone with a space.
          if (box[i][l] == '#' && box[i][r] == '.')
            swap(box[i][l], box[i][r]);
          --l;
        }
      }
    }
    vector<vector<char>> ans(n, vector<char>(m));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans[j][m - i - 1] = box[i][j];
    return ans;
  }
};
