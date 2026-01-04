/* Stack of Plates:
 * Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
 * Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
 * thershold. Implement a data structure SetOfStacks that mimics this. SetOfStack should be composed
 * of several stacks and should create a new stack once the previous one exceeds capacity.
 * SetOfStacks.push() sand SetOfStacks.pop() should behave identically to a single stack (that is,
 * pop() should return the same value as it would if there were just a single stack).
 * 
 * FOLLOW UP:
 * Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <stack>

template <typename T>
class SetOfStacks {
private:
  std::vector<std::stack<T>> stacks;
  int topStackIndex;
  int threshold;

  SetOfStacks() = default;

  void setNextTopStackIndex() {
    while (topStackIndex > 0 && stacks[topStackIndex].empty())
      --topStackIndex;
  }

public:
  SetOfStacks(const int threshold) {
    this->topStackIndex = 0;
    this->threshold = threshold;
  }

  void push(const T& value) {
    if (stacks[topStackIndex].size() == threshold)
      ++topStackIndex;

    stacks[topStackIndex].push(value);
  }

  void pop() {
    stacks[topStackIndex].pop();
    setNextTopStackIndex();
  }

  void popAtIndex(const int index) {
    if (index == topStackIndex) {
      pop();
    } else if (index < topStackIndex && index >= 0) {
      if (!stacks[index].empty())
        stacks[index].pop();
    } else {
      assert(false);
    }
  }
};
