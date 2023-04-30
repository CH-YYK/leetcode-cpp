#include <string>

using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    int len = 0, n = s.size();
    for(int j = 0; j < n; ++j)
      if(ispalindrome(s, 0, j))
        len = max(len, j + 1);
    string res;
    for(int i = n-1; i >= len; --i)
      res += s[i];
    return res + s;
  }
private:
  bool ispalindrome(string& s, int i, int j) {
    if(i > j) return true;
    if(i == j) return true;
    if(s[i] == s[j]) return ispalindrome(s, i+1, j-1);
    return false;
  }
};
