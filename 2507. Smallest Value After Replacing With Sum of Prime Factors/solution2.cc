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

class Solution {
 public:
  int p[65] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,
               43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101,
               103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
               173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
               241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
  int smallestValue(int n) {
    int sum = 0, res = n;
    for (int i = 0; i < 65 && res >= p[i]; ++i)
      while (res % p[i] == 0) {
        sum += p[i];
        res /= p[i];
      }
    return (sum == 0 || sum == n) ? n
                                  : smallestValue(sum + (res == 1 ? 0 : res));
  }
};