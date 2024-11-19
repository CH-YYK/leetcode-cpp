
#include <queue>
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
    // Improvement to Solution 1:
    // There are at most 2000 distinct numbers in nums, so let's get rid of the
    // unordered_map and use a vector to store the min_pqs.
    vector<priority_queue<int, vector<int>, greater<>>> min_pq_by_end(2002);
    for (int num : nums) {
      // Offset by 1001 to avoid num = 0.
      num += 1001;
      if (min_pq_by_end[num - 1].empty())
        min_pq_by_end[num].push(1);
      else {
        int curr_seq_size = min_pq_by_end[num - 1].top();
        min_pq_by_end[num - 1].pop();
        min_pq_by_end[num].push(curr_seq_size + 1);
      }
    }
    for (auto &pq : min_pq_by_end) {
      if (!pq.empty() && pq.top() < 3)
        return false;
    }
    return true;
  }
};