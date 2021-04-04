#include <unordered_set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

class Solution {
public:
  int countDifferentSubsequenceGCDs(vector<int> &nums) {
    set<int> gcds;
    for (int i = 0; i < nums.size(); ++i) {
      if (gcds.count(nums[i]))
        continue;
      int num = nums[i];
      vector<int> new_gcds;
      for (auto it = gcds.rbegin(); it != gcds.rend(); ++it) {
        if (gcds.count(gcd(*it, num))) continue;
        if(gcd(*it, num) == *it) break;
        new_gcds.push_back(gcd(*it, num));
      }
      for (const int &new_gcd : new_gcds)
        gcds.insert(new_gcd);
      gcds.insert(num);
    }
    return gcds.size();
  }
};
