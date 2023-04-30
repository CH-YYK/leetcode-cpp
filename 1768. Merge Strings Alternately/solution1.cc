#include <string>

using namespace std;


class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    // alternating order : 交替顺序
    string res;
    int a = 0, b = 0;
    while(a < word1.size() || b < word2.size()) {
      if(a < word1.size())
        res += word1[a];
      if(b < word2.size())
        res += word2[b];
      ++a, ++b;
    }
    return res;
  }
};

