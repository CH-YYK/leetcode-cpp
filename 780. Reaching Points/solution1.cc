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
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    // (x, y) -> (x, x + y) or (x + y, y)
    // reversed
    // (tx, ty) -> (x + y, y) -> (tx - ty, ty)
    if (sx == tx && sy == ty) return true;
    if (tx < sx || ty < sy) return false;

    if (tx > ty) {
      if(tx - sx < ty) return false;
      return reachingPoints(sx, sy, tx - (tx - sx) / ty * ty, ty);
    } else {
      if(ty - sy < tx) return false;
      return reachingPoints(sx, sy, tx, ty - (ty - sy) / tx * tx);
    }
  }
};