#include <list>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
int hash_(const T& key, const T& tableSize) {
  return key % tableSize;
}

template<typename T>
class HashTable {
private:
  vector<list<T>> hash_table;

  int myhash(const T& obj) {
    return hash_<T>(obj, hash_table.size());
  }
public:
  // size as prime
  HashTable(int size = 3) {
    hash_table.reserve(size);
    hash_table.resize(size);
  }
  ~HashTable() {};
  bool contains(const T& obj) {
    int hash_value = myhash(obj);
    const list<T>& slot = hash_table[hash_value];
    // typename is required as 'const_iterator' is in the scope of list<T>
    typename list<T>::const_iterator it = slot.cbegin();
    for(; it != slot.cend() && *it != obj; ++it);
    return it != slot.cend();
  }

  bool insert(const T& obj) {
    if(contains(obj)) return false;
    int hash_value = myhash(obj);
    list<T>& slot = hash_table[hash_value];
    slot.push_front(obj);
    return true;
  }

  bool remove(const T& obj) {
    list<T>& slot = hash_table[myhash(obj)];
    auto it = find(slot.begin(), slot.end(), obj);
    if(it == slot.end()) return false;
    slot.erase(it);
    return true;
  }
};

int main() {
  HashTable<int> hashtable(5);
  cout << hash_(7, 4) << endl;
  hashtable.insert(3);
  hashtable.insert(4);
  cout << hashtable.contains(3) << endl;
  cout << hashtable.contains(5) << endl;
}
