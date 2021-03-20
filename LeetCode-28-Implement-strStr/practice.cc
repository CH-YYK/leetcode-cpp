#include <string>
#include <vector>

using namespace std;

/* match
 * 1. Next(p.length): list where states transit over pattern
 * 2. state/pos: i -> match start from p[i+1]
 * 3. when going to the next state (where matching failed at s[i]),
 *  try start matching s[i] and p[j+1] with next j
 *
 * build
 * 1. advance state at next[i] if p[j+1] == p[i]
 */
class Solution {
public:
  int strStr(string haystack, string needle) {
    int j = -1;
    int m = haystack.length();
    int n = needle.length();

    vector<int> next(n, -1);
    build(needle, next);

    for(int i = 0; i < m; ++i) {
      while(j > -1 && needle[j+1] != haystack[i])
        j = next[j];
      if(needle[j+1] == haystack[i])
        j++;
      if(j == n-1) return i - n + 1;  // final state
    }
    return -1;
  }
private:
  void build(string& p, vector<int>& next) {
    int j = -1; // initial state  [-1, n-1]
    int n = p.length();
    for(int i = 1; i < n; ++i) {  // start from 1 as first state is -1 bydefault
      while(j > -1 && p[j+1] != p[i])
        j = next[j];
      if(p[j+1] == p[i]) ++j;  // 
      next[i] = j;
    }

  }
};
