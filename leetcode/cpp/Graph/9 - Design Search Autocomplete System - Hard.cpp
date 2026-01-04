#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

class AutocompleteSystem {
private:
    typedef struct Node_t
    {
        char val;
        int count;
        map<const char, Node_t *> children;
    } Node_t;

    Node_t *root;
    Node_t *curr_node;
    string curr_prefix;

    void dfs(Node_t*& node, string& prefix, vector<int>& top_hits_counts, vector<string>& top_hits)
    {
        int index_in_top_hits = -1;
        for (int i = top_hits_counts.size() - 1; i >= 0; --i)
        {
            if (node->count > top_hits_counts[i] ||
                (node->count == top_hits_counts[i] && prefix.compare(top_hits[i]) < 0))
            {
                index_in_top_hits = i;
            }
        }

        if (index_in_top_hits >= 0)
        {
            for (int i = top_hits_counts.size() - 1; i > index_in_top_hits; --i)
            {
                top_hits_counts[i] = top_hits_counts[i - 1];
                top_hits[i] = top_hits[i - 1];
            }

            top_hits_counts[index_in_top_hits] = node->count;
            top_hits[index_in_top_hits] = prefix;
        }

        map<const char, Node_t *>::iterator iter;

        for (iter = node->children.begin(); iter != node->children.end(); ++iter)
        {
            Node_t *child_node = iter->second;
            prefix.push_back(child_node->val);
            dfs(child_node, prefix, top_hits_counts, top_hits);
        }

        prefix.pop_back();
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        int sentences_size = sentences.size();

        // Instantiate the root item.
        root = new Node_t;
        root->val = '0';
        root->count = 0;

        // Iterate over all of the sentences and add them to the trie.
        for (int i = 0; i < sentences_size; ++i)
        {
            string *sentence = &sentences[i];
            int sentence_size = (*sentence).size();

            Node_t *node = root;

            for (int j = 0; j < sentence_size; ++j)
            {
                const char curr_char = (*sentence)[j];

                if (!node->children.count(curr_char))
                {
                    // Add a new node to the trie.
                    Node_t *child_node = new Node_t;
                    child_node->val = curr_char;
                    child_node->count = 0;
                    node->children[curr_char] = child_node;
                }

                node = node->children[curr_char];
            }

            // Set the count of the sentence.
            node->count = times[i];
        }

        // Set the current node to be the root and the current prefix as empty.
        curr_node = root;
        curr_prefix = "";
    }
    
    vector<string> input(char c) {
        vector<string> top_hits(3, "");

        if (c == '#')
        {
            // So long as the current node is not the root node
            // (i.e. we had some previous, non terminating, input)
            // then we should increment the count of the current node,
            // set the current prefix to its defualt value (empty) and
            // reset the currenet node to be at the root.
            if (curr_node != root)
            {
                ++curr_node->count;
                curr_prefix = "";
                curr_node = root;
            }
        }
        else
        {
            if (!curr_node->children.count(c))
            {
                // Add a new node to the trie.
                Node_t *child_node = new Node_t;
                child_node->val = c;
                child_node->count = 0;
                curr_node->children[c] = child_node;
            }

            curr_node = curr_node->children[c];
            curr_prefix.push_back(c);

            // Need to perform a search of the tree defined by the current node.
            // Note we only consider a string if its count is greater than 0.
            // We can do either a BFS or DFS here tree traversal here, however, this
            // problem prefers a DFS as it allows us to re-use a prefix string for
            // the entire procedure;
            string prefix = curr_prefix;
            vector<int> top_hits_counts(3, 0);
            dfs(curr_node, prefix, top_hits_counts, top_hits);
        }

        while (!top_hits.empty() && top_hits.back()[0] == '\0')
            top_hits.pop_back();

        return top_hits;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

int main()
{
    vector<string> sentences {"i love you", "island", "iroman", "i love leetcode"};
    vector<int> times {5, 3, 2, 2};

    // vector<char> inputs {'i', ' ', 'a', '#'};
    // vector<vector<string>> answer
    // {
    //     {"i love you", "island", "i love leetcode"},
    //     {"i love you", "i love leetcode"},
    //     { },
    //     { }
    // };

    vector<char> inputs {'i', ' ', 'a', '#', 'i', ' ', 'a', '#', 'i', ' ', 'a', '#'};
    vector<vector<string>> answer
    {
        {"i love you", "island", "i love leetcode"},
        {"i love you", "i love leetcode"},
        { },
        { },
        {"i love you", "island", "i love leetcode"},
        {"i love you", "i love leetcode", "i a"},
        {"i a"},
        { },
        {"i love you", "island", "i a"},
        {"i love you", "i a", "i love leetcode"},
        {"i a"},
        { }
    };

    AutocompleteSystem solution(sentences, times);

    vector<vector<string>> my_answer;

    for (int i = 0; i < inputs.size(); ++i)
        my_answer.push_back(solution.input(inputs[i]));
    
    cout << "done" << endl;

    // for (int i = 0; i < inputs.size(); ++i)
    // {
    //     cout << "answer    = " << answer[i] << endl;
    //     cout << "my_answer = " << my_answer[i] << "\n" << endl;
    // }
}