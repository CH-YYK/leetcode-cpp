#include <vector>
#include <utility>
#include <queue>
using namespace std;

/* Using maxHeap
 * * In heap, we are storing [distance, num] where num refer how many parts the distance should be divided into
 * * Greadily, we want to insert new stations to the largest interval, so that largest distance can be eliminated from heap
 * O(NlogN + KlogN) = O((N + K) logN)
 */
struct cmp_pair {
  bool operator()(pair<double, int> &lhs, pair<double, int> &rhs) {
    return lhs.first / lhs.second < rhs.first / rhs.second;
  }
};

class Solution {
public:
  double minmaxGasDist(vector<int> &stations, int k) {
    priority_queue<pair<double, int>, vector<double, int>, cmp_pair> pq;
    for (int i = 1; i < stations.size(); ++i)
      pq.push({stations[i] - stations[i - 1], 1});

    for (int i = 0; i < k; ++i) {
      auto [dist, num] = pq.top();
      pq.pop();
      pq.push({dist, num + 1});
    }
    auto [dist, num] = pq.top();
    return dist / num;
  }
};
