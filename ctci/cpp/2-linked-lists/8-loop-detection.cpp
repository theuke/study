/* Loop Detection:
 * Given a linked list which might contain a loop, implement an algorithm that
 * returns the node at the beginning of the loop (if one exists).
 * EXAMPLE:
 * Input:   A -> B -> C -> D -> E -> C [the same C as earlier]
 * Output:  C
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <set>

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
    const Node *loopDetectionWithMap(const Node *list) {
        // The simplest method for detecting a loop would be to maintain a set
        // of node addresses. The first time a node is encountered which is already
        // in the set, that node constitutes the beginning of the loop.

        std::set<const Node *> nodeSet;

        while (list != nullptr) {
            if (nodeSet.count(list) > 0)
                return list;
            else
                nodeSet.insert(list);
            
            list = list->next;
        }

        return nullptr;
    }

    const Node *loopDetectionWithRunner(const Node *list) {
        // If we are not able to use a map, then detecting the loop and identifying its
        // starting point is more difficult. The basic idea is to perform loop detection
        // via the classical slow / fast runner method. Note that only indicates the
        // presence of a loop. In order to get the loop start node, we must stop iteration
        // of the fast and slow runner once they collide, and then create two slow runners.
        // One slow runner will be at the start of the list an the other will be at collisionStart.
        // Now, when these two slows runners collide, that constitutes the start of the loop.

        if (list == nullptr) return nullptr;

        const Node *slowRunner = list;
        const Node *fastRunner = list;

        while (slowRunner != nullptr && fastRunner != nullptr && fastRunner->next != nullptr) {
            slowRunner = slowRunner->next;
            fastRunner = fastRunner->next->next;
            if (slowRunner == fastRunner) break;
        }

        // If slow and fastRunner are the same, that is the collision point. Note that it is
        // not possible for these to both be null at this point.
        if (slowRunner == fastRunner) {
            // Move fastRunner to the start of the linked list and increment both slow and fast runner
            // one step at a time. Once they collide, we have found the start of the loop.
            fastRunner = list;

            while (slowRunner != fastRunner) {
                slowRunner = slowRunner->next;
                fastRunner = fastRunner->next;
            }

            return slowRunner;
        }

        return nullptr;
    }
};

struct TestCase {
    Node *input;
    Node *output;
};

int main() {
    Solution solution;

    Node *input1_5 = new Node(5);
    Node *input1_4 = new Node(4, input1_5);
    Node *input1_3 = new Node(3, input1_4);
    Node *input1_2 = new Node(2, input1_3);
    Node *input1 = new Node(1, input1_2);
    input1_5->next = input1_3;

    std::vector<TestCase> cases = {
        {
            input1,
            input1_3
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        const Node *output = solution.loopDetectionWithMap(testCase->input);
        assert(output == testCase->output);
        output = solution.loopDetectionWithRunner(testCase->input);
        assert(output == testCase->output);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}