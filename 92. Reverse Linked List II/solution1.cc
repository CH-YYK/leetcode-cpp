
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

struct ListNode{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x) , next(nullptr)  {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *prev = new ListNode(0), *next = nullptr;
    ListNode *l = nullptr, *r = nullptr, *tmp = head;

    prev->next = head;
    int i = 1;
    while(tmp) {
      if (i < left) {
        prev = prev->next;
        l = prev->next;
      }

      if(i <= right) {
        r = tmp;
        next = tmp->next;
      }

      tmp = tmp->next;
      i++;
    }
    prev->next = reverse(l, r->next);
    l->next = next;
    return head;
  }
private:
  ListNode* reverse(ListNode* l, ListNode* r) {
    ListNode* curr = l, *prev = nullptr, *tmp;
    while(curr != r) {
      tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    return r;
  }
};
