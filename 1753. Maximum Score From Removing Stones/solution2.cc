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
    int maximumScore(int a, int b, int c) {
    	// recursively makesure a >= b and a >= c
    	if(a < b)
    		return maximumScore(b, a, c);
    	if(a < c)
    		return maximumScore(c, b, a);
    	if(b + c <= a)
    		return b + c;
    	else return (a + b + c) / 2;
    }
};