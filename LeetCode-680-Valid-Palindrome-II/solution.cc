#include <string>

using namespace std;

class Solution {
public:
  bool validPalindrome(string s) {
    deleted = false;
    return helper(s, 0, s.size() - 1);
  }
private:
  bool deleted;
  bool helper(string& s, int l, int r) {
    if(l >= r) return true;
    if(s[l] != s[r]) {
      if(!deleted) {
        deleted = true;
        return helper(s, l+1, r) or helper(s, l, r-1);
      }
      return false;
    }
    return helper(s, l+1, r-1);
  }
};

