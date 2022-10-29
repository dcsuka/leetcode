#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Implements a trie data structure for lowercase English letters

struct TrieNode
{
    vector<TrieNode *> data;
    bool wordEnds = false;
    TrieNode() : data(26, nullptr) {}
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *ptr = root;
        for (char c : word)
        {
            if (!ptr->data[c - 'a'])
                ptr->data[c - 'a'] = new TrieNode();
            ptr = ptr->data[c - 'a'];
        }
        ptr->wordEnds = true;
    }
    bool search(string word)
    {
        TrieNode *ptr = root;
        for (char c : word)
        {
            ptr = ptr->data[c - 'a'];
            if (!ptr)
                return false;
        }
        return ptr->wordEnds;
    }
    bool startsWith(string prefix)
    {
        TrieNode *ptr = root;
        for (char c : prefix)
        {
            ptr = ptr->data[c - 'a'];
            if (!ptr)
                return false;
        }
        return true;
    }
    void clear(TrieNode *&tn)
    {
        for (auto &x : tn->data)
        {
            if (x)
                clear(x);
        }
        delete tn;
        tn = nullptr;
    }
    ~Trie()
    {
        cout << "Destructor was called" << endl;
        clear(root);
    }

private:
    TrieNode *root;
};

int main()
{
    Trie x;
    x.insert("david");
    cout << x.search("dav") << endl;
    cout << x.search("shmavid") << endl;
    cout << x.search("david") << endl;
    cout << x.search("davids") << endl;
    cout << x.search("dsfsdfsdf") << endl;
    x.insert("dsfsdfsdf");
    cout << x.search("dsfsdfsdf") << endl;
    cout << x.startsWith("xyz") << endl;
    cout << x.startsWith("dsfg") << endl;
    cout << x.startsWith("dav") << endl;
    cout << x.startsWith("dsf") << endl;
    cout << x.startsWith("davids") << endl;
    return 0;
}