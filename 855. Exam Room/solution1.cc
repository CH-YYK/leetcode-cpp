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

class ExamRoom {
public:
    ExamRoom(int n) {
    	// quickly find the maximum gap with min index
    	// quickly loaate a random index
    	// to keep least decouple, a gap is determined by its left index and length
    	//
    	// set<pair<-gap,idx>>: max gap and min idx.
    	// unordered_map<idx, gap>: index and current gap
    	N = n;
    }
    
    int seat() {
    	if(ranks.empty()) {
    		// target index: (l + r) / 2
    		// length: (r - l + 1)
    		gaps[0] = N;
    		ranks.insert({-N/2, 0});
            return 0;
    	} else if(ranks.size() == 1) { 
    		gaps[N-1] = 1;
    		ranks.insert({0, N-1});
    		return N-1;
        } else {
    		auto it = ranks.begin();
    		int left = it->second;
    		int len = gaps[left];

    		if(gaps.begin()->first != 0 && (left + 1) / 2 >= len / 2) {
    			// 0 is empty
 				gaps[0] = left + 1;
 				ranks.insert({-(left + 1) / 2, 0});
 				return 0;
    		} 
   			int right = left - 1 - len;
   			int mid = left + (right - left) / 2;
   			ranks.erase({-len / 2, left});
   			ranks.insert({-(mid - left + 1) / 2, left});
   			ranks.insert({-(right - mid + 1) / 2, mid});
   			gaps[left] = mid - left + 1;
   			gaps[mid] = right - mid + 1;
            return mid;
    	}

    }
    
    void leave(int p) {
    	int len = gaps[p];
    	auto curr = gaps.find(p);
    	if(curr != gaps.begin()) {
    		auto pre = prev(curr);
    		ranks.erase({-pre->second / 2, pre->first});
    		pre->second += curr->second - 1;
    		ranks.insert({-pre->second / 2, pre->first});
    	}
    	ranks.erase({-len, p});
    	gaps.erase(curr);
    }
private:
	int N;
	set<pair<int, int>> ranks;
	map<int, int> gaps;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */