/* Remove Dups:
 * Write code to remove duplicates from an unsorted linked lit.
 * FOLLOW UP: How would you solve this problem is a temporary buffer is not allowed?
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

class Node {
public:
    int data;
    Node *next;

    Node() {}
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

class Solution {
public:
    Node *removeDups(Node *head) {
        // The simplest way to remove duplicates from the linked list is to
        // maintain a frequency count hash table. If a data value has already appeared before,
        // then remove that node.

        // In order to solve this problem without using a temporary buffer, the linked list should
        // be sorted. Then, iterate over the linkd list and simply skip over duplicate values (i.e.
        // make a connection from the first duplicate of value A to the first duplicate of value B).
        // The challenge then is simply in sorting a linked list without using a temporary buffer.

        // Since sorting the linked list is difficult, a simpler way to remmove duplicates is to just
        // do a "nested" loop of the linked list. Basically iter iterates through the linked list and theh
        // a subIter iterates through the remaining elements of the linked list looking for copies and removing them.
    }
};

struct TestCase {
    Node *input;
    Node *output;
};

int main() {
    Solution solution;

    Node *input1_5 = new Node(1);
    Node *input1_4 = new Node(3, input1_5);
    Node *input1_3 = new Node(4, input1_4);
    Node *input1_2 = new Node(1, input1_3);
    Node *input1 = new Node(2, input1_2);

    Node *output1_4 = new Node(1);
    Node *output1_3 = new Node(3, output1_4);
    Node *output1_2 = new Node(4, output1_3);
    Node *output1 = new Node(2, output1_2);
    std::vector<TestCase> cases = {
        {
            input1,
            output1
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        Node *output = solution.removeDups(testCase->input);
        Node *expected = testCase->output;
        while (output != nullptr && expected != nullptr) {
            assert(output->data == expected->data);
            output = output->next;
            expected = expected->next;
        }
        assert(output == expected);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}