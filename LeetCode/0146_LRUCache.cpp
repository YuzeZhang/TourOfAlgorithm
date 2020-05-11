//
// Created by Zeno on 2020/5/11.
//

/*
 * 思路：
 * 使用一个双链表和一个哈希表实现LRU Cache
 * 双链表中存储key和value的pair，哈希表存储从key到双链表迭代器的映射
 * 双链表存储key可以使得在尾删双链表节点时得到该节点的key，从而通过key找到哈希表中的该节点并将其删除
 * 哈希表的键值对中值是双链表迭代器即可以方便的通过双链表的begin/back操作找到头尾节点
 * get方法通过key在哈希表中找到对应的双链表节点，然后返回它的value，并将该节点删除，然后在双链表头部插入该节点的复制，并更新哈希表中的值
 * put方法需要先在哈希表中寻找对应的key，如存在则对value进行更新并将该节点提到链表头部
 * 如不存在则需要判断cache容量是否已满，如不满则直接头插，如满则先删除尾节点再头插
 * 注意：在每一步对链表进行更新时需要对哈希表同步更新*/

class LRUCache {
private:
    int cap; // 用于存储cache的最大容量
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }

        pair<int, int> k_v = *mp[key]; // mp[key]得到一个迭代器，对其解引用得到pair
        cache.erase(mp[key]);
        cache.push_front(k_v);

        mp[key] = cache.begin();
        return k_v.second;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            // cache中不存在key
            if (cache.size() == cap) {
                // 容量已满则先尾删
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                mp.erase(lastKey);
                cache.pop_back();
            }

            // 头插
            cache.push_front(make_pair(key, value));
            mp[key] = cache.begin();
        } else {
            // cache中存在key，更新它的value并将其提到头部
            cache.erase(mp[key]);
            cache.push_front(make_pair(key, value));
            mp[key] = cache.begin();
        }
    }
};
