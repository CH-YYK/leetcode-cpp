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
  long long minCost(vector<int>& basket1, vector<int>& basket2) {
    // trade between basket1 and basket2
    // 1. no need to swap common numbers
    // 2. for numbers that are not common, equally distributted between 1 and 2
    // 3. how to swap with minimum cost?
    // 		- within "to be swapped" numbers, swap a smallest with the
    // largest
    // 		- use a global min as a intermediate to swap forward and
    // backforward
    unordered_map<int, long long> cnt;
    for (int num : basket1) cnt[num]++;
    for (int num : basket2) cnt[num]--;
    vector<int> swapped;
    for (auto& [k, v] : cnt) {
      if (v % 2) return -1;
      for (int i = 0; i < abs(v) / 2; ++i) swapped.push_back(k);
    }
    // evenly distributed swappable numbers
    nth_element(swapped.begin(), swapped.begin() + swapped.size() / 2,
                swapped.end());

    // find a global min
    int min_ = min(*min_element(basket1.begin(), basket1.end()),
                   *min_element(basket2.begin(), basket2.end()));
    long long ans = 0;
    for (int i = 0; i < swapped.size() / 2; ++i) {
      ans += min(swapped[i], 2 * min_);
    }
    return ans;
  }
};