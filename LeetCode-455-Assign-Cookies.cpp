class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int j = 0;
    int m = g.size(), n = s.size();

    int res = 0;
    for(int i = 0; i < n; ++i) {
      if(j < m && s[i] >= g[j]) ++res, ++j;
    }
    return res;
  }
};