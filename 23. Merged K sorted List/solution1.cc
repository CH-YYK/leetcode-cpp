#include <queue>
#include <vector>

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<pair<int, ListNode *>> pq; // maxheap <-val, ptr>
    for (ListNode *node : lists) {
      if (node)
        pq.emplace(-node->val, node);
    }
    ListNode *ans = new ListNode(0);
    ListNode *curr = ans;
    while (!pq.empty()) {
      auto [nval, node] = pq.top();
      pq.pop();
      curr->next = node;
      node = node->next;
      curr->next->next = nullptr;
      curr = curr->next;

      if (node != nullptr) {
        pq.emplace(-node->val, node);
      }
    }
    return ans->next;
  }
};
