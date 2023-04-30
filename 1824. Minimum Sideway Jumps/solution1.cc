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
    int minSideJumps(vector<int>& obstacles) {
		int j0 = 1, j1 = 0, j2 = 1;

		for(int i = 1; i < obstacles.size(); ++i) {
			int nj0 = j0, nj1 = j1, nj2 = j2;
			if(obstacles[i] == 1)
				nj0 = INT_MAX - 1;
			if(obstacles[i] == 2)
				nj1 = INT_MAX - 1;
			if(obstacles[i] == 3)
				nj2 = INT_MAX - 1;

			if(obstacles[i] != 1)
				nj0 = min(nj0, min(nj1 + 1, nj2 + 1));
			if(obstacles[i] != 2)
				nj1 = min(nj1, min(nj0 + 1, nj2 + 1));
			if(obstacles[i] != 3)
				nj2 = min(nj2, min(nj0 + 1, nj1 + 1));
            j0 = nj0, j1 = nj1, j2 = nj2;
		}
		return min(j0, min(j1, j2));
    }
};