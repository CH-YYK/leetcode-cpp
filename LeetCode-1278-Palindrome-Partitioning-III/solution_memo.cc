#include <vector>
#include <limits>
#include <string>
using namespace std;

class Solution {
public:
  int palindromePartition(string s, int k) {
    int n = s.size();
    memo_res = vector<vector<int>>(n, vector<int>(k + 1, -1));
    memo_cost = vector<vector<int>>(n, vector<int>(n, -1));
    return search(s, 0, k);
  }

private:
  vector<vector<int>> memo_res; // cost to partition the s[i:] into k palindrome
  vector<vector<int>> memo_cost; // cost to change substring palindrome

  int search(string &s, int i, int k) {
    if (i == s.size())
      return 0;
    if (k == 1)  // make sure k partitions has been selected
      return cost(s, i, s.size() - 1);
    if (memo_res[i][k] >= 0)
      return memo_res[i][k];
    int min_ = 100000;
    // Pruning: make sure at least k-1 characters can be further added (starting from j+1)
    for (int j = i; j <= s.size() - k; ++j) {  
      min_ = min(search(s, j + 1, k - 1) + cost(s, i, j), min_);
    }
    return memo_res[i][k] = min_;
  }

  int cost(string &s, int i, int j) {
    if (i >= j)
      return 0;
    if (memo_cost[i][j] >= 0)
      return memo_cost[i][j];
    if (s[i] == s[j])
      return memo_cost[i][j] = cost(s, i + 1, j - 1);
    return memo_cost[i][j] = cost(s, i + 1, j - 1) + 1;
  }
};
