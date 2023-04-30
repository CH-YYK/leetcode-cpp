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
    int passThePillow(int n, int time) {
        int tmp = time / (n - 1);
        int res = time % (n - 1);
        if(tmp % 2 == 0)
        	return 1 +  res;
        else
        	return n - res;
    }
};