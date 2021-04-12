#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;
    vector<string> cache;
    int width = 0, nspaces = 0;
    string ans;

    for(int i = 0; i < words.size(); ++i) {
      if(width + words[i].size() + cache.size() <= maxWidth) {
        cache.push_back(words[i]);
        width += words[i].size();
      } else {
        int allspaces = (maxWidth - width);
        nspaces = cache.size() - 1;
        if(nspaces == 0)  // there is only one word
          ans += cache[0] + string(allspaces, ' ');
        else {
          int extraspaces = allspaces % nspaces;
          int perspaces = allspaces / nspaces;

          for(int j = 0; j < cache.size(); ++j) {
            ans += cache[j];
            if(j < cache.size() - 1) {
              if (extraspaces-- > 0)
                ans += string(perspaces + 1, ' ');
              else
                ans += string(perspaces, ' ');
            }
          }
        }
        res.emplace_back(move(ans));
        cache.clear();
        cache.push_back(words[i]);
        width = words[i].size();
      }
    }
    for(int j = 0; j < cache.size(); ++j)
      if(j == cache.size() - 1) ans += cache[j];
      else ans += (cache[j] + ' ');
    ans += string(maxWidth - ans.size(), ' ');
    res.emplace_back(move(ans));
    return res;
  }
};
