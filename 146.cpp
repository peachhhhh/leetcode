#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

//哈希表和双向链表
class LRUCache
{
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity)
    {
        this->cap = capacity;
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
        {
            return -1;
        }
        l.push_front(*map[key]);
        l.erase(map[key]);
        map[key] = l.begin();
        return map[key]->second;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            l.erase(map[key]);
            map.erase(key);
        }
        pair<int, int> p(key, value);
        l.push_front(p);
        pair<int, list<pair<int, int>>::iterator> pp(key, l.begin());
        map.insert(pp);
        if (map.size() > this->cap)
        {
            map.erase(l.back().first);
            l.pop_back();
        }
    }
};

void test()
{
    LRUCache *cache = new LRUCache(2 /* 缓存容量 */);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;    // 返回  1
    cache->put(3, 3); // 该操作会使得密钥 2 作废
    cout << cache->get(2) << endl;    // 返回 -1 (未找到)
    cache->put(4, 4); // 该操作会使得密钥 1 作废
    cout << cache->get(1) << endl;    // 返回 -1 (未找到)
    cout << cache->get(3) << endl;    // 返回  3
    cout << cache->get(4) << endl;   // 返回  4
}

int main()
{
    test();
    return 0;
}