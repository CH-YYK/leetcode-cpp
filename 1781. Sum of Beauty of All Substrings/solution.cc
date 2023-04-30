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

using namespace std;

class Solution {
public:
    int beautySum(string s) {
		// need to try substring O(26*N^2)
		// prefix sum of 26 characters
		int n = s.size();
		vector<vector<int>> prefixSum(n + 1, vector<int>(26, 0));
		for(int i = 0; i < n; ++i) {
			prefixSum[i+1][s[i] - 'a']++;
			for(int j = 0; j < 26; ++j) 
				prefixSum[i+1][j] += prefixSum[i][j];
		}

		int ans = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				int max_ = 0, min_ = n;
				for(int k = 0; k < 26; ++k) {
					int freq = prefixSum[j + 1][k] - prefixSum[i][k];
                    if(freq == 0) continue;
					max_ = max(max_, freq);
					min_ = min(min_, freq);
				}
				ans += max_ - min_;
			}
		}
		return ans;
    }
};

int main() {
    
}
