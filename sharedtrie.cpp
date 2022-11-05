#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Implements a trie data structure for lowercase English letters with std::shared_ptr

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
                ptr->children[c] = make_unique<Trie>();
            ptr = ptr->children[c].get();
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
            ptr = ptr->children[c].get();
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
            ptr = ptr->children[c].get();
        }
        return true;
    }

private:
    unique_ptr<Trie> children[256] = {};
    bool isWord = false;
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