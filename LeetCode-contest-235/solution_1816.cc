#include <string>
using namespace std;

class Solution {
public:
  string truncateSentence(string s, int k) {
    s.push_back(' ');
    for(int i = 0; i < s.size(); ++i) {
      if(s[i] == ' ') k--;
      if(k == 0) return s.substr(0, i);
    }
    return s;
  }
};
