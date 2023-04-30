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

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/


class Solution {
public:
    int minimumBoxes(int n) {
    	// 1 + (1 + 2) + (1 + 2 + 3) 
    	// SUM i(i+1)/2 = (i^2 + i)/2 
        // i(i+1)(2i+1)/6 + i(i+1)/2 <= n
        // find largest i to make above work
        // 
        // for the rest, find largest j j(j+1)/2 <= rest
        // return j+1
        // binary search       
        int ans = 0;
        long m = resolve1(n);
        ans += m * (m + 1) / 2;
        n -= func1(m);
        m = resolve2(n);
        ans += m;
        n -= func2(m);
        return ans + (n > 0);
    }
private:
	long func1(long x) {
		return (x * (x + 1) * (2 * x + 1) / 6 + x * (x + 1) / 2) / 2;
	}
	long func2(long x) {
		return x * (x + 1) / 2;
	}
	long resolve1(long n) {
		long l = 0, r = sqrt(n) + 1;
		while(l < r) {
			long m = (l + r + 1) / 2;
			long tmp = func1(m);
			if(tmp <= n) {
				l = m;
			} else r = m - 1; 
		}
		return l;
	}

	long resolve2(int n) {
		long l = 0, r = sqrt(2*n);
		while(l < r) {
			long m = (l + r + 1) / 2;
			long tmp = func2(m);
			if(tmp <= n) 
				l = m;
			else r = m - 1;
		}
		return l;
	}
};