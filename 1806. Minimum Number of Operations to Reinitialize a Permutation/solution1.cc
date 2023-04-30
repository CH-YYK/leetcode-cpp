#include <vector>

using namespace std;

class Solution {
public:
  int reinitializePermutation(int n) {
    vector<int> arr(n), perm(n, 0);
    bool back = true;
    vector<int> &p1 = perm, &p2 = arr;
    for (int i = 0; i < 10000; ++i) {
      back = true;
      for (int j = 0; j < n; ++j) {
        if (i == 0)
          arr[j] = j;
        else {
          if (j % 2 == 0)
            arr[j] = perm[j / 2];
          if (j % 2 == 1)
            arr[j] = perm[(n + j - 1) / 2];
          back &= (arr[j] == j);
        }
      }
      if (back)
        return i;
      swap(arr, perm);
    }
    return 1;
  }
};
