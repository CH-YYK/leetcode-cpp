// Hello, x is a CPP leetcode snippet.

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

class Allocator {
public:
    Allocator(int n) {
    	N = n;
    }
    
    int allocate(int size, int mID) {
        if(freeblocks.count(size)) {
        	int loc = freeblocks[size].top();
        	freeblocks[size].pop();
        	if(freeblocks[size].empty())
        		freeblocks.erase(size);
        	// cout << "take freed " << size << endl;
        	usedblocks[mID].emplace(loc, size);
        	return -loc;
        } else {
        	if(offset + size > N) return -1;
        	usedblocks[mID].emplace(-offset, size);
        	int loc = offset;
        	// cout << "take new " << size << endl;
         	offset += size;
         	return loc;
        }
    }
    
    int free(int mID) {
    	// total size
    	if(usedblocks.count(mID)) {
    		int res = 0;
    		while(!usedblocks[mID].empty()) {
    			auto [loc, size] = usedblocks[mID].top();
    			usedblocks[mID].pop();
    			freeblocks[size].push(loc);
    			res += size;
    		}
    		usedblocks.erase(mID);
    		return res;
    	} else return 0;
    }
private:
	int N;
	unordered_map<int, priority_queue<int>> freeblocks; // <size, maxpq(-firstIds)>
	unordered_map<int, priority_queue<pair<int,int>>> usedblocks;  // <id, maxpq<-loc, size>>
	int offset = 0; // global offset to the global available block
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */