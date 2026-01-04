/* Delete Middle Node:
 * Implement an algorithm to delete a node in the middle (i.e., any node but the first
 * abd kast node, not necessarily the exact middle) of a singly linked list, given access
 * only to that node.
 * EXAMPLE
 * Input: the nde c from the linked list a -> b -> c -> d -> e -> f
 * Result: nothing is returned, but the new linked list looks like a -> b -> d -> e -> f
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
    void deleteMiddleNode(Node *node) {
        // Best and simplest method is to simply copy both the value and next pointer of the
        // next node to the node being deleted. This effectivley does the deletion.
        node->data = node->next->data;
        node->next = node->next->next;

        // // Witout havign access to the previous node, this means we can only change the
        // // node supplied to us and all subsequent nodes. One approach is shown below.
        // while (node->next != nullptr) {
        //     node->data = node->next->data;
        //     if (node->next->next == nullptr)
        //         node->next = nullptr;
        //     else
        //         node = node->next;
        // }
        // node->next = nullptr;
    }
};

struct TestCase {
    Node *input;
    Node *nodeToRemove;
    const Node *output;
};

int main() {
    Solution solution;

    Node *input1_7 = new Node(1);
    Node *input1_6 = new Node(2, input1_7);
    Node *input1_5 = new Node(10, input1_6);
    Node *input1_4 = new Node(5, input1_5);
    Node *input1_3 = new Node(8, input1_4);
    Node *input1_2 = new Node(5, input1_3);
    Node *input1 = new Node(3, input1_2);

    Node *output1_7 = new Node(1);
    Node *output1_6 = new Node(2, output1_7);
    Node *output1_5 = new Node(10, output1_6);
    Node *output1_3 = new Node(8, output1_5);
    Node *output1_2 = new Node(5, output1_3);
    Node *output1 = new Node(3, output1_2);
    std::vector<TestCase> cases = {
        {
            input1,
            input1_4,
            output1
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        solution.deleteMiddleNode(testCase->nodeToRemove);
        const Node *output = testCase->input;
        const Node *expected = testCase->output;
        while (output != nullptr && expected != nullptr) {
            assert(output->data == expected->data);
            output = output->next;
            expected = expected->next;
        }
        assert(output == expected);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}