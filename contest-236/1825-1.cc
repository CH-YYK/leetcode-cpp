#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

/* BST of size m
 *
 */
class MKAverage {
public:
  MKAverage(int m, int k) {
    m_ = m;
    k_ = k;
  }

  void addElement(int num) {
    if (bucket.size() == m_) {
      bucket.erase(q.front());
      q.pop();
    }
    q.push(bucket.insert(num));
  }

  int calculateMKAverage() {
    if (q.size() < m_)
      return -1;

    auto it = bucket.begin();
    int counts = m_ - 2 * k_;
    long sum_ = 0;
    int t = 0;
    while(t++ < k_) it++;
    while(counts--) sum_ += *it++;
    return sum_ / (m_ - 2 * k_);
  }

private:
  int m_, k_;
  multiset<int> bucket;
  queue<multiset<int>::iterator> q;
};
