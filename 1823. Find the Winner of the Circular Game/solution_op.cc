#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
  int findTheWinner(int n, int k) {
    set<int> s;
    for (int i = 1; i <= n; ++i)
      s.insert(s.end(), i);

    auto it = begin(s);
    while (s.size() > 1) {
      if (it == end(s))
        it = begin(s);
      for (int j = 0; j < k; ++j)
        if (++it == end(s))
          it = begin(s);
      s.erase(it++);
    }
    return *s.begin();
  }
};
