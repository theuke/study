/* Queue via Stacks:
 * Implement a MyQueue class which implements a queue using two stacks.
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <stack>

template <typename T>
class MyQueue {
private:
  std::stack<T> s1;
  std::stack<T> s2;

  void popS1IntoS2() {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }
public:
  MyQueue() {}

  void push(const T& value) {
    s1.push(value);
  }

  T back() {
    s1.top();
  }

  void pop() {
    popS1IntoS2();
    s2.pop();
  }

  T front() {
    popS1IntoS2();
    return s2.top();
  }

  bool empty() {
    return s1.empty() && s2.empty();
  }

  int size() {
    return s1.size() + s2.size();
  }
};
