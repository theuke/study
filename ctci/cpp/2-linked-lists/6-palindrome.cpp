/* Palindrome:
 * Implement a function to check if a linked list is a palindrome.
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
    bool isPalindrome(Node *list) {
        // A palindrome is a number that is read the same forwads as it is backwards.
        // The easiest way to check if a linked list is a palindrome is to reverse the
        // the list and then simply iterate, in lock step, over the two lists and ensure
        // they are the same. Actually, we only have to iterate over ceil(list_size / 2)
        // nodes.
        Node *list_reverse = reverseList(cloneList(list));
        const int numIterations = (getListSize(list) + 1) / 2;

        for (int i = 0; i < numIterations; ++i) {
            if (list->data != list_reverse->data)
                return false;
            
            list = list->next;
            list_reverse = list_reverse->next;
        }
        
        return true;
    }
};

struct TestCase {
    Node *input;
    bool output;
};

int main() {
    Solution solution;

    Node *input1_5 = new Node(1);
    Node *input1_4 = new Node(2, input1_5);
    Node *input1_3 = new Node(0, input1_4);
    Node *input1_2 = new Node(2, input1_3);
    Node *input1 = new Node(1, input1_2);
    std::vector<TestCase> cases = {
        {
            input1,
            true
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        const bool output = solution.isPalindrome(testCase->input);
        assert(output == testCase->output);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}