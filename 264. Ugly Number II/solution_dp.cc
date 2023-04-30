#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    unordered_map<int, bool> m;
    m[0] = false, m[1] = true;
    int i = 0;
    int primes[3] = {2, 3, 5};
    for (int num = 1; num < 10000000000; ++num) {
      int tmp = num;
      for (int prime : primes) {
        while (tmp % prime == 0) {
          if (m.count(tmp))
            break;
          tmp /= prime;
        }
        if(m.count(tmp)) break;
      }
      m[num] = m[tmp];
      if (m[num])
        i++;
      if (i == n)
        return num;
    }
    return -1;
  }
};
