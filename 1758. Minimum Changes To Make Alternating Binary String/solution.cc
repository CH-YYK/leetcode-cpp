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

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        // it can either be 10101 or 01010
        // easy enumerating
        int start = 0;
        function<int(int)> numOperations = [&](int start) {
        	int ans = 0;
        	for (char c : s) {
        		if(c - '0' != start) ans++;
        		start ^= 1;
        	}
        	return ans;
        };
        return min(numOperations(0), numOperations(1));
    }
};

int main() {
    
}
