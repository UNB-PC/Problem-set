class LRUCache {
public:
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    std::list<int> usage;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        cache.reserve(cap);    
    }
    
    int get(int key) {
        if(cache.contains(key)){
            // Move the element to the front of the list in O(1)
            usage.splice(usage.begin(), usage, cache[key].second);
            cache[key].second = usage.begin();
            // Return the value
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.contains(key)){
            // O(1) move the node pointed to by entry.second to the front
            usage.splice(usage.begin(), usage, cache[key].second);
            cache[key] = {value, usage.begin()};
            return;
        }
        if(usage.size() == cap){
            cache.erase(usage.back());
            usage.pop_back();
        }
        usage.push_front(key);
        cache[key] = {value, usage.begin()};
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
