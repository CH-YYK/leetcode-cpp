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

class FrequencyTracker {
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
    	int oldcnt = mp[number];
    	int newcnt = oldcnt + 1;
    	mp[number] = newcnt;
        freq[oldcnt]--;
        freq[newcnt]++;
    }
    
    void deleteOne(int number) {
        if(!mp.count(number)) return;
        int oldcnt = mp[number];
        int newcnt = oldcnt - 1;

        if(newcnt == 0) mp.erase(number);
        else mp[number] = newcnt;

        freq[oldcnt]--;
        freq[newcnt]++;
    }
    
    bool hasFrequency(int frequency) {
    	return freq[frequency] > 0;
    }
private:
	unordered_map<int,int> mp;
	unordered_map<int,int> freq;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */