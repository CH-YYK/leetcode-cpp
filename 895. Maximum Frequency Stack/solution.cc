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
    	// a unordered_map to count the element
    	// a set saves the <cnt, latest time, val>
    	// a hashmap saves the <val, pointer to set>
    	// a hashmap saves the <val, stack<lastest times>>

    	// time complexity: 
    	//   push: O(1) + O(logK)
    	//   pop: O(logK)
    	// O(NlogN)
    }
    
    void push(int val) {
    	pushtime++;
    	if(cnts.count(val)) {
    		auto posInSet = cnts[val];

    		int cnt = (*posInSet)[0];
    		int time = (*posInSet)[1];

    		s.erase(posInSet);
	    	cnts[val] = s.insert({cnt + 1, pushtime, val}).first;
	    	pushtimes[val].push(pushtime);
    		return;
    	}
    	cnts[val] = s.insert({1, pushtime, val}).first;
    	pushtimes[val].push(pushtime);
    }
    
    int pop() {
    	if(s.empty()) return -1;
    	auto dumpIt = prev(s.end());

    	int cnt = (*dumpIt)[0];
    	int time = (*dumpIt)[1];
    	int val = (*dumpIt)[2];
    	pushtimes[val].pop();
    	s.erase(dumpIt);

    	if(cnt > 1) {
    		time = pushtimes[val].top();	
    		cnts[val] = s.insert({cnt - 1, time, val}).first;
    	} else {
    		pushtimes.erase(val);
    		cnts.erase(val);
    	}
    	return val;
    }
private:
	int pushtime = 0;
	set<array<int, 3>> s;
	unordered_map<int, set<array<int, 3>>::iterator> cnts;
	unordered_map<int, stack<int>> pushtimes;
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {
    
}
