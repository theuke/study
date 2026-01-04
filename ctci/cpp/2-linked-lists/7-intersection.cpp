/* Intersection:
 * Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting
 * node. Note that the intersectino is defined based on reference, not value. That is, the kth
 * node of the first linked list is the exact same node (by reference) as the jth node of the
 * second linked list, then they are intersecting.
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
private:
    int getListSize(const Node *list) {
        int count = 0;

        while (list != nullptr) {
            ++count;
            list = list->next;
        }

        return count;
    }
    
    const Node *getListTail(const Node *list) {
        while (list->next != nullptr) {
            list = list->next;
        }

        return list;
    }

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
    const Node *intersection(const Node *l1, const Node *l2) {
        // The only way we can really know that two lists intersect
        // is by traversing both lists to the end and comparing their
        // last node. If the last node is the same, then both lists intersect somewhere.
        //
        // To identify the intersectig node, we just need to iterate (forwards) both lists
        // and identify the first instance of both lists pointing to the same node. Becaues
        // the lists may be of differeign sizes, we need to "normalize" by skipping over the
        // first diff = |length(l1) - length(l2)| nodes of the longer list.

        if (getListTail(l1) != getListTail(l2)) return nullptr;

        const int l1_size = getListSize(l1);
        const int l2_size = getListSize(l2);
        const int diff_size = abs(l1_size - l2_size);

        const Node *short_iter;
        const Node *long_iter;

        if (l1_size < l2_size) {
            short_iter = l1;
            long_iter = l2;
        } else {
            short_iter = l2;
            long_iter = l1;
        }

        for (int i = 0; i < diff_size; ++i)
            short_iter = short_iter->next;

        while (short_iter != long_iter) {
            short_iter = short_iter->next;
            long_iter = long_iter->next;
        }

        return short_iter;
    }
};

struct TestCase {
    Node *input1;
    Node *input2;
    Node *output;
};

int main() {
    Solution solution;

    Node *input1_5 = new Node(1);
    Node *input1_4 = new Node(2, input1_5);
    Node *input1_3 = new Node(0, input1_4);
    Node *input1_2 = new Node(2, input1_3);
    Node *input1 = new Node(1, input1_2);

    Node *input2_2 = new Node(8, input1_3);
    Node *input2 = new Node(9, input2_2);

    std::vector<TestCase> cases = {
        {
            input1,
            input2,
            input1_3
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        const Node *output = solution.intersection(testCase->input1, testCase->input2);
        assert(output == testCase->output);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}