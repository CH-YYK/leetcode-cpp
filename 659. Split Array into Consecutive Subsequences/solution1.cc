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
    // Suppose we have a list of subsequences. When we go through nums from left
    // to right. We gradually append the number to one of the subsequences if
    // it's the next number. Otherwise, we create a new subsequence. If there
    // are multiple options of subsequences to append to, we choose the one of
    // the shortest length.

    // Improvement:
    // We don't have to "actually" store the subsequences, just the end number
    // and the size. This would be easier for us to maintain the order.
    unordered_map<int, priority_queue<int, vector<int>, greater<>>>
        min_pq_by_end;
    for (int num : nums) {
      if (!min_pq_by_end.count(num - 1)) {
        min_pq_by_end[num].push(1);
      } else {
        if (min_pq_by_end[num - 1].empty())
          min_pq_by_end[num].push(1);
        else {
          int curr_seq_size = min_pq_by_end[num - 1].top();
          min_pq_by_end[num - 1].pop();
          min_pq_by_end[num].push(curr_seq_size + 1);
        }
      }
    }
    for (auto &[_, pq] : min_pq_by_end) {
      if (!pq.empty() && pq.top() < 3)
        return false;
    }
    return true;
  }
};