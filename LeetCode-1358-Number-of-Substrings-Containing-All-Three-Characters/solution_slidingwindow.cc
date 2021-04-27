#include <string>
#include <vector>
using namespace std;

/* Substring problem -> sliding window
 * window state: arr[3], arr[0]>0 && arr[1]>0 && arr[2]>0,
 * * valid substring[l, r] (right inclusive)
 * * add all superstring [l, r+i] where i in [0, n-1-i] -> res += n-1-i+1 = n - i
 */
class Solution {
public:
  int numberOfSubstrings(string s) {
    int l = 0, res = 0, n = s.size();
    vector<int> cnt(3, 0);
    for (int r = 0; r < s.size(); ++r) {
      cnt[s[r] - 'a']++;
      while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
        res += n - r;
        cnt[s[l++] - 'a']--;
      }
    }
    return res;
  }
};
