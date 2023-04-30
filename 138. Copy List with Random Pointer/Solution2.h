#include <unordered_map>

// Method without hashmap, O(N) in time, O(1) in space;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {};
};

class Solution2 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode *nodeCopy, *copyHead = head, *newNode=new RandomListNode(0);
        // update original pointer by replicating nodes(original one followed by copied one)
        // 1----2----3----4----5
        // 1---1'---2---2'---3---3'---4---4'---5---5'
        while(copyHead){
            nodeCopy = new RandomListNode(copyHead->label);
            nodeCopy->next = copyHead->next;
            copyHead->next = nodeCopy;
            copyHead = copyHead->next->next;
        }

        // update copied nodes' random pointer
        copyHead = head;
        while(copyHead){
            if(copyHead->random)
                copyHead->next->random = copyHead->random->next;
            copyHead = copyHead->next->next;
        }


        // extract copied nodes from the original pointer
        // refine the original pointer by deleting copied nodes
        nodeCopy = newNode;
        copyHead = head;
        while(copyHead){
            nodeCopy->next = copyHead->next;
            copyHead->next = copyHead->next->next;
            nodeCopy = nodeCopy->next;
            copyHead = copyHead->next;
        }
        return newNode->next;
    }
};