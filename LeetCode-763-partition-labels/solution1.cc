#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string S) {
    if(S.empty()) return {};

    vector<int> res;
    unordered_set<char> set_;
    unordered_map<char, int> map_;

    for(char c : S) map_[c]++;

    int l = -1;
    char c;

    for(int r = 0 ; r < S.size(); ++r) {
      c = S[r];
      set_.insert(c);

      if(--map_[c] == 0) set_.erase(c);

      if(set_.empty()) {
        res.push_back(r - l);
        l = r;
      }
    }
    return res;
  }
};
