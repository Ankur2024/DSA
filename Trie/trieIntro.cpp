#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    void searchUtil(TrieNode *root, string word, string s)
    {
        if (word.length() == 0)
        {
            if (root->isTerminal)
                cout << "Word Found: " << s << endl;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            cout << "Word Not Found: " << s << endl;
            return;
        }
        return searchUtil(child, word.substr(1), s);
    }

    void search(string word)
    {
        searchUtil(root, word, word);
    }

    bool hasNoChildren(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != nullptr)
            {
                return false;
            }
        }
        return true;
    }

    void removeUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            cout << "Word Not Found: " << word << endl;
            return;
        }
        removeUtil(child, word.substr(1));
        if (child->isTerminal == false && hasNoChildren(child))
        {
            delete child;
            root->children[index] = NULL;
        }
    }

    void remove(string word)
    {
        removeUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->search("ABCD");
    t->insertWord("ABCE");
    t->search("ABCE");
    t->remove("ABCE");
    t->search("ABCE");
    return 0;
}