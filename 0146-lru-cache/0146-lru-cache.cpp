#include <list>
#include <map>
using namespace std;

class LRUCache {
public:
    list<int> dll;  // Most recently used key at front
    map<int, pair<list<int>::iterator, int>> mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void makeMostRecentlyUsed(int key) {
        dll.erase(mp[key].first);     // Remove old position
        dll.push_front(key);          // Put at front
        mp[key].first = dll.begin();  // Update iterator
    }

    int get(int key) {
        if (!mp.count(key)) {
            return -1;
        }

        makeMostRecentlyUsed(key);
        return mp[key].second;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            // Key already exists
            mp[key].second = value;
            makeMostRecentlyUsed(key);
        } 
        else {
            // New key
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        // Capacity exceeded
        if (n < 0) {
            int key_tobe_del = dll.back();
            mp.erase(key_tobe_del);
            dll.pop_back();
            n++;
        }
    }
};