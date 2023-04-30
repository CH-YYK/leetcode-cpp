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
    	// arr[i][j] : (arr[i-1][j], arr[i-1][j-1])    	
    	vector<vector<double>> arr(102, vector<double>(102, 0));
    	arr[0][0] = poured;
    	for(int i = 1; i <= query_row; ++i) {
    		for(int j = 0; j <= i; ++j) {
    			if(arr[i-1][j] > 1) 
    				arr[i][j] += (arr[i-1][j] - 1) / 2;
    			if(j > 0 && arr[i-1][j-1] > 1)
    				arr[i][j] += (arr[i-1][j - 1] - 1) / 2;
    		}
    	}
    	return arr[query_row][query_glass] > 1 ? 1 : arr[query_row][query_glass];
    }
};