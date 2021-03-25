#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
  bool splitArraySameAverage(vector<int> &nums) {
    S = accumulate(nums.begin(), nums.end(), 0);
    N = nums.size();

    memo = vector<vector<unordered_map<int, double>>> (N, vector<unordered_map<int, double>>(N));
    return dfs(nums, 0, 0, 0);
  }
private:
  int N;
  double S;
  vector<vector<unordered_map<int,double>>> memo;

  bool dfs(vector<int>& nums, int i, int n, double cumsum) {
    if(cumsum / n == (S - cumsum) / (N - n)) return true;
    if(i == N) return false;
    if(memo[n][i].count(cumsum/n))
      return memo[n][i][cumsum/n];
    bool base = false;
    for(int j = i; j < N; ++j) {
      base |= dfs(nums, j + 1, n+1, cumsum + nums[j]);
    }
    return memo[n][i][cumsum/n] = base;
  }
};
