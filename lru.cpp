#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        string key = "";
        int value = -1;
        Node(string key, int value)
        {
            this->key = key;
            this->value = value;
        }
};

class LRU
{
    public:
        int maxSize;
        list<Node> l;
        unordered_map <string, list<Node> :: iterator> m;

        LRU(int maxSize = 0)
        {
            this->maxSize = maxSize > 1 ? maxSize : 1;
        }

        void insertKeyValue(string key, int value)
        {
            // this key value pair exists in the cache, so update the old value
            if(m.count(key) != 0)
            {
                list<Node> :: it = m[key];
                it->value = value;
            }
            else
            {
                // cache is full, so remove the least recently used item from the list
                if(l.size() == maxSize)
                {
                    Node last = l.back();
                    m.erase(last.key);
                    l.pop_back();
                }
                
                Node n(key, value);
                l.push_front(n);
                m[key] = l.begin();
            }
            return;
        }

        // accessing a particular value and shifting it to top
        int* getValue(string key)
        {
            if(m.count(key) != 0)
            {
                list<Node> :: it = m[key];
                int value = it->value;
                l.push_front(*it);
                l.erase(it);
                m[key] = l.begin();
                return &(l.begin()->value);
            }
            return NULL;
        }

        string mostRecentKey()
        {
            return l.front().key;
        }
};

int main()
{
    LRU lru(4);
    lru.insertKeyValue("apple", 1);
    lru.insertKeyValue("banana", 2);
    lru.insertKeyValue("guava", 3);
    lru.insertKeyValue("mango", 4);

    return 0;
}