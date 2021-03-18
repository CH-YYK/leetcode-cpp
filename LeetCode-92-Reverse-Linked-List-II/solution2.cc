struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *prev = nullptr, *next = head, *curr = head, *tmp;

    int i = 1;
    while (curr) {
      if (i <= left - 1)
        prev = curr; // prev on left-1
      if (i <= right)
        next = curr; // next on right
      curr = curr->next;
      i++;
    }
    // find the head and tail of segment, and next
    if (prev == nullptr)
      curr = head;
    else
      curr = prev->next;
    ListNode *l = curr, *r = next;
    next = next->next;

    // reverse l throught r with help
    ListNode *con = nullptr;
    while (curr != next) {
      tmp = curr->next;
      curr->next = con;
      con = curr;
      curr = tmp;
    }
    // rebuild connection
    l->next = next;
    if (prev == nullptr)
      return r;
    prev->next = r;
    return head;
  }
};
