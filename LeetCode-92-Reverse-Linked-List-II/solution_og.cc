class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {

    if(head == nullptr) return nullptr;

    // Move two pointers until they reach the starting point
    ListNode *cur = head, *prev = nullptr;
    while(left > 1) {
      prev = cur;
      cur = cur->next;
      --left, --right;
    }

    // prev->tail
    ListNode* con = prev, *tail = curr;

    // Iteratively reverse the nodes until right becomes 0
    ListNode* tmp;
    while(right > 0) {
      tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
      --right;
    }

    // Adjust the final connections
    if(con != nullptr)
      con->next = prev;
    else
      head = prev;
    tail->next = curr;
    return head;
  }
};
