#include <iostream>
// #include "Solution.h"
#include "Solution2.h"

int main() {
    auto *head = new RandomListNode(8);
    RandomListNode *ans = Solution2().copyRandomList(head);
    return 0;
}