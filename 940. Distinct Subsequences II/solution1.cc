#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int distinctSubseqII(string s) {
    int mod = 1e9 + 7;
    vector<long> ends(26, 0);
    // Optimized version:
    // keep track of the 'total' counts during the iteration to avoid summing up
    // all the counts everytime.
    long total = 0;
    for (char c : s) {
      long current = ends[c - 'a'];
      ends[c - 'a'] = (total + 1) % mod;
      if (total <= current)
        // Avoid conflicts because of modulo.
        total += mod;
      total = (total - current + ends[c - 'a']) % mod;
    }
    return total;
  }
};