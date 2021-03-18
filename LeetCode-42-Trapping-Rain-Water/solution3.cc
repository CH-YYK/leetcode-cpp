#include <vector>

using namespace std;

/* Get left and right max values in one iteration
 * Maintain two pointers, i,j, pointing to left_max and right_max
 *   height in the middle would be determined by h= min(left_max, right_max)
 *   and we know that the 'h' for i,j has been confirmed so that we can add this
 *   to result immediately.
 */
class Solution {
public:
  int trap(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int res = 0;
    int left_max = 0, right_max = 0;
    while(left < right) {
      if (height[left] < height[right]) {  // left margin determined the height for the leftmost point
        res += max(left_max, height[left]) - height[left++];
      } else {  // right margin determined the height for the rightmost point
        res += max(right_max, height[right]) - height[right--];
      }
    }
    return res;
  }
};
