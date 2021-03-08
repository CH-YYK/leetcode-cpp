/* An envelope [w1, h1] can be put inside another one [w2, h2] if w1 < w2 and h1 < h2
 *
 * 1- Sort the vector of envelopes
 * 2- problem is reduced to LIS of envelope[1]
 *   2-1- Solve LIS using Binary Search
 * 3- Time complexity: O(NlogN)
 */

bool cmp(vector<int>& lhs, vector<int>& rhs) {
  return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
}

class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) {
      return 0;
    }
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), cmp);

    vector<int> f = {envelopes[0][1]};
    for (int i = 1; i < n; ++i) {
      if (int num = envelopes[i][1]; num > f.back()) {
        f.push_back(num);  // biggest
      }
      else {
        auto it = lower_bound(f.begin(), f.end(), num); // binary search lower bound
        *it = num; // replace with bigger
      }
    }
    return f.size();
  }
};
