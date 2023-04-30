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

class SummaryRanges {
public:
    SummaryRanges() {
        // Keep track of the ranges
        // merge the ranges on the fly while adding numbers
        // map<int,int>: <left, right>
    }
    
    void addNum(int value) {
    	if(ranges.count(value))
    		return;
     	int end = value;
     	// can merge the [value, value] to right
    	if(ranges.count(value + 1)) {
    		end = ranges[value + 1];
    		ranges.erase(value + 1);
    	}
    	// can merge the [value, end] to left
     	auto it = ranges.upper_bound(value);
     	if(it != ranges.begin() && prev(it)->second >= value - 1) {
     		if(prev(it)->second == value - 1) {     			
	   			prev(it)->second = end;
     		} 
     		return;
     	}
     	ranges[value] = end;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto [k, v] : ranges)
        	ans.push_back({k, v});
        return ans;
    }
private:
	map<int,int> ranges;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */