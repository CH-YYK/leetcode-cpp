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

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.front() != sentence.back())
        	return false;
        stringstream ss(sentence);
        string pre, curr;
        while(ss >> curr) {
        	if(pre.empty()) pre = curr;
        	else {
        		if(pre.back() != curr.front())
        			return false;
        		pre = curr;        		
        	}
        }
        return true;
    }
};

int main() {
    
}
