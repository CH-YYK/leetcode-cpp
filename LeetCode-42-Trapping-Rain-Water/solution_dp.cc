#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    vector<int> rights(n, 0), lefts(n, 0);
    lefts[0] = height[0];
    rights[n - 1] = height[n - 1];

    for (int i = 1; i < n; ++i)
      lefts[i] = max(lefts[i - 1], height[i]);
    for (int i = n - 1; i >= 0; --i)
      rights[i] = max(rights[i + 1], height[i]);
    int res = 0;
    for (int i = 0; i < n; ++i)
      res += min(lefts[i], rights[i]) - height[i];
    return res;
  }
};
