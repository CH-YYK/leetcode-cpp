// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
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
  int countHomogenous(string s) {
    // Homogenous substring: all chars are same
    // count("aaabb") = count("aaa") + count("bb")
    // count("aaa") = 3(1) + 2(2) + 1(3)
    // count("aaaa") = 4(1) + 3(2) + 2(3) + 1(4)
    // count("aaaaa") = 5(1) + 4(2) + 3(3) + 2(2) + 1(5)
    //
    int mod = 1e9 + 7;
    long ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      int j = i;
      while (j < s.size() && s[j] == s[i]) j++;
      long len = j - i;
      i = j - 1;
      if (len > 0) 
        ans = (ans + len * (len + 1) / 2 % mod) % mod;      
    }
    return ans;
  }
};