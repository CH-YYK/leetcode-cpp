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
    int pivotInteger(int n) {
    	// todo: binary search
  		int sum = n * (n + 1) / 2;
  		// find x such that y = x*(x + 1) / 2 and sum = 2 * y
		function<int(int)> y = [&](int x) {
			return x * (x + 1) / 2;
		};
		for(int i = 1; i <= n; ++i) {
			if(y(i) * 2 == sum + i)
				return i;
		}
		return -1;
    }
};

int main() {
    
}