#include <algorithm>
#include <limits>
#include <cstdint>>  // c standard int

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    int res = 0;
    short i = 0;
    while (n) {
      res += (n % 2) << (31 - i++);
      n /= 2;
    }
    return res;
  }
};
