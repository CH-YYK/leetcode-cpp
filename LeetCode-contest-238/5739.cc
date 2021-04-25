#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    map<int, int, greater<int>> m;
    for (int num : nums)
      m[num]++;
    int res = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
      int num = it->first;
      auto maxit = m.upper_bound(num - k);
      int K = k, cnt = it->second;
      for (auto curr = next(it); curr != maxit && K > 0; ++curr) {
        int diff = it->first - curr->first;
        if (K / diff >= curr->second) {
          cnt += curr->second;
          K -= curr->second * diff;
        } else {
          cnt += K / diff;
          break;
        }
      }
      if (cnt > res)
        res = cnt;
    }
    return res;
  }
};
