/**
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
 * If the number of keys exceeds the capacity from this operation,
 *   evict the least recently used key.

 *  Could you do get and put in O(1) time complexity?
 */
#include <list>
#include <unordered_map>
#include <pair>
#include <vector>
#include <string>


using namespace std;

class LRUCache {
 private:
  int cap_;
  /* timeline of values accessing, recent -> early
   *   - use pair<int, int> to map value to key.
   */
  list<pair<int,int>> cache_;
  /* record the positions of values in the list
   *   - use iterator to locate the <key, val> in cache
   */
  unordered_map<int, list<pair<int, int>>::iterator> map_;
 public:
  LRUCache(int capacity) {
    cap_ = capacity;
  }

  int get(int key) {
    if(!map_.count(key)) return -1;
    auto node = map_[key];
    int val = node->second;

    cache_.erase(node);
    cache_.emplace_front(key, val);
    map_[key] = cache_.begin();

    return val;
  }

  void put(int key, int value) {
    cache_.emplace_front(key, value);
    if(map_.count(key)) cache_.erase(map_[key]);
    map_[key] = cache_.begin();

    if(cache_.size() > cap_) {
      const auto& node = cache_.back();
      map_.erase(node.first);
      cache_.pop_back();  // cannot use end() to erase
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
