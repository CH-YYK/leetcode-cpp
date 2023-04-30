// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // k partitions with minimum cost
  		// weights[0] and weights[n-1] must be invovled
  		// find k-1 adjacent pairs non overlapping pairs that make sum minimum
  		// A[0]..A[i1],A[i1+1]..A[i2],A[i2+1],...
  		// (A[0] + A[i1]) + (A[i1+1], A[i2]) + ...
  		// A[0] + (A[i1] + A[i1+1]) + (A[i2] + ..A[i2+1]) + ,,,
  		// specially we have i2 == i1 + 1
  		vector<int> candidates;
  		for(int i = 0; i < weights.size() - 1; ++i) 
  			candidates.push_back(weights[i] + weights[i+1]);
  		sort(candidates.begin(), candidates.end());

  		// A[0] and A[n-1] should be involved in both cases,
  		int min_ = 0, max_ = 0;
  		int n = candidates.size();
  		for(int i = 0; i < k-1; ++i) {
  			min_ += candidates[i];
  			max_ += candidates[n - 1 - i];
  		}
  		return max_ - min_;
    }
};