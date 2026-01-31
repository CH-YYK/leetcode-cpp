#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int i = 0, j = i + 1;
    int k = 1;
    int n = nums.size();
    while (i < n - 1) {
      // find the next different number
      while (j < n && nums[i] == nums[j])
        j++;
      if (j < n) {
        k++;
        swap(nums[i + 1], nums[j++]);
      }
      i++;
    }
    return k;
  }
};