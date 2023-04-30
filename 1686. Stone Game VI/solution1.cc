#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
  int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
    int n = aliceValues.size();
    vector<pair<int, int>> profits;
    for (int i = 0; i < n; ++i)
      profits.push_back({aliceValues[i] + bobValues[i], i});
    sort(profits.begin(), profits.end(), greater<pair<int, int>>());

    int A = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0)
        A += aliceValues[profits[i].second];
      else
        A -= bobValues[profits[i].second];
    }

    if (A > 0)
      return 1;
    else if (A == 0)
      return 0;
    else
      return -1;
  }
};
