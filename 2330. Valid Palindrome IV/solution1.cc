// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
 public:
  bool makePalindrome(string s) {
    int n = s.size();
    int l = 0, r = n - 1;
    int k = 2;
    while (l < r) {
      if (s[l] == s[r] || k-- > 0)
        l++, r--;
      else
        return false;
    }
    return true;
  }
};