#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPossible(vector<int> &nums) {
    // Check if a sequence can be split into several consecutive subsequences of
    // size 3 or more.
    //
    // Use a Greedy approach.
    //
    // Improvement to Solution 2:
    // For each element, we try to add the "num" to the existing consecutive
    // subsequences. If we cannot do so, we expect there'd be at least two
    // greater numbers to compose a consecutive subsequnce with "num".
    unordered_map<int, int> num_count;
    unordered_map<int, int> num_end_count;

    for (int num : nums)
      num_count[num]++;
    for (int num : nums) {
      if (num_count[num] == 0)
        continue;
      num_count[num]--;
      if (num_end_count[num - 1] > 0) {
        // can we append "num" to any existing consecutive subsequences?
        // if yes, extend the subsequence.
        num_end_count[num]++;
        num_end_count[num - 1]--;
      } else if (num_count[num + 1] > 0 && num_count[num + 2] > 0) {
        // would be build a consecutive subsequence of size 3 leading with
        // "num"? if yes, consume the next two numbers.
        num_count[num + 1]--;
        num_count[num + 2]--;
        num_end_count[num + 2]++;
      } else {
        return false;
      }
    }
    return true;
  }
};