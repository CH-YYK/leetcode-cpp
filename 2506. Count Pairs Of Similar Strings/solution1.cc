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
    function<bool(string&, string&)> isEqual = [](string& lhs, string& rhs) {
      vector<int> chars1(26, 0);
      vector<int> chars2(26, 0);
      for (char c : lhs) chars1[c - 'a'] = 1;
      for (char c : rhs) chars2[c - 'a'] = 1;
      return chars1 == chars2;
    };
    int ans = 0;
    for (int i = 0; i < words.size(); ++i)
      for (int j = i + 1; j < words.size(); ++j)
        if (isEqual(words[i], words[j])) ans++;
    return ans;
  }
};