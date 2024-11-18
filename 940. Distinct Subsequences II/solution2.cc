#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int distinctSubseqII(string s) {
    int mod = 1e9 + 7;
    vector<long> ends(26, 0);
    for (char c : s) {
      // New and distinct subsequences ending with 'char c' could be created by
      // appending 'char c' to all the existing and unique subsequences.
      long total = accumulate(ends.begin(), ends.end(), 0l);
      ends[c - 'a'] = (total + 1) % mod;
    }
    return accumulate(ends.begin(), ends.end(), 0l) % mod;
  }
};