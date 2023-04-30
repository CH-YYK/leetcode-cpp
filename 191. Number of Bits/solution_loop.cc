#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int res = 0;
    int base = 0;

    while((2 << base) <= n) {
      if((2 << base++) & n) res++;
    }
    return res;
  }
};
