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
    int maxDistance(vector<int>& position, int m) {
		// binary search to place balls with inner force k
		sort(position.begin(), position.end());
    	int l = 0, r = 1e9;
    	while(l < r) {
    		int mid = (l + r + 1) / 2;
    		int k = 1, prev = position[0];
    		for(int i = 1; i < position.size(); ++i)
    			if(position[i] - prev >= mid)
    				k++, prev = position[i];
    		if(k >= m) // increase mid to get low k
    			l = mid;
    		else
    			r = mid - 1;
    	}
    	return l;
    }
};