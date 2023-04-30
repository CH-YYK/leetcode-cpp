// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    // find an x that divides str1 and str2
    // find common prefix
    //
    return str1.size() > str2.size() ? gcd(str1, str2, 0, 0) : gcd(str2, str1, 0, 0);
  }

 private:
  string gcd(string& s1, string& s2, int i1, int i2) {
    // use s2 to consume s1 until s1.size() <= s2.size()
    int n1 = s1.size(), n2 = s2.size();
    int origin = i2;

    for (int i = i1; i < n1; ++i) {
      if (s1[i] == s2[i2])
        i2++;
      else
        return string();
      if (i2 == n2) i2 = origin;
    }
    if (i2 == origin) return s2.substr(origin);
    return gcd(s2, s2, origin, i2);
  }
};