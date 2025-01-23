#include <vector>
using namespace std;

class Trie {
    vector<Trie *> children;
    bool isWord;

  public:
    Trie() {
        children = vector<Trie *>(26);
        isWord = false;
    }

    void insert(string word) {
        Trie *curr = this;
        for (char &ch : word) {
            if (curr->children[ch - 'a'] == nullptr) {
                curr->children[ch - 'a'] = new Trie();
            }

            curr = curr->children[ch - 'a'];
        }
        curr->isWord = true;
    }

    bool search(string word) {
        Trie *curr = this;
        for (char &ch : word) {
            if (curr->children[ch - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        return curr->isWord;
    }

    bool startsWith(string prefix) {
        Trie *curr = this;
        for (char &ch : prefix) {
            if (curr->children[ch - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */