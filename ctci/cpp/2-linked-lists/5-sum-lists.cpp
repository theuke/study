/* Sum Lists:
 * You have two numbers represented by a linked list, where each node cnotains a single digit.
 * The digits are stored in reverse order, such that the 1's digit is at the head of the list.
 * Write a function that adds the two numbers and returns teh sum as a linked list. (You are not
 * allowed to "cheat" and just convert the linked list to an integer).
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

class Node {
public:
    int data;
    Node *next;

    Node() {
        this->next = nullptr;
    }
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
private:
    Node *cloneList(const Node *head) {
        Node *newHead = nullptr;
        Node *newTail = nullptr;

        const Node *iter = head;

        while (iter != nullptr) {
            if (newHead == nullptr) {
                newHead = new Node();
                newTail = newHead;
            } else {
                newTail->next = new Node();
                newTail = newTail->next;
            }
            newTail->data = iter->data;
            iter = iter->next;
        }

        return newHead;
    }

    Node *reverseList(Node *head) {
        Node *prevIter = head;
        Node *currIter = prevIter->next;

        if (currIter == nullptr) return head;

        prevIter->next = nullptr;
        Node *nextIter = currIter->next;

        while (currIter != nullptr) {
            currIter->next = prevIter;
            prevIter = currIter;
            currIter = nextIter;
            if (nextIter != nullptr)
                nextIter = nextIter->next;
        }

        head = prevIter;

        return head;
    }

public:
    Node *sumLists(const Node *l1, const Node *l2) {
        // Because we will be summing via linked lists, we need to simply iterate, in tandem,
        // through l1 and l2 and sum the digits and calculate / propogate the carry to the next
        // node as appropriate. Additionally, we need to dynamically allocate the nodes as we go.

        Node *sumHead = nullptr;
        Node *sumTail = nullptr;
        const Node *iter1 = l1;
        const Node *iter2 = l2;
        int carry = 0;

        // First iterate over the two lists until both of them end.
        while (iter1 != nullptr || iter2 != nullptr) {
            if (sumHead == nullptr) {
                sumHead = new Node();
                sumTail = sumHead;
            } else {
                sumTail->next = new Node();
                sumTail = sumTail->next;
            }

            int sum = carry;
            if (iter1 != nullptr) sum += iter1->data;
            if (iter2 != nullptr) sum += iter2->data;

            int intermediateSum = sum;
            carry = 0;
            if (sum >= 10) {
                intermediateSum -= 10;
                carry = 1;
            }

            sumTail->data = intermediateSum;

            if (iter1 != nullptr) iter1 = iter1->next;
            if (iter2 != nullptr) iter2 = iter2->next;
        }

        if (carry == 1) {
            sumTail->next = new Node();
            sumTail = sumTail->next;
            sumTail->data = 1;
        }

        return sumHead;
    }

    const Node *sumListsForward(Node *l1, Node *l2) {
        // The procedure here is the same as for summing the lists in reverse
        // order once once the input lists are reversed. Additionally, the
        // outputted list (in reverse order) must be reversed.
        Node *l1_reverse = cloneList(l1);
        Node *l2_reverse = cloneList(l2);
        l1_reverse = reverseList(l1_reverse);
        l2_reverse = reverseList(l2_reverse);
        Node *sum_reverse = sumLists(l1_reverse, l2_reverse);
        Node *sum = reverseList(sum_reverse);
        return sum;
    }
};

struct TestCase {
    Node *input1;
    Node *input2;
    const Node *output;
};

int main() {
    Solution solution;

    // Lists are in reverse order.
    Node *input1_1_3 = new Node(6);
    Node *input1_1_2 = new Node(1, input1_1_3);
    Node *input1_1 = new Node(7, input1_1_2);

    Node *input1_2_3 = new Node(2);
    Node *input1_2_2 = new Node(9, input1_2_3);
    Node *input1_2 = new Node(5, input1_2_2);

    Node *output1_3 = new Node(9);
    Node *output1_2 = new Node(1, output1_3);
    Node *output1 = new Node(2, output1_2);
    std::vector<TestCase> cases1 = {
        {
            input1_1,
            input1_2,
            output1
        }
    };

    for (int i = 0; i < cases1.size(); ++i) {
        TestCase *testCase = &cases1.at(i);
        const Node *output = solution.sumLists(testCase->input1, testCase->input2);
        const Node *expected = testCase->output;
        while (output != nullptr && expected != nullptr) {
            assert(output->data == expected->data);
            output = output->next;
            expected = expected->next;
        }
        assert(output == expected);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }

    // Lists are in forward order.
    Node *input2_1_3 = new Node(7);
    Node *input2_1_2 = new Node(1, input2_1_3);
    Node *input2_1 = new Node(6, input2_1_2);

    Node *input2_2_3 = new Node(5);
    Node *input2_2_2 = new Node(9, input2_2_3);
    Node *input2_2 = new Node(2, input2_2_2);

    Node *output2_3 = new Node(2);
    Node *output2_2 = new Node(1, output2_3);
    Node *output2 = new Node(9, output2_2);
    std::vector<TestCase> cases2 = {
        {
            input2_1,
            input2_2,
            output2
        }
    };

    for (int i = 0; i < cases2.size(); ++i) {
        TestCase *testCase = &cases2.at(i);
        const Node *output = solution.sumListsForward(testCase->input1, testCase->input2);
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