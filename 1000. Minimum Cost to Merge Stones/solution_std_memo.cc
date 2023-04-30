#include <vector>
using namespace std;

class Solution {
public:
  int mergeStones(vector<int> &stones, int K) {
    k = K;
    const int n = stones.size();
    if ((n - 1) % (K - 1) != 0)
      return -1;
    sums = vector<int>(n + 1);
    for (int i = 0; i < n; ++i)
      sums[i + 1] = sums[i] + stones[i];
    memo = vector<vector<int>>(n, vector<int>(n, -1));
    return mincost(stones, 0, n - 1);
  }

private:
  int k;
  vector<int> sums;
  vector<vector<int>> memo;

  int mincost(vector<int> &stones, int i, int j) {
    const int l = j - i + 1;
    if (l < k)
      return 0;
    if (memo[i][j] != -1)
      return memo[i][j];
    int ans = 10000000;
    for (int m = i; m < j; m += k - 1)
      ans = min(ans, mincost(stones, i, m) + mincost(stones, m + 1, j));
    if ((l - 1) % (k - 1) == 0)
      ans += sums[j + 1] - sums[i];
    return memo[i][j] = ans;
  }
};
