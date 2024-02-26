#include <iostream>

#include "Word.h"


using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int>>> data;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap(): data(base) {}

    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it).first == key) {
                (*it).second = value;
                return;
            }
        }
        data[h].push_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it).first == key) {
                return (*it).second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it).first == key) {
                data[h].erase(it);
                return;
            }
        }
    }
};


// 字典树的结点
struct trie {
    int n;
    trie* son[26];
    trie (): n(0) {
        for (int i = 0; i < 26; ++i) {
            son[i] = nullptr;
        }
    }
};

class WordsFrequency {
private:
    trie* root;
public:
    WordsFrequency(vector<string>& book) {
        root = new trie();
        trie* tmp = root;
        for (auto& i : book) {
            tmp = root;
            for (auto& ch : i) {
                int next = ch - 'a';
                if (!tmp->son[next]) {
                    tmp->son[next] = new trie();
                }
                tmp = tmp->son[next];
            }
            // 到达底部后, 将叶子结点++
            ++tmp->n;
        }
    }
    int get(string word) {
        trie* find = root;
        for (auto& i : word) {
            int next = i - 'a';
            if (find->son[next]) find = find->son[next];
            else return 0;
        }
        return find->n;
    }
};

