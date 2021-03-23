#include <string>

using namespace std;

class Solution {
public:
  int secondHighest(string s) {
    int firstmax = -1, secondmax = -1;
    for (char &c : s) {
      if (!isdigit(c))
        continue;
      if (c - '0' > firstmax) {
        secondmax = firstmax;
        firstmax = c - '0';
      } else if (c - '0' > secondmax && c - '0' < firstmax)
        secondmax = c - '0';
    }
    return secondmax;
  }
};
