// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

static vector<long> dp;

class Solution {
public:
  bool checkPowersOfThree(int n) {
    // triple number
    // 3^0 + 3^1 + 3^2..
    // 3^x = n
    // 3^y = n - 3^x
    // dp[i]:= least power of 3 to be maximized under i
    if (n == 1)
      return true;
    if (n < 3)
      return false;

    if (dp.empty()) {
      dp = vector<long>(30, 0);
      for (int i = 0; i < 30; ++i) {
        if (i == 0)
          dp[0] = 1;
        else
          dp[i] = dp[i - 1] * 3;
      }
    }

    vector<int> visited(30, 0);
    while (n) {
      auto p = prev(upper_bound(dp.begin(), dp.end(), n));
      int pow = p - dp.begin();
      if (visited[pow])
        return false;
      visited[pow] = 1;
      n -= *p;
    }
    return true;
  }
};

int main() {}
