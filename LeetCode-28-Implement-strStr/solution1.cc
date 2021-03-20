#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) { // haystack: str, needle: pattern
    int k = -1, n = haystack.length(), p = needle.length();
    if(p == 0) return 0;
    vector<int> next(p, -1);

    callNext(needle, next);

    for(int i = 0; i < n; ++i) {
      while(k > -1 && needle[k+1] != haystack[i])
        k = next[k];
      if(needle[k+1] == haystack[i])
        ++k;
      if(k == p-1)
        return i - p + 1;
    }
    return -1;
  }
private:
  void callNext(const string& needle, vector<int>& next){
    for(int j = 1, p = -1; j < needle.length(); ++j) {
      while(p > -1 && needle[p+1] != needle[j])
        p = next[p];
      if(needle[p+1] == needle[j])
        ++p;
      next[j] = p;
    }
  }
};
