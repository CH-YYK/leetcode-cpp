#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/* nums[i] + rev(nums[j]) = nums[j] + rev(nums[i])
 * nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
 */
class Solution {
public:
  int countNicePairs(vector<int> &nums) {
    // unordered_map<int, unordered_set<int>> hashtable;
    unordered_map<int, int> table;
    int res = 0;
    for(int& num : nums) {
      res += table[num - rev(num)];
      table[num - rev(num)]++;
    }
    return res;
  }
private:
  int rev(int num) {
    long res = 0;
    while(num) {
      res += num % 10;
      num /= 10;
      res *= 10;
    }
    return res / 10;
  }
};
