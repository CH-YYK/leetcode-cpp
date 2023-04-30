#include <vector>
#include <unordered_set>
using namespace std;

/* Bottom-up, find ugly_i then get ugly_i * 2, ugly_i * 3, ugly_i * 5
 */
class Solution {
public:
  int nthUglyNumber(int n) {
    int num = 1;
    vector<int> res{num};
    static int i = 0, j = 0, k = 0;
    while (n > 1) {
      const int num_i = res[i] * 2;
      const int num_j = res[j] * 3;
      const int num_k = res[k] * 5;
      const int min_num = min(num_i, min(num_j, num_k));
      if (num_i == min_num)
        i++;
      if (num_j == min_num)
        j++;
      if (num_k == min_num)
        k++;
      res.push_back(min_num), n--;
    }
    return res.back();
  }
};
