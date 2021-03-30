#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> values;
    backtrack(n, 1, values, k);
    return res;
  }

private:
  vector<vector<int>> res;
  void backtrack(int n, int i, vector<int> &values, int k) {
    if (values.size() == k) {
      res.push_back(values);
      return;
    }

    for (int j = i; j <= n; ++j) {
      values.push_back(j);
      backtrack(n, j + 1, values, k);
      values.pop_back();
    }
  }
};
