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

int main() {}

class Solution {
 public:
  int similarPairs(vector<string>& words) {
    function<int(string&)> convert = [](string& w) {
      int state = 0;
      for(char c : w)
        state |= 1 << (c - 'a');
      return state;
    };
    // counts O(N)
    unordered_map<int, int> mp;
    int ans = 0;
    for(string& w : words) {
      int state = convert(w);
      ans += mp[state];
      mp[state]++;
    }
    return ans;
  }
};