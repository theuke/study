# 1. Embedded Development Notes

## 1.1. Table of Contents

- [1. Embedded Development Notes](#1-embedded-development-notes)
  - [1.1. Table of Contents](#11-table-of-contents)
  - [1.2. Number Systems](#12-number-systems)
    - [1.2.1. Binary](#121-binary)
    - [1.2.2. Hexadecimal](#122-hexadecimal)
    - [1.2.3. Two's Complement](#123-twos-complement)
  - [1.3. Memory Concepts](#13-memory-concepts)
    - [1.3.1. Basic Memory Concepts](#131-basic-memory-concepts)
      - [1.3.1.1. Machine Word](#1311-machine-word)
    - [1.3.2. Endianness](#132-endianness)
      - [1.3.2.1. Little Endian vs Big Endian](#1321-little-endian-vs-big-endian)
    - [1.3.3. Memory Layout](#133-memory-layout)
    - [1.3.4. Key Memory-Related Keywords](#134-key-memory-related-keywords)
  - [1.4. Operating System Concepts](#14-operating-system-concepts)
    - [1.4.1. Scheduler](#141-scheduler)
    - [1.4.2. Synchronization Primitives](#142-synchronization-primitives)
      - [1.4.2.1. Mutex](#1421-mutex)
      - [1.4.2.2. Semaphore](#1422-semaphore)
        - [1.4.2.2.1. Operations](#14221-operations)
        - [1.4.2.2.2. Initialization](#14222-initialization)
        - [1.4.2.2.3. Types of Semaphores](#14223-types-of-semaphores)
          - [1.4.2.2.3.1. Binary Semaphore](#142231-binary-semaphore)
          - [1.4.2.2.3.2. Counting Semaphore](#142232-counting-semaphore)
        - [1.4.2.2.4. Classic Problems](#14224-classic-problems)
      - [1.4.2.3. Barrier Synchronization](#1423-barrier-synchronization)
    - [1.4.3. Atomic Operations](#143-atomic-operations)
      - [1.4.3.1. Spinlock](#1431-spinlock)
    - [1.4.4. Memory Management](#144-memory-management)
      - [1.4.4.1. How `malloc()` and `free()` Work](#1441-how-malloc-and-free-work)
        - [1.4.4.1.1. `malloc()`](#14411-malloc)
        - [1.4.4.1.2. `free()`](#14412-free)
        - [1.4.4.1.3. Challenges](#14413-challenges)
    - [1.4.5. Virtual Memory](#145-virtual-memory)
    - [1.4.6. Thread Safety](#146-thread-safety)
      - [1.4.6.1. Thread-Safe Methods](#1461-thread-safe-methods)
      - [1.4.6.2. Re-entrant Methods](#1462-re-entrant-methods)
    - [1.4.7. Interrupts](#147-interrupts)
      - [1.4.7.1. How Do Interrupts Work?](#1471-how-do-interrupts-work)
  - [1.5. Algorithm Problems](#15-algorithm-problems)
    - [1.5.1. Matrix Chain Multiplication](#151-matrix-chain-multiplication)
    - [1.5.2. 0/1 Knapsack Problem](#152-01-knapsack-problem)
      - [1.5.2.1. Dynamic Programming Approach](#1521-dynamic-programming-approach)
      - [1.5.2.2. Complete Memo Table](#1522-complete-memo-table)
      - [1.5.2.3. Greedy Solution](#1523-greedy-solution)
      - [1.5.2.4. Memoization Strategy](#1524-memoization-strategy)

---

## 1.2. Number Systems

### 1.2.1. Binary

- TODO: Add notes

### 1.2.2. Hexadecimal

- TODO: Add notes

### 1.2.3. Two's Complement

- TODO: Add notes

---

## 1.3. Memory Concepts

### 1.3.1. Basic Memory Concepts

#### 1.3.1.1. Machine Word

- Usually 32 bits (4 bytes) in size
- Defines the memory range
- Example: A 32-bit machine can have addresses from 0 to 2³²-1 = 4,294,967,295
  - Total addressable space: 4,294,967,296 bytes (4 GB)

### 1.3.2. Endianness

#### 1.3.2.1. Little Endian vs Big Endian

```txt
Hex:     0A   0B   0C   0D
Binary:  00001010 00001011 00001100 00001101

Memory Address:  0    1    2    3
Little Endian:  0D   0C   0B   0A
Big Endian:     0A   0B   0C   0D
```

**Key Points:**

- **Little endian**: Stores the least significant byte at the lowest address
- **Big endian**: Stores the most significant byte at the lowest address
- Endianness refers to byte ordering only; bit ordering within bytes remains the same

### 1.3.3. Memory Layout

Memory is organized from low address to high address:

1. **Text Segment** - Instructions, strings, and compile-time constants
2. **Initialized Data** - Global and static variables with initial values
3. **Uninitialized Data (BSS)** - Global and static variables without initial values
4. **Heap** - Dynamically allocated memory (grows upward)
5. **Stack** - Function calls, local variables (grows downward)

> Note: The stack grows from high to low addresses so that overflow would spill into the heap

### 1.3.4. Key Memory-Related Keywords

- `static` - Variables persist across function calls, limited scope
- `volatile` - Prevents compiler optimization, value may change unexpectedly
- `const` - Read-only, prevents modification

---

## 1.4. Operating System Concepts

### 1.4.1. Scheduler

**Questions to explore:**

- What are the types of schedulers?

### 1.4.2. Synchronization Primitives

#### 1.4.2.1. Mutex

- **Purpose**: Protect a resource from concurrent access
- **Operations**: `lock()` and `unlock()`
- Ensures mutual exclusion in critical sections

#### 1.4.2.2. Semaphore

**Purpose**: Used for flow control and resource counting

##### 1.4.2.2.1. Operations

**`sem_wait()` (Decrement/Lock)**

- If semaphore value > 0: Immediately returns and decrements value by 1
- If semaphore value = 0: Blocks the calling thread until `sem_post()` is called

**`sem_post()` (Increment/Unlock)**

- Increments the semaphore value by 1
- If threads are waiting, one is unblocked

##### 1.4.2.2.2. Initialization

- Must initialize before use
- Must destroy when done

##### 1.4.2.2.3. Types of Semaphores

###### 1.4.2.2.3.1. Binary Semaphore

- Can be used to implement a mutex
  - Initialize to 1
  - Use `wait()` before and `post()` after critical section
- Can be used as a signaling mechanism between threads
  - Example: Thread 2 waits for Thread 1 to reach a checkpoint
  - Initialize to 0
  - Thread 1 calls `post()` when ready
  - Thread 2 calls `wait()` before dependent work

###### 1.4.2.2.3.2. Counting Semaphore

- Can have values greater than 1
- Controls access to multiple instances of a resource
- Coordinates a specific number of threads/processes
- Initialized with a specific count
- Value decrements on each acquisition
- Blocks when value reaches zero
- Useful for limiting concurrent accesses or tracking task completion

##### 1.4.2.2.4. Classic Problems

- **Producer-Consumer Problem**
- **Single Writer, Multiple Reader Problem**
  - Can also be solved using mutexes and condition variables

#### 1.4.2.3. Barrier Synchronization

- TODO: Add details

### 1.4.3. Atomic Operations

#### 1.4.3.1. Spinlock

- TODO: Add details

### 1.4.4. Memory Management

#### 1.4.4.1. How `malloc()` and `free()` Work

##### 1.4.4.1.1. `malloc()`

- Returns an address from a large memory pool (typically an array)
- Ensures no overlap with previously allocated memory
- Tracks allocations to prevent double allocation

##### 1.4.4.1.2. `free()`

- Marks the memory chunk as available
- Implementation uses a lookup table to track free/allocated blocks
- Does not actually clear or reset the memory

##### 1.4.4.1.3. Challenges

- **Data fragmentation** is the biggest problem with dynamic allocation

### 1.4.5. Virtual Memory

- TODO: Add details

### 1.4.6. Thread Safety

#### 1.4.6.1. Thread-Safe Methods

- TODO: What makes a method thread safe?

#### 1.4.6.2. Re-entrant Methods

- TODO: What makes a method re-entrant?

### 1.4.7. Interrupts

#### 1.4.7.1. How Do Interrupts Work?

- TODO: Add details

---

## 1.5. Algorithm Problems

### 1.5.1. Matrix Chain Multiplication

**Problem**: Find the order of matrix chain multiplication to minimize total operations.

Given matrices:

```txt
    0         1         2         3
(5 x 4) * (4 x 6) * (6 x 2) * (2 x 7)
```

**Dynamic Programming Table**:

```txt
    0               1               2               3
------------------------------------------------------------------
0   x               5x6, 120        5x2, 88         5x7, 158
                    [0,0]x[1,1]     [0,0]x[1,2]     [0,0]x[1,3]
                                    [0,1]x[2,2]     [0,1]x[2,3]
                                                    [0,2]x[3,3]

1                   x               4x2, 48         4x7, 104
                                    [1,1]x[2,2]     [1,1]x[2,3]
                                                    [1,2]x[3,3]

2                                   x               6x7, 84
                                                    [2,2]x[3,3]

3                                                   x
```

**Recursive Solution**:

```c
int min_multiplications(int A[], int low, int high) {
    int n = high - low;
    if (n > 1) {
        int lowest = MAX_INT;
        for (int i = low; i < high; ++i) {
            int numSteps = min_multiplications(A, low, i) *
                          min_multiplications(A, i + 1, high);
            lowest = (numSteps < lowest) ? numSteps : lowest;
        }
        return lowest;
    } else {
        // Base case
        return A[low][0] * A[low][1] * A[high][1];
    }
}

// Call with: min_multiplications(A, 0, n - 1)
```

---

### 1.5.2. 0/1 Knapsack Problem

**Problem**: Given an array of weight/profit pairs and a maximum knapsack capacity, choose which items to include (each item can be chosen only once). Return a boolean array indicating which items are included.

**Example**:

```txt
n: 4 items
m: 8 (max capacity)

Idx:  0   1   2   3
W:    1   2   5   6
P:    2   3   4   5
```

#### 1.5.2.1. Dynamic Programming Approach

**Iterative Exploration of Combinations**:

**Initial (Single Items)**:

```txt
0   1   2   3
----------------------------
1   0   0   0 : W = 1, P = 2
0   1   0   0 : W = 2, P = 3
0   0   1   0 : W = 5, P = 4
0   0   0   1 : W = 6, P = 5
```

**Pairs**:

```txt
0   1   2   3
----------------------------
1   1   0   0 : W = 3, P = 5
1   0   1   0 : W = 6, P = 6
1   0   0   1 : W = 7, P = 7
0   1   1   0 : W = 7, P = 7
0   1   0   1 : W = 8, P = 8  ← Valid, best so far
0   0   1   1 : W = 11, P = 9 (exceeds capacity)
```

**Triples**:

```txt
0   1   2   3
----------------------------
1   1   1   0 : W = 8, P = 9  ← Valid, new best
1   1   0   1 : W = 9, P = 10 (exceeds capacity)
1   0   1   1 : W = 12, P = 11 (exceeds capacity)
0   1   1   1 : W = 13, P = 12 (exceeds capacity)
```

**All Items**:

```txt
1   1   1   1 : W = 14, P = 14 (exceeds capacity)
```

**Best Solution**: `[1, 1, 1, 0]` → Items 0, 1, 2 with W = 8, P = 9

#### 1.5.2.2. Complete Memo Table

```txt
0   0   0   0 : W = 0,  P = 0
1   0   0   0 : W = 1,  P = 2
0   1   0   0 : W = 2,  P = 3
0   0   1   0 : W = 5,  P = 4
0   0   0   1 : W = 6,  P = 5
1   1   0   0 : W = 3,  P = 5
1   0   1   0 : W = 6,  P = 6
1   0   0   1 : W = 7,  P = 7
0   1   1   0 : W = 7,  P = 7
0   1   0   1 : W = 8,  P = 8
0   0   1   1 : W = 11, P = 9
1   1   1   0 : W = 8,  P = 9
1   1   0   1 : W = 9,  P = 10
1   0   1   1 : W = 12, P = 11
0   1   1   1 : W = 13, P = 12
1   1   1   1 : W = 14, P = 14
```

#### 1.5.2.3. Greedy Solution

- Order objects by profitability (profit/weight ratio)
- Select items in order until capacity is reached
- **Note**: This doesn't always give the optimal solution for 0/1 knapsack

#### 1.5.2.4. Memoization Strategy

- Memoize explored sets/combinations
- Represent sets as boolean arrays (item included/excluded)
- Avoid recalculating the same combination multiple times
