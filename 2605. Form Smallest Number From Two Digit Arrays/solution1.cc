#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minNumber(vector<int> &nums1, vector<int> &nums2) {
    // digits -> elements are in [1, 9], so the formed number
    // must be either a 2-digit number i.e. in [11, 99], or one digit
    // that is commonly located in two arrays.
    vector<int> states(10);
    int min1 = 10, min2 = 10;
    for (int num : nums1)
      states[num]++, min1 = min(min1, num);
    for (int num : nums2)
      states[num]++, min2 = min(min2, num);
    for (int i = 1; i <= 9; ++i)
      if (states[i] == 2)
        return i;
    return min(min1 * 10 + min2, min2 * 10 + min1);
  }
};