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
    int captureForts(vector<int>& forts) {
  		// 
  		int ans = 0;
        int n = forts.size();
  		int empty = -1;
  		// move left
  		for(int i = 0; i < forts.size(); ++i) {
  			if(forts[i] == 0)
  				continue;
  			if(forts[i] == -1)
  				empty = i;
  			if(forts[i] == 1 && empty != -1) {
  				ans = max(ans, i - empty - 1);
  				empty = -1;
  			}
  		}

  		empty = -1;
  		// move right
  		for(int i = n - 1; i >= 0; --i) {
  			if(forts[i] == 0)
  				continue;
  			if(forts[i] == -1)
  				empty = i;
  			if(forts[i] == 1 && empty != -1) {
  				ans = max(ans, empty - i - 1);
  				empty = -1;
  			}
  		}
  		return ans;

  		// move r
    }
};