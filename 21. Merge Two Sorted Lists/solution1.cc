
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = new ListNode(-1, nullptr);
    ListNode *cur = head;
    // Take the smaller one to the tail of head.
    while (list1 && list2) {
      if (list1->val < list2->val) {
        cur->next = list1;
        list1 = list1->next;
      } else {
        cur->next = list2;
        list2 = list2->next;
      }
      cur = cur->next;
    }
    // in case List1 is longer than List2.
    if (list1)
      cur->next = list1;
    // in case List2 is longer than List1.
    if (list2)
      cur->next = list2;
    return head->next;
  }
};
