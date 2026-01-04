/* Partition:
 * Write code to partitino a linkedl ist around a value x, such that all nodes less than x
 * come before all nodes greater than or equal to x. (IMPORTANT: The partition element x can appear
 * anywhere in the "right partition"; it does not need to appear between the left and right partitions.
 * The additional spacing in the example below indicates the partition. Yes, the output below is one of
 * many valid outputs!)
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
    const Node *partition(Node *head, const int val) {
        // In order to partition a linked list on a value, iterate through the linked
        // list and simply move all nodes whose value is less than the partition value
        // to the head of the list.

        Node *newHead = head;
        Node *iter = head;

        while (iter->next != nullptr) {
            if (iter->next->data < val) {
                // Remove node and move it to the front of the list.
                Node *temp = iter->next;
                iter->next = iter->next->next;
                temp->next = newHead;
                newHead = temp;
            } else {
                iter = iter->next;
            }
        }

        return newHead;
    }
};

struct TestCase {
    Node *input;
    const int val;
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

    Node *output1_7 = new Node(10);
    Node *output1_6 = new Node(5, output1_7);
    Node *output1_5 = new Node(8, output1_6);
    Node *output1_4 = new Node(5, output1_5);
    Node *output1_3 = new Node(3, output1_4);
    Node *output1_2 = new Node(2, output1_3);
    Node *output1 = new Node(1, output1_2);
    std::vector<TestCase> cases = {
        {
            input1,
            5,
            output1
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        const Node *output = solution.partition(testCase->input, testCase->val);
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