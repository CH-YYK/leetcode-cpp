#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int res = 0;
    /* Number can exist for 3 times for once
     * Walk through all 32 digits
     * * For num which may exist 3 times
     * * if ith digit is 1, then total number of 1's at ith digit must be multiply of 3
     * * For num which only exist once, then it cannot make a multiply of 3 for some digit
     */
    for(int i = 31; i >= 0; --i) {
      int total = 0;
      for(int& num : nums)
        if(num & 1 << i) total++;
      if(total % 3) res += 1 << i;
    }
    return res;
  }
};
