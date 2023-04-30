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
  		// find x such that y = x*(x + 1) / 2 and sum + x = 2 * y
		function<int(int)> y = [&](int x) {
			return x * (x + 1) / 2 * 2 - x; // x * x
		};
		int l = 0, r = n;
		while(l < r) {
			int m = (l + r) / 2;
			int ym = y(m);
			if(ym == sum) 
				return m;
			else if(ym > sum)
				r = m - 1;
			else
				l = m + 1;
		}
		return -1;
    }
};

int main() {
    
}