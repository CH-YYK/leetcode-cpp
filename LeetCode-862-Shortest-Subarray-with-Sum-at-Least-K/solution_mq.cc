#include <vector>
#include <deque>
using namespace std;

/* Find the minimum length of subarray whose sum is at least K
 * Sh - Sl >= K -> Sh - K >= Sl
 * * we maintain a monotonic queue where Sl are ordered increasingly
 * * front() of queue is the minimum Sl and we hope Sh - dq.front() >= K
 * * we pop front() of queue to get shorter size of array
 */
class Solution {
public:
  int shortestSubarray(vector<int> &A, int K) {
    if (A.size() == 1)
      return A[0] >= K ? 1 : -1;
    deque<int> dq; // put smallest Sl at left, is a [Sl Sh] work, for Sl, find
                   // nearest Sh that Sh - Sl >= K
    int len = 1e9;
    vector<int> presum(A.size() + 1, 0);
    for (int i = 0; i < A.size(); ++i)
      presum[i + 1] = presum[i] + A[i];
    for (int i = 0; i < presum.size(); ++i) {
      // pop from front to get smaller subarray
      while (!dq.empty() && presum[i] - presum[dq.front()] >= K) {
        len = min(len, i - dq.front());
        dq.pop_front();
      }

      while (!dq.empty() && presum[i] <= presum[dq.back()])
        dq.pop_back();
      dq.push_back(i);
    }
    return len == 1e9 ? -1 : len;
  }
};
