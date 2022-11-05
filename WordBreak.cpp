#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

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
    bool dive(string wordList)
    {
        int len = wordList.size(), pos = 0;
        if (!len)
            return true;
        stack<pair<Trie *, int>> st;
        st.emplace(pair<Trie *, int>{this->children[wordList[0] - 'a'], 0});
        while (st.size())
        {
            auto curr = st.top();
            st.pop();
            while (curr.first)
            {
                cout << curr.first->isWord << " " << curr.second << endl;
                if (curr.first->isWord)
                {
                    cout << "found " << curr.second << endl;
                    if (curr.second == len - 1)
                        return true;
                    st.emplace(pair<Trie *, int>{this->children[wordList[curr.second + 1] - 'a'], curr.second + 1});
                }
                curr.first = curr.first->children[wordList[++curr.second] - 'a'];
            }
        }
        return false;
    }
    ~Trie()
    {
        Trie *ptr = this;
        for (Trie *x : ptr->children)
            if (x)
                delete x;
        ptr = nullptr;
    }

private:
    Trie *children[26] = {};
    bool isWord = false;
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        Trie tr;
        for (string s : wordDict)
        {
            tr.insert(s);
        }
        return tr.dive(s);
    }
};

int main()
{
    /*Solution so;
    vector<string> vec{"leet", "code"};
    cout << endl
         << so.wordBreak("leetcode", vec) << endl*/
    Trie *tr = new Trie();
    vector<string> vec{"leet", "code", "leeted", "newbie"};
    for (string s : vec)
        tr->insert(s);
    bool b = tr->dive("leetcode");
    cout << "result: " << b << endl;
    b = tr->dive("leetednewbiecode");
    cout << "result: " << b << endl;
    vector<string> vec1{"aaaa", "aa"};
    Trie *cr = new Trie();
    for (string s : vec1)
        cr->insert(s);
    bool c = cr->dive("aaaaaaa");
    cout << "result: " << c << endl;
    delete tr;
    return 0;
}