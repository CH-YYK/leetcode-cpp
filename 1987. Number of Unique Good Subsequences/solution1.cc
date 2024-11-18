#include <string>

using namespace std;

class Solution {
public:
  int numberOfUniqueGoodSubsequences(string binary) {
    // The main challenge is how to dedupe the subsequences.

    // We gradually create subsequences by adding a 1 or 0 to the end of the
    // current subsequences. The state to track here is the 'count' of the
    // 'unique' subsequences.
    //
    // Say, we let
    //   str_ends1 = the set of unique subsequences ending with 1
    //   str_ends0 = the set of unique subsequences ending with 0
    //   ends1 = the count of unique subsequences ending with 1
    //   ends0 = the count of unique subsequences ending with 0
    //
    // Then, if we add '1' to all existing subsequences, we get
    //   new_ends1 = ends0 + ends1.
    //   new_ends0 = ends0 + ends1.
    // They are guaranteed to be unique because:
    //   (1) `str_ends1` is already unique, so adding a '1' to each them does
    //   not create a set with duplicates. (2) similarly to `str_ends0`.
    //
    // For simplicity, we won't consider the case of single '0' here, so we'll
    // anyway start from a '1'.
    //
    // Initially, ends1 = 0 and ends0 = 0. Each expansion of str_ends1 should consider "1".
    // So the updated version is
    //   new_ends1 = ends0 + ends1 + 1
    //   new_ends0 = ends0 + ends1
    int mod = 1e9 + 7;
    long ends1 = 0, ends0 = 0;
    long has_zero = 0;
    for (char c : binary) {
      if (c == '1') {
        ends1 = (ends0 + ends1 + 1) % mod;
      } else {
        ends0 = (ends0 + ends1) % mod;
        has_zero = 1;
      }
    }
    return (ends1 + ends0 + has_zero) % mod;
  }
};