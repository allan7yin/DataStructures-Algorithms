#include <string>
#include <vector>
using namespace std;

class Node {
  public:
    char current;
    vector<Node *> children;
    bool isWord;
    Node(char current) : current(current), children(26, nullptr), isWord(false) {}
};

class WordDictionary {
    Node *root;

  public:
    WordDictionary() {
        root = new Node(' ');
    }

    void addWord(string word) {
        Node *current = root;
        for (int i = 0; i < word.size(); i++) {
            Node *&next = current->children[word[i] - 'a'];
            if (!next) {
                next = new Node(word[i]);
            }
            current = next;
        }
        current->isWord = true;
    }

    bool f(Node *current, string word, int k) {
        if (!current) return false;
        if (k >= word.size()) return current->isWord;
        bool found = false;

        if (word[k] == '.') {
            for (int i = 0; i < 26; i++) {
                found = found || f(current->children[i], word, k + 1);
            }
        } else {
            found = f(current->children[word[k] - 'a'], word, k + 1);
        }
        return found;
    }

    bool search(string word) {
        bool found = f(root, word, 0);
        return found;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */