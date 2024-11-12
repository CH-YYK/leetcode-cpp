#include <algorithm>
#include <limits>
#include <string>

class Solution {
public:
  int reverse(int x) {
    // If the number go outside of range of signed int, return 0.
    // The problem stated that the system doesn't allow for long type.
    int res = 0;
    int max_value = INT_MAX;
    int min_value = INT_MIN;
    while (x != 0) {
      if (res > 0 && (res > max_value / 10 || res * 10 > max_value - x % 10)) {
        return 0;
      }
      if (res < 0 && (res < min_value / 10 || res * 10 < min_value - x % 10)) {
        return 0;
      }
      res *= 10;
      res += x % 10;
      x /= 10;
    }
    return res;
  }
};