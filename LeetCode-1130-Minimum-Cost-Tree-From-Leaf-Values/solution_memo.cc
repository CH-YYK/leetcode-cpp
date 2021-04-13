#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
  int mctFromLeafValues(vector<int> &arr) {
    int n = arr.size();
    memo_minsum = vector<vector<int>>(n, vector<int>(n, -1));
    memo_max = vector<vector<int>>(n, vector<int>(n, -1));
    return minsum(arr, 0, n-1);
  }
private:
  vector<vector<int>> memo_minsum;
  vector<vector<int>> memo_max;
  int minsum(vector<int>& arr, int i, int j) {
    if(i == j) return 0;
    if(i == j - 1) return arr[i] * arr[j];
    if(memo_minsum[i][j] >= 0) return memo_minsum[i][j];
    // fun(i,j) = min{fun(i,k)+fun(k+1,j)+max(i,k)*max(k+1,j)}
    int min_ = 1000000;
    for(int k = i; k < j; ++k) {
      min_ = min(min_, minsum(arr, i, k) + minsum(arr, k+1, j) + maxvalue(arr, i, k) * maxvalue(arr, k+1, j));
    }
    return memo_minsum[i][j] = min_;
  }

  int maxvalue(vector<int>& arr, int i, int j) {
    if(i > j) return 0;
    if(i == j) return arr[i];
    if(memo_max[i][j] >= 0) return memo_max[i][j];
    if(arr[i] >= arr[j])
      return memo_max[i][j] = max(arr[i], maxvalue(arr, i+1, j-1));
    return memo_max[i][j] = max(arr[j], maxvalue(arr, i+1, j-1));
  }
};
