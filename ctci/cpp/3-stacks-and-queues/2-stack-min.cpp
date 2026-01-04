/* Stack Min:
 * How would you design a stack which, in addition to push and pop, has a function min which returns
 * the minimum element? Push, pop, and min should all operate in O(1) time.
*/

// One option is to maintain a shadow stack which keeps track of the min for each level of the stack.
// Howver, this is not a very memory efficient method. A better approach is to maintain a shadow stack
//
// Simply need to maintain two stacks. One actual stack and the other a min stack.
// on push(): if new item is greater than or equal to top of minStack, push it on the min stack too.
// on pop():  if item being popped is equal to top of minStack, pop min stack.
// on min():  return minStack.peek()

5 2 3 4 3 4 5 8 7 9
  2 3   3 4 5   7 9