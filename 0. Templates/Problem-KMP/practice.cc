#include <string>
#include <vector>

using namespace std;

/* match state: -1 -> next match start from p[0]
 * match state: i -> next match start from p[i+1]
 * match state: p.len -1 -> match complete
 *
 * build state: -1 -> initial state to next[0]
 * build state: 
 */

namespace KMP {
void build(string &p, vector<int> &next) { // next(p.len, -1)
  int j = -1;                              // initial state
  for (int i = 1; i < p.length(); ++i) {
    while (j > -1 && p[j + 1] != p[i]) // revert to previous state
      j = next[j];
    if (p[j + 1] == p[i]) // advance state if pattern matched at current state
      ++j;
    next[i] = j;
  }
}

  int match(string s, string p) {
    int j = -1;
    vector<int> next(p.length(), -1);
    build(p, next);

    for(int i = 0; i < s.length(); ++i) {
      while(j > -1 && s[i] != p[j+1])
        j = next[j];
      if(p[j + 1] == s[i]) ++j;  // advance state if pattern matched at current state
      if(j+1 == p.length()) return i - j; // first index where matched substr start
    }
    return -1;
  }

}
