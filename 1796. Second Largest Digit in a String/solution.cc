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
  int secondHighest(string s) {
    int first = -1, second = -1;
    for (char c : s) {
      if (isdigit(c)) {
        if (c - '0' == first || c - '0' == second)
          continue;
        if (c - '0' > first) {
          second = first;
          first = c - '0';
        } else if (c - '0' > second) {
          second = c - '0';
        }
      }
    }
    return second == first ? -1 : second;
  }
};

int main() {}
