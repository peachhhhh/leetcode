#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//前缀树
class Trie
{
private:
    Trie *next[26] = {nullptr};
    bool isEnd = false;

public:
    /** Initialize your data structure here. */
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *t = this;
        for (char &c : word)
        {
            if (!t->next[c - 'a'])
            {
                t->next[c - 'a'] = new Trie();
            }
            t = t->next[c - 'a'];
        }
        t->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *t = this;
        for (char &c : word)
        {
            if (!t->next[c - 'a'])
            {
                return false;
            }
            t = t->next[c - 'a'];
        }
        return t->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *t = this;
        for (char &c : prefix)
        {
            if (!t->next[c - 'a'])
            {
                return false;
            }
            t = t->next[c - 'a'];
        }
        return true;
    }
};

void test()
{
}

int main()
{
    test();
    return 0;
}