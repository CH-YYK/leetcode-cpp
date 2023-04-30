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

int gcd(int a, int b) {
	// must carefully using __gcd(a,b) when b = 0
	// b ? gcd(b, a % b) : a;
	if(b == 0) return a;
	a %= b;
	return gcd(b, a);
}

inline int gcd_iter(int a, int b) {
	while(b!=0) {
		swap(b, a %= b);		
	}
	return a;
}
