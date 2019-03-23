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
    unordered_set<Node*> visited;
    unordered_map<Node*, Node*> hashmap;
public:
    Node* cloneGraph(Node* node) {
        // copy nodes
        dfs(node);
        visited.clear();

        // copy edges
        Node* newNode = new Node();
        newNode->val = node->val;
        Node* curr = newNode;
        queue<Node*> origin({node});
        queue<Node*> copy({curr});

        while(!origin.empty()) {
            Node* tmp_origin = origin.front();
            Node* tmp_copy = copy.front();
            origin.pop();
            copy.pop();

            visited.insert(tmp_origin);

            for(auto i: tmp_origin->neighbors) {
                tmp_copy->neighbors.push_back(hashmap[i]);
                if(visited.count(i)) continue;
                origin.push(i);
                copy.push(hashmap[i]);
            }
        }
        return newNode;
    }

    void dfs(Node* node) {
        if(visited.count(node)) return;
        Node* curr = new Node();
        curr->val = node->val;
        hashmap[node] = curr;
        visited.insert(node);
        for(auto i: node->neighbors) {
            dfs(i);
        }
    }
};