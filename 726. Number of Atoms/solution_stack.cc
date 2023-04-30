#include <map>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  string countOfAtoms(string formula) {
    formula.push_back('A');
    stack<map<string, int>> s;

    map<string, int> b;

    string ptn = "";
    char prev;
    int num = 0;
    for(char c : formula)  {
      if(isdigit(c)) {   // process number
        num = 10 * num + (c - '0');
      } else {  // end of last pattern/sub-pattern
        if (num == 0) num = 1;
        if(c - 'a' >= 0 && c - 'a' <= 26) {
          ptn += c;
        } else {
          // handle the last pattern/sub-pattern
          // prev == ')', last one is a sub-pattern
          // else, last one is a pattern
          if (prev == ')' && !s.empty()) {
            multiply(b, num);
            merge(s.top(), b);
            b = s.top();
            s.pop();
          } else if(!ptn.empty()){// edge case
            b[ptn] += num == 0 ? 1 : num;
          }

          // new pattern: initialize current as a starter
          if(c - 'A' >= 0 && c - 'A' <= 26) {
            ptn = c;
          }
          // new sub-pattern: no initialization but ot remove the last
          if(c == '(') {
            s.push(b);
            b = map<string, int>();
            ptn = "";
          }
        }
      num = 0;
      prev = c;
      }
    }
    string res;
    for(auto p : b) {
      res += p.first;
      if(p.second > 1)
        res += to_string(p.second);
    }
    return res;
  }
private:
  void merge(map<string, int>& old,
             map<string, int>& fresh) {
    for(auto p : fresh) {
      old[p.first] += p.second;
    }
  }

  void multiply(map<string, int>& old, int num) {
    for(auto p : old) {
      old[p.first] = p.second * num;
    }
  }
};

