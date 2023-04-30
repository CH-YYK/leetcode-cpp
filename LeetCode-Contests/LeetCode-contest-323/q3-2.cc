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
    	units = vector<int>(n, 0);
    }
    
    int allocate(int size, int mID) {
    	for(int i = 0; i < N; ++i) {
    		if(units[i] != 0) continue;
    		int j = i;
    		// j - i + 1 >= size
    		while(j <= min(i + size - 1, N-1) && units[j] == 0)
    			j++; 		
    		if(j - i == size) {
	    		usedblocks[mID].emplace_back(i, size);
	    		int loc = i;
	    		while(i < j) {
	    			units[i++] = mID;
	    		}
	    		return loc;
    		}
    		i = j;
    	}
    	return -1;
    }
    
    int free(int mID) {
    	// total size
    	if(!usedblocks.count(mID)) return 0;
    	int res = 0;
    	for(int i = 0; i < usedblocks[mID].size(); ++i) {
    		int j = usedblocks[mID][i].first;
    		int size = usedblocks[mID][i].second;
    		res += size;
    		while(size--) {
    			units[j++] = 0;
    		}
    	}
        usedblocks.erase(mID);
    	return res;
    }
private:
	int N;
	vector<int> units;
	unordered_map<int, vector<pair<int,int>>> usedblocks;
	int offset = 0; // global offset to the global available block
};


/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */