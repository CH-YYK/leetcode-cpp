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


class LFUCache {
public:
    LFUCache(int capacity) {
    	// 1. hashtable to do key-value store
    	// 2. map to sort by usage frequency
    	// 3. for each frequency, save a list as a queue
        size_ = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        // get value of the key and usage + 1
    	if(table.count(key)) {
    		auto [freq, it] = table[key];
    		int value = it->second;
			auto freqPtr = freqs.find(freq);
			freqPtr->second.erase(it);
    		
    		list<pair<int,int>>& newFreqList = freqs[freq + 1];
    		table[key] = {freq + 1, newFreqList.insert(newFreqList.end(), {key, value})};

    		if(freq == minFreq && freqPtr->second.empty()) minFreq++;
    		return value;
    	}
    	return -1;
    }
    
    void put(int key, int value) {
        if(size_ == 0) return;
    	if(table.count(key)) {
    		// update value and freqency
    		auto [freq, it] = table[key];
    		auto freqPtr = freqs.find(freq);
			freqPtr->second.erase(it);
            
            list<pair<int,int>>& newFreqList = freqs[freq + 1];
            table[key] = {freq + 1, newFreqList.insert(newFreqList.end(), {key, value})};
            if(freq == minFreq && freqPtr->second.empty()) minFreq++;
    		return;
    	} else if(table.size() == size_) {
    		// dump first element of the least frequency
    		list<pair<int,int>>& freqList = freqs[minFreq];
    		auto [_k, _v] = freqList.front();
    		table.erase(_k);
    		freqList.pop_front();
    	}
   		// put new value to table
   		list<pair<int,int>>& newFreqList = freqs[1];
   		table[key] = {1, newFreqList.insert(newFreqList.end(), {key, value})};
   		minFreq = 1;
    }
private:
	int size_;
	int minFreq;
	// <freq, list of (key,value)>
	map<int, list<pair<int,int>>> freqs;
	// key: <freq, pointer>
	unordered_map<int, pair<int, list<pair<int,int>>::iterator>> table;
};
