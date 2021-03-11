#include <string>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
  bool isValidSerialization(string preorder) {
    if(preorder[0] == '#') return preorder.size() == 1;
    preorder.push_back(',');  // add ',' to make all elements in preorder be processed.

    stack<pair<int, int>> s;
    int num = 0, init = 1;
    char prev;

    for (char c : preorder) {
      if(isdigit(c))
        num = 10 * num + (c - '0');
      else if(c == ',') {
        if (s.empty()) {
          if (prev == '#')
            return false;
          if(init--) s.emplace(num, 2);
          else return false;  // false if stack empty again
        } else {
          s.top().second--;
          if (prev != '#')
            s.emplace(num, 2);
          while (!s.empty() && s.top().second == 0)
            s.pop();
        }
        num = 0;
      }
      prev = c;
    }
    return s.empty();
  }
};

// test cases
// 9,3,4,#,#,1,#,#,2,#,6,#,#
