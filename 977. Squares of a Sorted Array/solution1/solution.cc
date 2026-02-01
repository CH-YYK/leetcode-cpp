#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &A) {
    // Find the z, where nums[z] >= 0
    int z = lower_bound(A.begin(), A.end(), 0) - A.begin();
    int l = z - 1, r = z;
    vector<int> res;
    while (l >= 0 && r < A.size()) {
      if (abs(A[l]) <= abs(A[r])) {
        res.push_back(A[l] * A[l]);
        l--;
      } else {
        res.push_back(A[r] * A[r]);
        r++;
      }
    }
    while (l >= 0)
      res.push_back(A[l] * A[l]), l--;
    while (r < A.size())
      res.push_back(A[r] * A[r]), r--;
    return res;
  }
};