#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Trie {
public:
  vector<Trie *> children;
  bool isWord;
  Trie() : children(26, nullptr), isWord(false) {}
};
class Solution {
  Trie *root;

public:
  Solution() {
    root = new Trie();
  }
  string replaceWords(vector<string> &dictionary, string sentence) {
    // we first construct a Tride from the words
    for (string &word : dictionary) {
      this->insert(word);
    }

    stringstream ss(sentence);
    string word, result;
    while (ss >> word) {
      if (!result.empty()) {
        result += " ";
      }
      result += this->search(word);
    }
    return result;
  }

  void insert(string word) {
    Trie *node = root;
    for (char ch : word) {
      int index = ch - 'a';
      if (!node->children[index]) {
        // make new Tride node
        node->children[index] = new Trie();
      }
      node = node->children[index];
    }

    node->isWord = true;
  }

  string search(string word) {
    // search for the prefix of this word, and return it
    Trie *node = root;
    string prefix = "";
    for (char ch : word) {
      int index = ch - 'a';
      if (!node->children[index]) {
        if (node->isWord) {
          return prefix;
        }
        return word;
      }
      // the character is in the array
      prefix += ch;
      if (node->children[index]->isWord) {
        return prefix;
      }
      node = node->children[index];
    }
    return word;
  }
};