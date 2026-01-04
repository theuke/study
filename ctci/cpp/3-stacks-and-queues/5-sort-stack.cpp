/* Sort Stack:
 * Write a program to sort a stack such that the smallest items are on the top. You can use
 * an additional temporary stack, but you may not copy the elements into any other data structure
 * (such as an array). The stack supports the following operations: push, pop, peek, isEmpty.
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <stack>


class Solution {
private:
  int extractMax(std::stack<int> &source, std::stack<int> &target, const int depth) {
    int max = source.top();
    source.pop();

    for (int i = 1; i < depth; ++i) {
      int top = source.top();
      source.pop();

      if (top > max) {
        target.push(max);
        max = top;
      } else {
        target.push(top);
      }
    }

    return max;
  }

public:
  void sortStack(std::stack<int> &stack) {
    // The idea here is to, iterativley, extract the largest element from the stack
    // and push it onto the now empty stack (all of the other values are stored
    // in the tempStack at this time). Repeat this procedure for N times. Note
    // that in the end result we want to end up with the sort stack being stored
    // in the original stack.

    int stackSize = stack.size();

    if (stackSize == 0) return;

    std::stack<int> tempStack;

    // The first extraction is special.
    stack.push(extractMax(stack, tempStack, stackSize));

    std::stack<int> *source = &tempStack;
    std::stack<int> *target = &stack;
    int prevMax;

    for (int i = stackSize - 1; i > 0; --i) {
      const int max = extractMax(*source, *target, i);
      if (source == &stack) {
        stack.push(prevMax);
        stack.push(max);
        source = &tempStack;
        target = &stack;
      } else {
        prevMax = max;
        source = &stack;
        target = &tempStack;
      }
    }

    // If the stack size is even, that means a single element will be left in the
    // tempStack after the above loop finishes executing.
    if (!(stackSize & 1))
      stack.push(prevMax);
  }
};

struct TestCase {
    std::stack<int> input;
    std::stack<int> output;
};

int main() {
    Solution solution;

    std::stack<int> input1;
    input1.push(1);
    input1.push(3);
    input1.push(5);
    input1.push(7);
    input1.push(9);
    std::stack<int> output1;
    output1.push(9);
    output1.push(7);
    output1.push(5);
    output1.push(3);
    output1.push(1);
    std::vector<TestCase> cases = {
        {
            input1,
            output1
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        solution.sortStack(testCase->input);
        std::stack<int> &output = testCase->input;
        assert(output.size() == testCase->output.size());
        while (!output.empty()) {
          assert(output.top() == testCase->output.top());
          output.pop();
          testCase->output.pop();
        }
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}