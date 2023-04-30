// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
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
  vector<int> closestPrimes(int left, int right) {
    // left right, num1 num2
    vector<int> primes = getPrimes(right, left);
    if (primes.empty()) return {-1, -1};
    int mindiff = right - left;
    vector<int> ans = {-1, -1};
    for (int i = 1; i < primes.size(); ++i) {
      int diff = primes[i] - primes[i - 1];
      if (diff < mindiff) {
        ans[0] = primes[i - 1], ans[1] = primes[i];
        diff = mindiff;
      }
    }
    return ans;
  }

 private:
  vector<int> getPrimes(int n, int lower) {
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