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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
    	// todo: delete on the fly
        // monotonic-desc stack
    	vector<int> nodeList;
    	ListNode* curr = head;
    	while(curr) {
    		nodeList.push_back(curr->val);
    		curr = curr->next;
    	}

    	vector<int> stk;
    	for(int i = 0; i < nodeList.size(); ++i) {
    		while(!stk.empty() && nodeList[i] > nodeList[stk.back()])
    			stk.pop_back();
    		stk.push_back(i);
    	}
		
		// build list
		ListNode* res = new ListNode(0);
		curr = res;
		for(int i = 0; i < stk.size(); ++i) {
			curr->next = new ListNode(nodeList[stk[i]]);
			curr = curr->next;
		}
		return res->next;
    }
};

int main() {
    
}
