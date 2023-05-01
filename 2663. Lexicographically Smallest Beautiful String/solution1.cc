;  // Hello, this is a CPP leetcode snippet.

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
  string smallestBeautifulString(string s, int k) {
    // Construct the new string
    // Rule 1: the given `s` is a beautiful string
    // Rule 2: feel free to create a new beautiful string
    //
    // Loop from right to left and try incrementing each s[i] s.t.
    //   s[i] != s[i-1] and s[i] != s[i-2] and s[i] < 'a' + k;
    // 	(we don't need to consider ealier ones like s[i-3], because s[i-2] and
    // s[i-1]
    //   must not be a palindrome)
    //
    // Once we find the s[i], rebuild the s[i+1:] with a lexically smallest
    // non-palindrome string
    //   i.e. s[i] != s[i-1] && s[i] != s[i-2], (abcabcabc)
    int n = s.size();
    int i = n - 1;
    for (int i = n - 1; i >= 0; --i) {
      s[i]++;
      while (!isValid(s, i) && s[i] < 'a' + k) {
        s[i]++;
      }
      if (s[i] >= 'a' + k) continue;

      for (int j = i + 1; j < n; ++j) {
        s[j] = 'a';
        while (!isValid(s, j) && s[j] < 'a' + k) s[j]++;
      }
      return s;
    }
    return "";
  }

 private:
  bool isValid(string& s, int i) {
    if (i > 0 && s[i] == s[i - 1]) return false;
    if (i > 1 && s[i] == s[i - 2]) return false;
    return true;
  }
};