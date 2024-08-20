#include <string>
#include <vector>

using namespace std;
class Node {
  public:
    char current;
    vector<Node *> children; // index this with char - 'a'
    bool isWord = false;

    Node(char current) : current(current), children(26, nullptr) {}
};

class Trie {
    Node *root;

  public:
    Trie() {
        root = new Node(' ');
    }

    void insert(string word) {
        Node *current = root;
        for (int i = 0; i < word.size(); i++) {
            if (!current->children[word[i] - 'a']) {
                current->children[word[i] - 'a'] = new Node(word[i]);
            }
            current = current->children[word[i] - 'a'];
        }
        current->isWord = true;
    }

    bool search(string word) {
        Node *current = root;
        for (int i = 0; i < word.size(); i++) {
            if (current->children[word[i] - 'a']) {
                current = current->children[word[i] - 'a'];
            } else {
                return false;
            }
        }
        return current->isWord;
    }

    bool startsWith(string prefix) {
        Node *current = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (current->children[prefix[i] - 'a']) {
                current = current->children[prefix[i] - 'a'];
            } else {
                return false;
            }
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