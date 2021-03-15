#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    int n = s1.size();
    vector<int> pos;

    for(int i = 0; i < n; ++i) {
      if(s1[i] == s2[i]) continue;
      else {
        if(pos.size() == 2) return false;
        pos.push_back(i);
      }
    }

    if(pos.empty()) return true;
    else if(pos.size() == 1) return false;
    return s1[pos[0]] == s2[pos[1]] && s1[pos[1]] == s2[pos[0]];
  }
};
