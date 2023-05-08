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
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        // answer[i] := number of adjacent elements with same coler after ith
        // a color change can result in change in 
        //  left: nums[i] == nums[i-1]
        //  right: nums[i] == nums[i+1]
        vector<int> arr(n, 0);
        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); ++i) {
        	int ind = queries[i][0];
        	int color = queries[i][1];
        	if(i == 0) {
        		arr[ind] = color;
        		continue;
        	}
        	int cnt = ans[i - 1];
        	// check left
        	if(ind > 0 && arr[ind] != color) {
        		if(arr[ind] > 0 && arr[ind] == arr[ind - 1])
        			cnt--;
        		else if(arr[ind - 1] == color)
        			cnt++;
        	}
        	if(ind < n - 1 && arr[ind] != color) {
        		if(arr[ind] > 0 && arr[ind] == arr[ind + 1])
        			cnt--;
        		else if(arr[ind + 1] == color)
        			cnt++;
        	}
        	arr[ind] = color;
        	ans[i] = cnt;
        }
        return ans;
    }
};