# 1. C++ STL Container Cheat Sheet

## 1.1. Table of Contents

- [1. C++ STL Container Cheat Sheet](#1-c-stl-container-cheat-sheet)
  - [1.1. Table of Contents](#11-table-of-contents)
  - [1.2. Sequence Containers](#12-sequence-containers)
    - [1.2.1. Vector](#121-vector)
      - [1.2.1.1. Common Methods](#1211-common-methods)
      - [1.2.1.2. Example Usage](#1212-example-usage)
    - [1.2.2. List](#122-list)
      - [1.2.2.1. Common Methods](#1221-common-methods)
      - [1.2.2.2. Example Usage](#1222-example-usage)
    - [1.2.3. Deque](#123-deque)
      - [1.2.3.1. Common Methods](#1231-common-methods)
      - [1.2.3.2. Example Usage](#1232-example-usage)
  - [1.3. Container Adapters](#13-container-adapters)
    - [1.3.1. Stack](#131-stack)
      - [1.3.1.1. Common Methods](#1311-common-methods)
      - [1.3.1.2. Example Usage](#1312-example-usage)
    - [1.3.2. Queue](#132-queue)
      - [1.3.2.1. Common Methods](#1321-common-methods)
      - [1.3.2.2. Example Usage](#1322-example-usage)
  - [1.4. Associative Containers](#14-associative-containers)
    - [1.4.1. Set](#141-set)
      - [1.4.1.1. Common Methods](#1411-common-methods)
      - [1.4.1.2. Example Usage](#1412-example-usage)
    - [1.4.2. Map](#142-map)
      - [1.4.2.1. Common Methods](#1421-common-methods)
      - [1.4.2.2. Example Usage](#1422-example-usage)
  - [1.5. Unordered Containers](#15-unordered-containers)
    - [1.5.1. Unordered Set](#151-unordered-set)
      - [1.5.1.1. Common Methods](#1511-common-methods)
      - [1.5.1.2. Example Usage](#1512-example-usage)
    - [1.5.2. Unordered Map](#152-unordered-map)
      - [1.5.2.1. Common Methods](#1521-common-methods)
      - [1.5.2.2. Example Usage](#1522-example-usage)
  - [1.6. Quick Reference Summary](#16-quick-reference-summary)
    - [1.6.1. Container Selection Guide](#161-container-selection-guide)

---

## 1.2. Sequence Containers

### 1.2.1. Vector

**Description**: Dynamic array that can resize automatically. Provides fast random access.

#### 1.2.1.1. Common Methods

| Method        | Complexity | Description                                                           |
| ------------- | ---------- | --------------------------------------------------------------------- |
| `begin()`     | O(1)       | Returns an iterator to the first element                              |
| `end()`       | O(1)       | Returns an iterator to the theoretical element after the last element |
| `size()`      | O(1)       | Returns the number of elements present                                |
| `empty()`     | O(1)       | Returns true if the vector is empty, false otherwise                  |
| `at()`        | O(1)       | Return the element at a particular position                           |
| `assign()`    | O(n)       | Assign a new value to the vector elements                             |
| `push_back()` | O(1)       | Adds an element to the back of the vector                             |
| `pop_back()`  | O(1)       | Removes an element from the end                                       |
| `insert()`    | O(n)       | Insert an element at the specified position                           |
| `erase()`     | O(n)       | Delete the elements at a specified position or range                  |
| `clear()`     | O(n)       | Removes all elements                                                  |

#### 1.2.1.2. Example Usage

```cpp
#include <iostream>
#include <vector>
using namespace std;

int vector_example()
{
  // 1d vector with initialization list
  vector<int> v1 = {1, 2, 3, 4, 5};
  // 2d vector with size and element value initialization
  vector<vector<int>> v2(3, vector<int>(3, 5));

  // adding values using push_back()
  v1.push_back(6);
  // printing v1 using size()
  cout << "v1: ";
  for (int i = 0; i < v1.size(); i++)
  {
    cout << v1[i] << " ";
  }
  cout << endl;

  v1.erase(v1.begin() + 4);
  // printing v1 using iterators
  cout << "v1: ";
  for (auto i = v1.begin(); i != v1.end(); i++)
  {
    cout << *i << " ";
  }

  // printing v2 using range based for loop
  cout << "v2:-" << endl;
  for (auto i : v2)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
```

---

### 1.2.2. List

**Description**: Doubly-linked list that allows fast insertion and deletion at both ends and in the middle.

#### 1.2.2.1. Common Methods

| Method         | Complexity | Description                                                           |
| -------------- | ---------- | --------------------------------------------------------------------- |
| `begin()`      | O(1)       | Returns an iterator to the first element                              |
| `end()`        | O(1)       | Returns an iterator to the theoretical element after the last element |
| `size()`       | O(1)       | Returns the number of elements in the list                            |
| `push_back()`  | O(1)       | Adds one element at the end of the list                               |
| `pop_back()`   | O(1)       | Removes a single element from the end                                 |
| `push_front()` | O(1)       | Adds a single element to the front of the list                        |
| `pop_front()`  | O(1)       | Removes a single element from the front                               |
| `insert()`     | O(1)       | Inserts an element at the specified position                          |
| `erase()`      | O(1)       | Deletes the element at the given position                             |
| `remove()`     | O(n)       | Removes all the copies of the given elements from the list            |

#### 1.2.2.2. Example Usage

```cpp
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int list_example()
{
  // creating std::list object using initializer list
  list<int> l1 = {1, 5, 9, 1, 4, 6};

  // vector for initialization
  vector<char> v = {'G', 'e', 'e', 'k', 's'};
  list<int> l2(v.begin(), v.end());

  // printing first element
  cout << "First element if l1: " << l1.front() << endl;

  // adding element
  l1.insert(l1.begin(), 5);

  // deleting element
  l1.erase(l1.begin());

  // traversing and printing l1
  cout << "l1: ";
  for (auto i = l1.begin(); i != l1.end(); i++)
  {
    cout << *i << " ";
  }
  cout << endl;

  // traversing and printing l2
  cout << "l2: ";
  for (auto i : l2)
  {
    cout << char(i);
  }
  cout << endl;

  return 0;
}
```

---

### 1.2.3. Deque

**Description**: Double-ended queue that allows fast insertion and deletion at both ends. Combines features of both stack and queue.

#### 1.2.3.1. Common Methods

| Method         | Complexity | Description                                                           |
| -------------- | ---------- | --------------------------------------------------------------------- |
| `begin()`      | O(1)       | Returns iterator to the first element                                 |
| `end()`        | O(1)       | Returns an iterator to the theoretical element after the last element |
| `at()`         | O(1)       | Access specified element                                              |
| `[]`           | O(1)       | Access element at the given index                                     |
| `front()`      | O(1)       | Returns the first element                                             |
| `back()`       | O(1)       | Returns the last element                                              |
| `size()`       | O(1)       | Returns the number of elements                                        |
| `push_back()`  | O(1)       | Add the elements at the end                                           |
| `pop_back()`   | O(1)       | Removes the elements from the end                                     |
| `push_front()` | O(1)       | Add the elements at the front                                         |
| `pop_front()`  | O(1)       | Removes the element from the front                                    |

#### 1.2.3.2. Example Usage

```cpp
#include <deque>
#include <iostream>
using namespace std;

int deque_example()
{
  // creating a deque
  deque<int> d = {1, 2, 3, 4, 5};

  // removing two elements from the back and pushing them
  // at the front
  d.push_front(d.back());
  d.pop_back();
  d.push_front(d.back());
  d.pop_back();

  for (auto i : d)
  {
    cout << i << " ";
  }

  return 0;
}
```

---

## 1.3. Container Adapters

### 1.3.1. Stack

**Description**: LIFO (Last In First Out) data structure. Provides access only to the top element.

#### 1.3.1.1. Common Methods

| Method    | Complexity | Description                                         |
| --------- | ---------- | --------------------------------------------------- |
| `empty()` | O(1)       | Returns true if the stack is empty, false otherwise |
| `size()`  | O(1)       | Returns the number of elements in the stack         |
| `top()`   | O(1)       | Returns the top element                             |
| `push(g)` | O(1)       | Push one element in the stack                       |
| `pop()`   | O(1)       | Removes one element from the stack                  |

#### 1.3.1.2. Example Usage

```cpp
#include <bits/stdc++.h>
using namespace std;

int stack_example()
{
  stack<int> s;

  for (int i = 1; i <= 5; i++)
  {
    s.push(i);
  }

  s.push(6);
  // checking top element
  cout << "s.top() = " << s.top() << endl;

  // getting all the elements
  cout << "s: ";
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }

  // size after popping all elements
  cout << "Final Size: " << s.size();

  return 0;
}
```

---

### 1.3.2. Queue

**Description**: FIFO (First In First Out) data structure. Elements are inserted at the back and removed from the front.

#### 1.3.2.1. Common Methods

| Method    | Complexity | Description                                         |
| --------- | ---------- | --------------------------------------------------- |
| `empty()` | O(1)       | Returns true if the queue is empty, otherwise false |
| `size()`  | O(1)       | Returns the number of items in the queue            |
| `front()` | O(1)       | Returns the front element                           |
| `back()`  | O(1)       | Returns the element at the end                      |
| `push()`  | O(1)       | Add an item to the queue                            |
| `pop()`   | O(1)       | Removes an item from the queue                      |

#### 1.3.2.2. Example Usage

```cpp
#include <iostream>
#include <queue>
using namespace std;

int queue_example()
{
  // creating queue
  queue<int> q;

  // pushing elements
  for (int i = 1; i <= 5; i++)
  {
    q.push(i);
  }
  q.push(6);

  cout << "q.front() = " << q.front() << endl;
  cout << "q.back() = " << q.back() << endl;

  // printing queue by popping all elements
  cout << "q: ";
  int size = q.size();
  for (int i = 0; i < size; i++)
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}
```

---

## 1.4. Associative Containers

### 1.4.1. Set

**Description**: Ordered container that stores unique elements. Implemented as a balanced BST (typically Red-Black Tree).

#### 1.4.1.1. Common Methods

| Method     | Complexity | Description                                                                          |
| ---------- | ---------- | ------------------------------------------------------------------------------------ |
| `begin()`  | O(1)       | Returns an iterator to the first element                                             |
| `end()`    | O(1)       | Return an iterator to the last element                                               |
| `size()`   | O(1)       | Returns the number of elements                                                       |
| `empty()`  | O(1)       | Checks if the container is empty                                                     |
| `insert()` | O(log n)   | Inserts a single element                                                             |
| `erase()`  | O(log n)   | Removes the given element                                                            |
| `clear()`  | O(n)       | Removes all elements                                                                 |
| `find()`   | O(log n)   | Returns the pointer to the given element if present, otherwise, a pointer to the end |

#### 1.4.1.2. Example Usage

```cpp
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int set_example()
{
  // creating vector
  vector<int> v = {1, 5, 3, 4, 2};
  // creating set using vector v
  set<int> s(v.begin(), v.end());

  // finding 4
  if (s.find(4) == s.end())
  {
    cout << "4 not found" << endl;
  }
  else
  {
    cout << "4 found" << endl;
  }

  // adding 9
  s.insert(9);

  // printing set
  cout << "s: ";
  for (set<int>::iterator i = s.begin(); i != s.end(); i++)
  {
    cout << *i << " ";
  }
  cout << endl;
  return 0;
}
```

---

### 1.4.2. Map

**Description**: Ordered associative container that stores key-value pairs. Keys are unique and sorted. Implemented as a balanced BST.

#### 1.4.2.1. Common Methods

| Method            | Complexity | Description                                                                  |
| ----------------- | ---------- | ---------------------------------------------------------------------------- |
| `begin()`         | O(1)       | Returns an iterator to the first element                                     |
| `end()`           | O(1)       | Returns an iterator to the theoretical element that follows the last element |
| `size()`          | O(1)       | Returns the number of elements in the map                                    |
| `insert()`        | O(log n)   | Adds a new element to the map                                                |
| `erase(iterator)` | O(log n)   | Removes the element at the position pointed by the iterator                  |
| `erase(key)`      | O(log n)   | Removes the key and its value from the map                                   |
| `clear()`         | O(n)       | Removes all the elements from the map                                        |
| `find()`          | O(log n)   | Returns an iterator to the element with given key                            |

#### 1.4.2.2. Example Usage

```cpp
#include <iostream>
#include <map>
using namespace std;

int map_example()
{
  // creating std::map object
  map<int, string> m;

  // adding elements
  m[1] = "ONE";
  m[2] = "TWO";
  m[3] = "THREE";

  // checking size
  cout << "Size of map m: " << m.size() << endl;

  // inserting using insert pair
  m.insert({4, "FOUR"});

  // deleting key 2 with its value
  m.erase(2);

  // printing the map
  cout << "Map:-" << endl;
  for (auto i : m)
  {
    cout << "Key: " << i.first << '\t';
    cout << "Value: " << i.second << endl;
  }

  return 0;
}
```

---

## 1.5. Unordered Containers

### 1.5.1. Unordered Set

**Description**: Unordered container that stores unique elements. Implemented using hash tables for O(1) average access time.

#### 1.5.1.1. Common Methods

| Method     | Complexity | Description                                                                          |
| ---------- | ---------- | ------------------------------------------------------------------------------------ |
| `begin()`  | O(1)       | Returns an iterator to the first element                                             |
| `end()`    | O(1)       | Returns an iterator to the theoretical element that follows the last element         |
| `size()`   | O(1)       | Returns the number of elements                                                       |
| `empty()`  | O(1)       | Returns true if the unordered_set is empty, otherwise false                          |
| `insert()` | O(1) avg   | Insert an item in the container                                                      |
| `erase()`  | O(1) avg   | Removes an element from the container                                                |
| `find()`   | O(1) avg   | Returns the pointer to the given element if present, otherwise, a pointer to the end |

#### 1.5.1.2. Example Usage

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int unordered_set_example()
{
  // creating an unordered_set object
  unordered_set<int> us = {1, 5, 2, 3, 4};

  // checking size
  cout << "Size of us: " << us.size() << endl;

  // inserting data
  us.insert(7);

  // finding some key
  if (us.find(3) != us.end())
  {
    cout << "3 found!" << endl;
  }
  else
  {
    cout << "3 not found" << endl;
  }

  // traversing unordered_set using iterators
  cout << "us: ";
  for (auto i = us.begin(); i != us.end(); i++)
  {
    cout << *i << " ";
  }
  cout << endl;

  return 0;
}
```

---

### 1.5.2. Unordered Map

**Description**: Unordered associative container that stores key-value pairs. Implemented using hash tables for O(1) average access time.

#### 1.5.2.1. Common Methods

| Method     | Complexity | Description                                                                          |
| ---------- | ---------- | ------------------------------------------------------------------------------------ |
| `begin()`  | O(1)       | Returns an iterator to the first element                                             |
| `end()`    | O(1)       | Returns an iterator to the theoretical element that follows the last element         |
| `size()`   | O(1)       | Returns the number of elements                                                       |
| `empty()`  | O(1)       | Returns true if the unordered_map is empty, otherwise false                          |
| `find()`   | O(1) avg   | Returns the pointer to the given element if present, otherwise, a pointer to the end |
| `bucket()` | O(1)       | Returns the bucket number where the data is stored                                   |
| `insert()` | O(1) avg   | Insert an item in the container                                                      |
| `erase()`  | O(1) avg   | Removes an element from the container                                                |

#### 1.5.2.2. Example Usage

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int unordered_map_example()
{
  // creating unordered_map object
  unordered_map<int, string> umap;

  // inserting key value pairs
  umap[1] = "ONE";
  umap[2] = "TWO";
  umap[3] = "THREE";
  umap.insert({4, "FOUR"});

  // finding some key
  if (umap.find(12) != umap.end())
  {
    cout << "Key 12 Found!" << endl;
  }
  else
  {
    cout << "Key 12 Not Found!" << endl;
  }

  // traversing whole map at once using iterators
  cout << "umap:--" << endl;
  for (auto i = umap.begin(); i != umap.end(); i++)
  {
    cout << "Key:" << i->first
         << "\tValue: " << i->second << endl;
  }

  return 0;
}
```

---

## 1.6. Quick Reference Summary

### 1.6.1. Container Selection Guide

- **Vector**: Use when you need fast random access and mostly add/remove from the end
- **List**: Use when you need frequent insertions/deletions in the middle
- **Deque**: Use when you need to add/remove from both ends efficiently
- **Stack**: Use for LIFO operations (undo/redo, expression evaluation)
- **Queue**: Use for FIFO operations (breadth-first search, task scheduling)
- **Set**: Use when you need sorted unique elements with fast lookup
- **Map**: Use when you need sorted key-value pairs with fast lookup
- **Unordered Set**: Use when you need unique elements with fastest possible lookup (no ordering)
- **Unordered Map**: Use when you need key-value pairs with fastest possible lookup (no ordering)
