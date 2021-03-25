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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *prev = nullptr, *conn = nullptr, *curr = head;
    ListNode *res = new ListNode(-101);
    res->next = head;
    conn = res;
    bool dup = false; // true: the prev should be removed

    while (curr) {
      if (prev == nullptr) {
        prev = curr;
        curr = curr->next;
        continue;
      }

      if (prev->val == curr->val) {
        dup = true;
        prev->next = curr->next; // delete curr and prev wont move
      } else if (dup) {
        conn->next = prev->next; // delete prev and conn wont move
        prev = prev->next;
        dup = false;
      } else {
        conn = conn->next;
        prev = prev->next;
      }
      curr = curr->next;
    }
    if (dup)
      conn->next = prev->next; // the prev left would need deletion
    return res->next;
  }
};
