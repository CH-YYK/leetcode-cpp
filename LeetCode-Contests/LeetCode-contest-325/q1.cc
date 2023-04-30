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
    int closetTarget(vector<string>& words, string target, int startIndex) {
    	if(words[startIndex] == target) 
    		return 0;
    	int n = words.size();
        // move forward
        int step = 1;
        int i = (startIndex + 1) % n;
        while(i != startIndex && words[i] != target) {
        	i = (i + 1) % n, step++;
        }
        if(i == startIndex)
        	return -1;

        int step2 = 1;
        i = (startIndex - 1 + n) % n;
        while(i != startIndex && words[i] != target)
        	i = (i - 1 + n) % n, step2++;
        return min(step, step2);
    }	
};