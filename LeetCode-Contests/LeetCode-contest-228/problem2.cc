#include <string.h>

using namespace std;
/*
 * 5677. Count Number of Homogenous Substrings
 */

class Solution {
 public:
  int countHomogenous(string s) {
    if(s.empty()) return 0;
        
    int l = 0, r = 1;
    long res = 0;
    long n;
    for(; r < s.size(); ++r) {
      if(s[l] != s[r]) {
        n = r - l;
        res += n*(n+1)/2;
        l = r;
      }
    }
    n = r - l;
    res += n * (n+1) /2;
    return res % 1000000007;
  }
};
