#include <vector>
using namespace std;

/* Fast pointer and slow pointer
 * * fast pointer: find non-duplicate numbers
 * * slow pointer: mark the right place tp place the numbers from fast pointer
 */
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) // edge case: if nums is empty, return 0
      return 0;
    int slow = 1;
    for (int fast = 1; fast < nums.size(); ++fast) {
      if (nums[fast] != nums[fast - 1])
        nums[slow++] = nums[fast];
    }
    return slow;
  }
};
