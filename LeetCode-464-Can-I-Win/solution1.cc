#include <vector>
using namespace std;

class Solution {
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal == 0)
      return true;
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
      return false;
    int picked = 0;
    m_ = vector<int>(1 << (maxChoosableInteger + 1), -1);
    return canIwin(maxChoosableInteger, desiredTotal, picked);
  }

private:
  vector<int> m_;
  bool canIwin(int M, int T, int picked) {
    if (T <= 0)
      return false;
    if (picked + 1 == 1 << (M + 1))
      return false;

    if (m_[picked] >= 0)
      return m_[picked];

    for (int i = 1; i <= M; ++i) {
      if (picked & (1 << i))
        continue;
      if (!canIwin(M, T - i, picked | (1 << i)))
        return true;
    }
    return m_[picked] = false;
  }
};
