#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
    // BFS solution iteratively using queue, O(N), O(N) for a queue
public:
    Node* connect(Node* root) {
        queue<Node*> Queue({root});
        while(!Queue.empty()) {
            vector<Node*> vec;
            while(!Queue.empty()) {
                if(Queue.front() != NULL) vec.push_back(Queue.front());
                Queue.pop();
            }

            for(int i = 0; i < vec.size(); i++) {
                if(i < vec.size()-1) 
                    vec[i]->next = vec[i+1];
                Queue.push(vec[i]->left), Queue.push(vec[i]->right);
            }
        }
        return root;
    }
};

class Solution2 {
    // DFS solution using recursion, O(N), O(N) for recursion
    // idea: get results from `left` and `right`
    //       connect rightmost nodes in `left` to leftmost nodes in `right` level by level
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node* left = connect(root->left);
        Node* right = connect(root->right);

        while(left) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        return root;
    }
};