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
  string largestMerge(string w1, string w2) {
  	// O(N^2 + M^2)
  	// with std::string::compare
    string res;
    int i = 0, j = 0;
    while (i < w1.size() && j < w2.size()) {
      if (w1.compare(i, w1.size() - i, w2, j, w2.size() - j) > 0)
        res += w1[i++];
      else
        res += w2[j++];
    }
    return res + w1.substr(i) + w2.substr(j);
  }
};