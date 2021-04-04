#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> s1 = split(sentence1), s2 = split(sentence2);

    int n1 = s1.size(), n2 = s2.size();
    int l1 = 0, l2 = 0, r1 = n1-1, r2 = n2-1;
    while(l1 <= r1 && l2 <= r2) {
      if(s1[l1] == s2[l2] || s1[r1] == s2[r2]) {
        if (s1[r1] == s2[r2]) r1--, r2--;
        if (s1[l1] == s2[l2]) l1++, l2++;
      }else return false;
    }
    return l1 > r1 || l2 > r2;
  }
private:
  vector<string> split(string& s) {
    vector<string> res;
    string ptn;
    for(char c : s) {
      if(c == ' ') res.emplace_back(ptn), ptn.clear();
      else ptn += c;
    }
    res.push_back(ptn);
    return res;
  }
};
