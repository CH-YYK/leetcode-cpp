#include <vector>
#include <algorithm>
using namespace std;

// make lhs strickly smaller than rhs
bool cmp(const vector<int> &lhs, const vector<int> &rhs) {
  if (lhs[0] < rhs[0])
    return true;
  else if (lhs[0] == rhs[0])
    return lhs[1] < rhs[1];
  else
    return false;
}

class Solution {
public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
    vector<int> ans(k, 0);
    sort(logs.begin(), logs.end(), cmp);
    int uam = 0;
    for (int i = 0; i < logs.size(); ++i) {
      if (i == 0)
        uam = 1;
      else if (logs[i][0] != logs[i - 1][0]) {
        ans[uam - 1]++;
        uam = 1;
      } else if (logs[i][1] == logs[i - 1][1])
        continue;
      else
        uam++;
    }
    ans[uam - 1]++;
    return ans;
  }
};
