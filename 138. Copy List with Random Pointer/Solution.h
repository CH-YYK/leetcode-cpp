#include <unordered_map>

// Method using hashmap O(N) in time, O(N) in space;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {};
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode *cur = head, *newNode = new RandomListNode(0);
        RandomListNode *tmpNode = newNode;
        std::unordered_map<RandomListNode *, RandomListNode *> hashmap;
        while(cur){
            if(!hashmap.count(cur))
                hashmap[cur] = new RandomListNode(cur->label);
            tmpNode->next = hashmap[cur];
            if(cur->random){
                hashmap[cur->random] = new RandomListNode(cur->random->label);
                tmpNode->next->random = hashmap[cur->random];
            }
            tmpNode = tmpNode->next;
            cur = cur->next;
        }
        return newNode->next;
    }
};