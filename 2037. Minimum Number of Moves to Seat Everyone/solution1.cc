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
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    	sort(seats.begin(), seats.end());
    	sort(students.begin(), students.end());
    	int ans = 0;
    	// greedy: sorting let ith student move to ith seat
    	// why greedy is valid?
    	// 		1. ith seat may not be the closest to ith student
    	// 		2. but if ith student doesn't go to ith seat, somebody that is much farther
    	// 			from the ith seat should take that, 
    	// 		3. resulting in more moves.

    	for(int i = 0; i < seats.size(); ++i) {
    		ans += abs(students[i] - seats[i]);
    	}
    	return ans;
    }
};