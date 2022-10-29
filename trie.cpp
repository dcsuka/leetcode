#include <iostream>
#include <string>

using namespace std;

// Implements a trie data structure for lowercase English letters

class Trie
{
public:
    Trie() {}
    void insert(string word)
    {
        Trie *ptr = this;
        for (char c : word)
        {
            c -= 'a';
            if (!ptr->children[c])
                ptr->children[c] = new Trie();
            ptr = ptr->children[c];
        }
        ptr->isWord = true;
    }
    bool search(string word)
    {
        Trie *ptr = this;
        for (char c : word)
        {
            c -= 'a';
            if (!ptr->children[c])
                return false;
            ptr = ptr->children[c];
        }
        return ptr->isWord;
    }
    bool startsWith(string prefix)
    {
        Trie *ptr = this;
        for (char c : prefix)
        {
            c -= 'a';
            if (!ptr->children[c])
                return false;
            ptr = ptr->children[c];
        }
        return true;
    }
    ~Trie()
    {
        cout << "Destructor was called" << endl;
        Trie *tr = this;
        for (Trie *x : tr->children)
        {
            if (x)
            {
                delete x;
                x = nullptr;
            }
        }
    }

private:
    Trie *children[26] = {};
    bool isWord = false;
};

int main()
{
    Trie *x = new Trie();
    x->insert("david");
    cout << x->search("dav") << endl;
    cout << x->search("shmavid") << endl;
    cout << x->search("david") << endl;
    cout << x->search("davids") << endl;
    cout << x->search("dsfsdfsdf") << endl;
    x->insert("dsfsdfsdf");
    cout << x->search("dsfsdfsdf") << endl;
    cout << x->startsWith("xyz") << endl;
    cout << x->startsWith("dsfg") << endl;
    cout << x->startsWith("dav") << endl;
    cout << x->startsWith("dsf") << endl;
    cout << x->startsWith("davids") << endl;
    delete x;
    x = nullptr;
    return 0;
}