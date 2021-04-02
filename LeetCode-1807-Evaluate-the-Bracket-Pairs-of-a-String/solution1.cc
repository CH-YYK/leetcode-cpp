#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // take care of string copy
  string evaluate(string s, vector<vector<string>> &knowledge) {
    unordered_map<string, string> m;
    for (auto p : knowledge) {
      m[p[0]] = p[1];
    }
    string res, ptn;
    for (char c : s) {
      if (c == '(') {
        res += ptn;
        ptn = string();
      } else if (c == ')') {
        ptn = m.count(ptn) ? m[ptn] : "?";
        res += ptn;
        ptn = string();
      } else
        ptn += c;
    }
    return res + ptn;
  }
};
