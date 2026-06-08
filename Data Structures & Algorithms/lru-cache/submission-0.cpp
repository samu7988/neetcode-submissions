/*
 ─────────────────────────────────────────────────────────────────────
 LRU CACHE — General Idea
 ─────────────────────────────────────────────────────────────────────
 Design a cache with fixed capacity that supports get() and put() in O(1).
 When capacity is exceeded → evict the LEAST RECENTLY USED item.
 
 Data Structures Used:
   1. Doubly Linked List (DLL)
      - FRONT = most recently used (MRU)
      - BACK  = least recently used (LRU) → eviction target
   
   2. HashMap (key → {DLL iterator, value})
      - Iterator: gives O(1) access to node in DLL
      - Value: stores the cached value
 
 Operations:
   get(key)         → if found, move to front (MRU) and return value
                    → if not found, return -1
   
   put(key, value)  → if exists, update value and move to front
                    → if not, insert at front
                    → if over capacity, remove LRU (back of DLL)
 ─────────────────────────────────────────────────────────────────────
*/

class LRUCache {
public:
    list<int> dll;                                                    // front = MRU, back = LRU
    unordered_map<int, pair<list<int>::iterator, int>> mp;            // key → {iterator in dll, value}
    int n;                                                             // remaining capacity
    
    LRUCache(int capacity) {
        n = capacity;                                                  // initialize capacity
    }
    
    // ── move key to front of DLL (mark as most recently used) ──
    void mostRecentlyUsed(int key) {
        dll.erase(mp[key].first);                                     // remove key from current position
        dll.push_front(key);                                          // re-insert at front
        mp[key].first = dll.begin();                                  // update iterator in map
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())                                 // key not in cache
            return -1;
        
        mostRecentlyUsed(key);                                        // mark as recently used
        return mp[key].second;                                        // return associated value
    }
    
    void put(int key, int value) {
        
        if (mp.find(key) != mp.end())                                 // key already exists
        {
            mp[key].second = value;                                   // update value
            mostRecentlyUsed(key);                                    // mark as recently used
        }
        else                                                           // key is new
        {
            dll.push_front(key);                                      // insert at front
            mp[key] = {dll.begin(), value};                           // record iterator + value
            n--;                                                       // ✅ FIX: decrement capacity
            
            if (n < 0)                                                 // capacity exceeded
            {
                int del_key = dll.back();                             // get LRU key (back of DLL)
                mp.erase(del_key);                                    // remove from map
                dll.pop_back();                                       // remove from DLL
                n++;                                                   // restore capacity
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */