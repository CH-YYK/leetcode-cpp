// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <cmath>
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
  int findValidSplit(vector<int>& nums) {
    // prime factorization
    // there are 78k primes under 1m
    int max_ = *max_element(nums.begin(), nums.end());
    vector<int> sieveOfEratosthenes(max_);

    unordered_map<int,int> right, left;
    for(int num : nums) 
    	for(auto& [k,v] : getPrimeFactorsCounts(primes, num))
    		right[k] += v;

    for(int i = 0; i < nums.size() - 1; ++i) {
    	// if for the first time all cumulative primes factors 
    	// from the left is non-overlapping with the right
    	// return the index
    	int nonOverlapping = true;
    	for(auto& [k,v] : getPrimeFactorsCounts(primes, nums[i])) {
    		left[k] += v;
    		if(left[k] < right[k])
    			nonOverlapping = false;
    	}

    	if(nonOverlapping) return i;
    }
    return -1;
  }
 private:
  vector<int> sieveOfEratosthenes(int n) {
    //  O(n*log(log(n)))
    vector<int> isPrime(n + 1, 1);
    for (int p = 2; p * p <= n; p++) {
      // If prime[p] is not changed, then it is a prime
      if (isPrime[p]) {
        // Update all *multiples* of p greater than or
        // equal to the square of it numbers which are
        // multiple of p and are less than p^2 are
        // already been marked.
        for (int i = p * p; i <= n; i += p) isPrime[i] = 0;
      }
    }
    vector<int> primes;
    for (int p = 2; p <= n; ++p)
      if (isPrime[p]) primes.push_back(p);
    return primes;
  }
  unordered_map<int, int> getPrimeFactorsCounts(vector<int>& primes, int num) {
    int p = 0;
    unordered_map<int, int> factors;
    while (num > 1 && p < primes.size() && primes[p] <= num) {
      while (num % primes[p] == 0) {
        num /= primes[p];
        factors[primes[p]]++;
      }
      p++;
    }
    return factors;
  }
};