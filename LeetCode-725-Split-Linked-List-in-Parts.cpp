#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        ListNode* curr = root;
        while(curr) curr = curr->next, n++;
        partition(root, n, k);
        return all_partitions;
    }
private:
    vector<ListNode*> all_partitions;

    void partition(ListNode* rest, int n, int k) {
        if(rest == NULL && k == 0) return;
        if(rest == NULL && k > 0) {
            all_partitions.emplace_back(); 
            partition(rest, n, k - 1);
            return;
        }
        int size = n / k + (n % k > 0);
        ListNode* curr = rest;
        for(int i = 0; i < size-1 && curr->next; i++) 
            curr = curr->next;

        ListNode* tmp = curr->next;
        curr->next = NULL;
        all_partitions.push_back(rest);
        partition(tmp, n - size, k-1);
    }
};