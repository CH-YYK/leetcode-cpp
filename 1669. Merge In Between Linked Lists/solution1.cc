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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		ListNode* dummyHead = new ListNode(0);        
		ListNode* dummyTail = nullptr;
		dummyHead->next = list1;
		int pos = 0;
		while(pos < a){
			dummyHead = dummyHead->next;
			pos++;
		}
        ListNode* curr = dummyHead->next;
		while(pos < b) {
			curr = curr->next;
			pos++;
		}
        dummyTail = curr->next;
		dummyHead->next = list2;
		curr = list2;
		while(curr->next) curr = curr->next;		
		curr->next = dummyTail;
		return list1;
    }
};