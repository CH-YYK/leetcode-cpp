// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
 public:
  int distinctPrimeFactors(vector<int>& nums) {
    // 10^7
    // get primes
    //
    // res = primes[num[0]] + primes[nums[1]]
    primes = getPrimesUnderN(1000);
    unordered_set<int> s;
    for (int num : nums) {
      int p = 0;
      while (p < primes.size() && primes[p] <= num && num > 1) {
        if (num % primes[p] == 0) {
          num /= primes[p];
          s.insert(primes[p]);
        }
        p++;
      }
    }
    return s.size();
  }

 private:
  vector<int> primes;
  vector<int> getPrimesUnderN(int n) {
    vector<int> isPrime(n + 1, 1);
    for (int p = 2; p * p <= n; p++) {
      if (isPrime[p]) {
        for (int i = p * p; i <= n; i += p) isPrime[i] = 0;
      }
    }
    vector<int> primes;
    for (int p = 2; p <= n; ++p)
      if (isPrime[p]) primes.push_back(p);
    return primes;
  }
};