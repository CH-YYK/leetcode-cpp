#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int solve(vector<int> &arr, vector<int> &cost, int w, int b, int x) {
    this->b = b;
    this->x = x;
    memo = vector<unordered_map<int,int>>(arr.size());
    return maxfish(arr, cost, 0, w, w);
  }

private:
  vector<unordered_map<int, int>> memo;
  int b, x;
  int maxfish(vector<int> &arr, vector<int> &cost, int i, int w, int m) {
    if (i == arr.size())
      return 0;
    if (w >= m)
      w = m;
    if(memo[i].count(w)) return memo[i][w];
    int res = 0;
    for (int j = 0; j <= arr[i]; ++j) {
      if (w - cost[i] * j >= 0)
        res = max(res,
                j + maxfish(arr, cost, i + 1, w - cost[i] * j + x, m + b * j));
    }
    return memo[i][w] = res;
  }
};


int main() {
  vector<int> arr = {3, 4};
  vector<int> cost = {4, 2};
  int w = 12, b = 0, x = 4;
  int sol = Solution().solve(arr, cost, w, b, x);
  cout << sol << endl;
}
