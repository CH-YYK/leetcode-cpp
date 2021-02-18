#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp_str(const string& lhs, const string& rhs) {
  if(lhs.size() > rhs.size()) return true; // longer string
  else if(lhs.size() == rhs.size()) // less lexical order
    return lhs.compare(rhs) < 0;
  else return false;
}

class Solution {
public:
  string findLongestWord(string s, vector<string>& d) {
    vector<const char*> _pchars(d.size());
    for(int i = 0; i < d.size(); ++i) {
      _pchars[i] = d[i].data();
    }

    vector<string> res;

    // one-pointer for orgin vs multiple pointers on others
    for(int i = 0; i < s.size(); ++i) {
      for(const char*& _pchar : _pchars)
        if(*_pchar == s[i]) ++_pchar;
    }

    for(int j = 0; j < d.size(); ++j)
      if(*_pchars[j] == '\0') res.push_back(d[j]);

    sort(res.begin(), res.end(), comp_str);
    return res.empty() ? "" : res[0];
  }
};

