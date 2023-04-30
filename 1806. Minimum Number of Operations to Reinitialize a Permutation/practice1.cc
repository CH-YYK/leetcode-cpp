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
    int reinitializePermutation(int n) {
        // simulation
    	vector<int> perm(n, 0), arr(n);
    	int back = true;
    	for(int i = 0; i < 10000; ++i) {
    		back = true;
    		for(int j = 0; j < n; ++j) {
    			if(i == 0) arr[i] = j;
    			else {
    				if(j % 2 == 0)
    					arr[j] = perm[j/2];
    				else
    					arr[j] = perm[(n + j - 1) / 2];
    				back &= (arr[j] == j);
    			}
    		}
    		if(i > 0 && back) return i;
    		swap(arr, perm);
    	}    	
    	return 1;
    }   
};