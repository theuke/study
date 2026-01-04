#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

class Solution {
private:
    typedef struct Node_t
    {
        char val;
        int indegree;
        set<Node_t *> children;
        set<Node_t *> parents;
    } Node_t;

public:
    string alienOrder(vector<string>& words) {
        int words_size = words.size();

        // Create a hash map of all of the letters in each word.
        map<const char, Node_t *> nodes;

        for (int i = 0; i < words_size; ++i)
        {
            int word_size = words[i].size();

            for (int j = 0; j < word_size; ++j)
            {
                if (!nodes.count(words[i][j]))
                {
                    Node_t *node = new Node_t;
                    node->val = words[i][j];
                    node->indegree = 0;
                    nodes[node->val] = node;
                }
            }
        }

        string *curr_word = &words[0];
        string *next_word = &words[1];
        bool edge_case = false;

        // Keep comparing the current word and the next word until
        // the current word is the last word in the dictionary of words.
        // At the conclusion of this routine we will have generated a
        // node based graph.
        while(next_word - &words[0] < words_size && !edge_case)
        {
            int curr_word_size = curr_word->size();
            int next_word_size = next_word->size();
            int i = 0;

            // Within the sizes of the current and next words, keep iterating
            // until a difference between the two words is found.
            for (; i < curr_word_size && i < next_word_size; ++i)
                if ((*curr_word)[i] != (*next_word)[i])
                    break;
            
            const char curr_letter = (*curr_word)[i];
            const char next_letter = (*next_word)[i];

            if (curr_letter != '\0')
            {
                if (next_letter != '\0' )
                {
                    Node_t *curr_node = nodes[curr_letter];
                    Node_t *next_node = nodes[next_letter];
                    curr_node->children.insert(next_node);

                    if (!next_node->parents.count(curr_node))
                        next_node->indegree += 1;
                    
                    next_node->parents.insert(curr_node);
                }
                else
                {
                    return "";
                }
            }

            ++curr_word;
            ++next_word;
        }

        // Iterate through the hashmap and add all indegree 0 elements to it.
        queue<Node_t *> q;
        map<const char, Node_t *>::iterator iter;

        for (iter = nodes.begin(); iter != nodes.end(); ++iter)
        {
            Node_t *node = iter->second;

            if (node->indegree == 0)
                q.push(node);
        }

        string output = "";

        while (!q.empty())
        {
            Node_t *node = q.front();
            q.pop();

            output.push_back(node->val);

            set<Node_t *>::iterator iter;

            for (iter = node->children.begin(); iter != node->children.end(); ++iter)
            {
                Node_t *child_node = *iter;

                --child_node->indegree;

                if (child_node->indegree == 0)
                    q.push(child_node);
            }
        }

        if (output.size() != nodes.size())
            output = "";

        return output;
    }
};

int main()
{
    // vector<string> words {"wrt","wrf","er","ett","rftt"};
    // string answer = "wertf";

    // vector<string> words {"wr","wrt","er","ett","rfw","rfg","rftt", "rftw"};
    // string answer = "";

    vector<string> words {"k","k","faxnpvtf","ededoi","rkxxphs","uhs","act","gggaghn","gepxteth","uasxztf","pqf","ocwgcapf","bhuhwppma","rsaihyyfk","pmjxgyqf","pq","kazj"};
    string answer = "";

    Solution solution;
    string my_answer = solution.alienOrder(words);

    cout << "answer    = " << answer << endl;
    cout << "my_answer = " << my_answer << endl;
}