#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    unordered_map<Node*, Node*> hashmap;
public: 
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* newNode = new Node(node->val, {});
        hashmap[node] = newNode;
        queue<Node*> todo({node});

        while(!todo.empty()) {
            Node* curr = todo.front();
            todo.pop();
            for(Node* neighbor : curr->neighbors) {
                if(!hashmap.count(neighbor)){
                    hashmap[neighbor] = new Node(neighbor->val, {});
                    todo.push(neighbor);
                }
                hashmap[curr]->neighbors.push_back(hashmap[neighbor]);
            }
        }
        return newNode;
    }
};