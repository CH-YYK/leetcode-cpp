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
    int findJudge(int n, vector<vector<int>>& trust) {
    	// indegree = n-1, outdegree = 0;
	    vector<int> ins(n), outs(n);
	    for(vector<int>& edge : trust) {
	    	ins[edge[1]]++;
	    	outs[edge[0]]++;	    	
	    }
	    int nums = 0;
	    for(int i = 0; i < n; ++i){
	    	if(ins[i] == n-1 && outs[i] == 0)
	    		nums++;
	    }
	    return nums == 1;
    }
};