#include <vector>
#include <memory>
#include <string>
#include <unordered_set>

using namespace std;

struct TrieNode {
  bool is_word;
  bool is_end;
  vector<TrieNode*> children;
  TrieNode() : is_word(false), children(26, nullptr), is_end(false) {}
  ~TrieNode() {
    for(TrieNode* child : children)
      if(child) delete child;
  }
};

class Trie {
public:
  Trie() : root(new TrieNode()) {}
  void insert(const string& w) {
    TrieNode* p = root.get();
    for(char c : w) {
      if(!p->children[c - 'a'])
        p->children[c - 'a'] = new TrieNode();
      p = p->children[c- 'a'];
      p->is_end = false;
    }
    p->is_word = true;
    p->is_end = true;
  }
  TrieNode* get_ptr() const {
    return root.get();
  }
private:
  unique_ptr<TrieNode> root;
};

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    // sort(words.begin(), words.end(), [&](string& lhs, string& rhs) {return lhs.size() < rhs.size();});
    trie = Trie();
    m = board.size();
    n = board[0].size();
    for(string& w : words)
      trie.insert(w);

    TrieNode* root = trie.get_ptr();
    string word;
    for(int i = 0; i < board.size(); ++i) {
      for(int j = 0; j < board[0].size(); ++j) {
        if(!root->children[board[i][j] - 'a']) continue;
        char c = board[i][j];
        board[i][j] = '0';
        word.push_back(c);
        dfs(board, i, j, root->children[c - 'a'], word);
        board[i][j] = c;
        word.pop_back();
      }
    }
    vector<string> ret(res.begin(), res.end());
    return ret;
  }
private:
  Trie trie;
  unordered_set<string> res;
  int m, n;
  const  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, string& word) {
    if(root == nullptr) return ;
    if(root->is_word) res.insert(word);
    // if(root->is_end)
    //  return;
    if (word.size() == min(m * n, 10))  // maxsize 10
      return;

    for(int k = 0; k < 4; ++k) {
      int ni = i + dirs[k][0], nj = j + dirs[k][1];
      if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] != '0') {
        char c = board[ni][nj];
        board[ni][nj] = '0';
        word.push_back(c);
        dfs(board, ni, nj, root->children[c - 'a'], word);
        board[ni][nj] = c;
        word.pop_back();
      }
    }
    return;
  }
};
