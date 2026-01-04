/* Return Kth to Last:
 * Implement an algorithim to find the kth to last element of a singly linkd list.
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
    const Node *kthToLast(const Node *head, const int k) {
        // The approach here is to simply have to pointers, last and kthToLast and to keep a distance
        // of k element between them. Initally the distance is liable to be less than k, but once it does
        // hit k distance, we simply make sure to move kthToLast forward on each iteration.

        const Node *last = head;
        const Node *kthToLast = head;
        int distance = 0;

        while (last->next != nullptr) {
            last = last->next;
            if (distance == k)
                kthToLast = kthToLast->next;
            else
                ++distance;
        }

        return kthToLast;
    }
};

struct TestCase {
    const Node *input;
    const int k;
    const Node *output;
};

int main() {
    Solution solution;

    Node *input1_5 = new Node(1);
    Node *input1_4 = new Node(3, input1_5);
    Node *input1_3 = new Node(4, input1_4);
    Node *input1_2 = new Node(1, input1_3);
    Node *input1 = new Node(2, input1_2);
    std::vector<TestCase> cases = {
        {
            input1,
            3,
            input1_2
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        const Node *output = solution.kthToLast(testCase->input, testCase->k);
        assert(output == testCase->output);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}