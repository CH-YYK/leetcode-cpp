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
  int minimumPartition(string s, int k) {
    // greedy
    int n = s.size();
    int ans = 0;
    long num = 0;
    for (char c : s) {
      num = 10 * num + c - '0';
      if (num > k) {
        ans++;
        num = c - '0';
        if (num > k) return -1;
      }
    }
    return num <= k ? ans + 1 : ans + 2;
  }
};