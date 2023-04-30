#include <iostream>
#include "Solution.h"

int main() {
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    for(auto i:{4, 2, 1, 3}){
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    ListNode *ans = Solution().sortList(head->next);
    while(ans) {
        std::cout << ans->val;
        ans = ans->next;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}