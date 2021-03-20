#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

/* Using KMP algorithm to match reversed s, rev_s, to s.
 * Get the common substring between rev_s and s which included the tail of rev_s
 * rev_s : abaaaa
 * s :       aaaaba
 * check which state it'll go after final state of j where rev[n-1] == s[j+1] & j > -1;
 */

class Solution {
public:
  string shortestPalindrome(string s) {
    int n = s.length();
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    vector<int> next(n, -1);
    build(s, next);

    int j = -1;
    for(int i = 0; i < n; ++i) {
      while(j > -1 && s[j+1] != rev_s[i])
        j = next[j];
      if(s[j+1] == rev_s[i]) {
        ++j;
      }
    }
    return rev_s.substr(0, n - (j + 1)) + s;
  }
private:
  void build(string& p, vector<int>& prev) {
    int j = -1;
    for(int i = 1; i < p.length(); ++i){
      while(j > -1 && p[j+1] != p[i])
        j = prev[j];
      if(p[j+1] == p[i]) ++j;
      prev[i] = j;
    }
  }
};
