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
    while (sx < tx && sy < ty)
      if (tx < ty)
        ty %= tx;
      else
        tx %= ty;
    return sx == tx && sy <= ty && (ty - sy) % sx == 0 ||
           sy == ty && sx <= tx && (tx - sx) % sy == 0;
  }
};