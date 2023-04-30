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
    
class FreqStack {
public:
    FreqStack() {
    	// We used to map values its frequent
    	// Since we always pop the most frequent and the frequency decrease
    	// by 1 every pop(); So we probably can transpose the mapping and 
    	// map freq to values
    	// 
    	// an integer that track the maxFreq
    	// a hashmap saves <freq, stack<values>> 
    	// a hashmap saves <value, freq>
    	// 
    	// we don't need to worry about dump values from stacks
    	// the freq map is just for tracking the 'push' that make 
    	// a value to some frequency

    	// time complexity: 
    	//   push: O(1)
    	//   pop: O(1)
    	// overall O(N)
    }
    
    void push(int val) {
    	int freq = ++cnts[val];
    	freqmap[freq].push(val);
    	maxFreq = max(freq, maxFreq);
    }
    
    int pop() {
    	int val = freqmap[maxFreq].top();
    	freqmap[maxFreq].pop();
    	cnts[val]--;
    	if(freqmap[maxFreq].empty()) 
    		freqmap.erase(maxFreq--);
    	return val;
    }
private:
	int maxFreq = 0;
	unordered_map<int, stack<int>> freqmap; // freq -> values
	unordered_map<int, int> cnts; // value -> total freq
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {
    
}
