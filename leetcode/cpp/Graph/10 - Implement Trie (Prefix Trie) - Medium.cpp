#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

// // Most readable but marginally less efficient.
class Trie {
private:
    typedef struct Node_t
    {
        char val;
        bool is_complete;
        map<const char, Node_t *> children;
    } Node_t;
    
    Node_t *root;

    Node_t *find(string& prefix)
    {
        Node_t *node = root;
        const char *letter = prefix.c_str();

        while (*letter != '\0')
        {
            if (!node->children.count(*letter))
                return NULL;

            node = node->children[*letter];
            ++letter;
        }

        return node;
    }

public:
    Trie() {
        // Instantiate the root node so that we always have reference to it.
        root = new Node_t;
        root->val = '\0';
        root->is_complete = false;
    }
    
    void insert(string word) {
        // To insert a word into the trie, simply need to traverse down
        // the trie, matching up the letters of the word with the node elements.
        // If the node element(s) does not exist, simply create them as we go.
        // Once we reach the last character of the word (not considering null
        // terminator) then mark then set that last node's is_complete flag.
        Node_t *node = root;
        const char *letter = word.c_str();

        while (*letter != '\0')
        {
            if (!node->children.count(*letter))
            {
                Node_t *child_node = new Node_t;
                child_node->val = *letter;
                child_node->is_complete = false;
                node->children[*letter] = child_node;
            }

            node = node->children[*letter];
            ++letter;
        }

        node->is_complete = true;
    }
    
    bool search(string word) {
        Node_t *terminating_node = find(word);
        return terminating_node && terminating_node->is_complete;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    Trie trie;
    vector<bool> my_answer;

    trie.insert("apple");
    my_answer.push_back(trie.search("apple"));      // return True
    my_answer.push_back(trie.search("app"));        // return False
    my_answer.push_back(trie.startsWith("app"));    // return True
    trie.insert("app");
    my_answer.push_back(trie.search("app"));        // return True
    vector<bool> answer = { true, false, true, true };

    cout << "done" << endl;

    // cout << "answer    = " << answer << endl;
    // cout << "my_answer = " << my_answer << endl;
}