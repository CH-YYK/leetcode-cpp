#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    int xors = 0, n = nums.size();
    for(int num : nums) xors ^= num;

    vector<int> answer(n);
    for(int i = 0; i < n; ++i) {
      if(i > 0) xors ^= nums[n - i];
      for(int j = maximumBit - 1; j >= 0; --j) {
        if(xors & (1 << j)) // jth bit is 1
          answer[i] += 0 << j;
        else // jth bit is 0
          answer[i] += 1 << j;
      }
    }
    return answer;
  }
};
