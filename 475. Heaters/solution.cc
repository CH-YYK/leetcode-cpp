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

using namespace std;


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // binary search
        // find the minimum radius such that heaters can cover all houses
    	int l = 0, r = 1e9;
    	set<int> positions;    	
    	for(int h : heaters)
    		positions.insert(h);

    	function<bool(int)> canCoverAll = [&](int r) {
    		for(int house : houses) {
    			auto upper = positions.upper_bound(house + r);
    			auto lower = positions.lower_bound(house - r);
    			if(upper == positions.begin()) 
    				return false;
    			if(lower == positions.end())
    				return false;
                if(*lower > house + r) 
                    return false;
    		}
    		return true;
    	};

    	while (l < r) {
    		int m = (l + r) / 2;
    		if(canCoverAll(m)) {
    			r = m;
    		} else 
    			l = m + 1;
    	}
    	return l;
    }
};


int main() {
    
}