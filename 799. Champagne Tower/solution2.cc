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
    double champagneTower(int poured, int query_row, int query_glass) {
    	// simulation
    	// save one dimension
    	// arr[i][j] : (arr[i-1][j], arr[i-1][j-1])    	    	
    	vector<double> arr(query_row + 1, 0);
    	arr[0] = poured;
    	for(int i = 1; i <= query_row; ++i) {
    		for(int j = i; j >= 0; --j) {
	    		double tmp = 0;
	    		if(j > 0  && arr[j-1] > 1)
    				tmp += (arr[j-1] - 1) / 2;
    			if(arr[j] > 1) 
    				tmp += (arr[j] - 1) / 2;
    			arr[j] = tmp;
    		}
    	}
    	return arr[query_glass] > 1 ? 1 : arr[query_glass];
    }
};