#include <string>

using namespace std;
/* 5676. Minimum Changes To Make Alternating Binary String
 */

class Solution {
 public:
  int minOperations(string s) {
    /* Respectively go through 010101 or 101010
     *  and compare
     */
    if(s.empty()) return 0;

    int res1 = 0, res2 = 0;
    int base = 0;
    for(char c : s) {
      if(base ^ (c - '0')) ++res1;
      base = (base == 0);
    }

    base = 1;
    for(char c : s) {
      if(base ^ (c - '0')) ++res2;
      base = (base == 0);
    }

    // printf("%d", min(res1, res2));
    return min(res1, res2);
  }
};
