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
    	// brute force
    	int n = s.size();
    	int ans = 0;
    	for(int i = 0; i < n; ++i){
            int freq[26] = {};
    		int max_ = 0;
    		for(int j = i; j < n; ++j){
    			max_ = max(max_, ++freq[s[j] - 'a']);
    			int min_ = INT_MAX;
    			for(int k = 0; k < 26; ++k)
                    min_ = min(min_, freq[k] == 0 ? INT_MAX : freq[k]);	  
                ans += max_ - min_;
    		}
    		
    	}
    	return ans;
    }
};

int main() {
    
}
