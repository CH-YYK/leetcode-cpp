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
  char repeatedCharacter(string s) {
    int state = 0;
    for (char c : s) {
      if (state & (1 << (c - 'a'))) return c;
      state |= (1 << (c - 'a'));
    }
    return 'a';
  }
};