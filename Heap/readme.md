# Heap

A heap is a specialized tree-based data structure that follows the binary tree structure. There are broadly two types of heaps: Min Heap and Max Heap.

## Time Complexity of Various Operations

- **Insert**: O(log n)
- **Search**: O(N) (as heap is not optimized for search)
- **Find_Min/Max**: O(1)
- **Delete_Min/Max**: O(log n)

## When to Use a Heap

Use a heap when the focus is on inserting, finding, and deleting the minimum or maximum element.

## Heap Characteristics

- **Tree-based**: Heaps are tree-based data structures.
- **Complete Binary Tree**: Nodes are filled level-wise and from left to right.
- **Heap Property**: Each root node in all subtree is the maximum (in a Max Heap) or minimum (in a Min Heap) among all its children.

> **Note**: A heap could be binary or n-ary. There are also other types such as Fibonacci heaps and binomial heaps.

## Representation

A heap can be represented as an array:

- **Root**: i
- **Left Child**: 2\*i + 1
- **Right Child**: 2\*i + 2
- **Parent**: For an element at index i, the parent is at index (i - 1) // 2.

## Concepts

- **Size of Array Storing Tree**: The size of the array storing the tree is given by `2^(h+1) - 1` (maximum nodes in the entire tree) where `h` is the height of the tree.
- **Height of a Tree**: The height `h` of a tree is given by `h = floor(log2(n))` where `n` is the number of nodes.
- **Range of Internal Nodes**: The range of internal nodes is from `0` to `ceil(n/2) - 1`.
- **Range of Leaves**: The range of leaves is from `ceil(n/2)` to `n-1`.

  (Assuming 0-based indexing; if using 1-based indexing, add 1 to the indexes.)

## Algorithms

- ## **Heapify**

The process of rearranging the heap by comparing each parent with its children recursively is called heapify. Here, we will be implementing max_heap.

> **Note**: Heapify is applied at a node only if its left and right child subtree follow the heap property.

**Process**:

1. If the root is smaller than the left or right child, swap the root with the larger of the two children and call heapify on that child node.
2. Stop this process when reaching a leaf node or the parent is greater than both its children.

**Code**:

```cpp
    void heapify(ll i) {
        ll l = 2*i + 1;
        ll r = 2*i + 2;
        ll largest = i;

        if (l < n && tree[l] > tree[largest])
            largest = l;
        if (r < n && tree[r] > tree[largest])
            largest = r;
        if (largest != i) {
            swap(tree[largest], tree[i]);
            heapify(largest);
        }
    }
    // Time Complexity: O(log n) //Height of tree
    // Space Complexity: O(log n) //Height of tree
```

- ## **Build Heap**:

Now here we just need to call heapify in bottom-up order as we know that heapify could only be applied at a node if the left and right subtrees are heaps. So, leaving the leaf nodes, we just need to call heapify at all nodes in bottom-up order.

From [Concepts](#concepts), we know that the range of internal nodes is from 0 to `ceil(n/2) - 1`, so just run a loop in backward order from `ceil(n/2) - 1` to 0.

```cpp
    void build() {
        for (ll i = ceil(n / 2.0) - 1; i >= 0; i--) {
            heapify(i);
        }
    }
    //Time Complexity: O(n)
    //Space Complexity: O(log n) // Height of the tree
```

> **Note**: [Proof of time complexity why it is not O(n log n) but O(n)](https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/)

- ## **Extract Max**:

Store 0th index of the array as maximum element replace it with last element call heapify on root.

```cpp
    ll maxHeap() {
        if (n == 0) return -1 ll;
        ll mx = tree[0];
        tree[0] = tree[n - 1];
        n--;
        heapify(0);
        return mx;
    }
    //Time Complexity: O(log n)
    //Space Complexity: O(log n)
```

- ## **Increase Key**:

Increase the key at the given index then compare it to the parent if it becomes larger than parent swap continue it till the condition till i>0 and parent is less than node.

```cpp
    void increaseKey(ll i, ll key) {
        if (key < tree[i]) {
            decreaseKey(i, key);
            return;
        }
        tree[i] = key;
        while (i > 0 && tree[i / 2] < tree[i]) {
            swap(tree[i], tree[i / 2]);
            i /= 2;
        }
    }
    //Time Complexity: O(log n)
    //Space Complexity: O(1)
```

- ## **Decrease Key**:

Decrease the key at the given index then call heapify at that index.

```cpp
    void decreaseKey(ll i, ll key) {
        if (key > tree[i]) {
            increase(i, key);
            return;
        }
        tree[i] = key;
        heapify(i);
    }
    //Time Complexity: O(log n)
    //Space Complexity: O(log n)
```

- ## **Insert Key**:

Increase the size of tree array insert the key at last index then compare it to the parent if it becomes larger than parent swap continue it till the condition till i>0 and parent is less than node.

```cpp
    void insertElement(ll key) {
        n++;
        tree[n - 1] = key;
        ll i = n - 1;
        while (i > 0 && tree[(i - 1) / 2] <= tree[i]) {
            swap(tree[i], tree[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    //Time Complexity: O(log n)
    //Space Complexity: O(1)
```

- ## **Heapsort**:

In a max heap we know the root is the greatest element swap it with last index of tree then decrease the size of tree and call heapify at root.

```cpp
    vll heapsort() {
        build();
        ll n1 = n;
        for (ll i = (n1 - 1); i > 0; i--) {
            swap(tree[i], tree[0]);
            n--;
            heapify(0);
        }
        return tree;
    }
    //Time Complexity: O(nlog n)
    //Space Complexity: O(log n)
```

> **Note**: Operations like finding, deleting random elements or extracting minimum element from a max Heap takes O(n) time complexity since we have to perform linear search.

## Operations

- ### **Push**:
  Call insert key operation
- ### **Pop**:
  Call decrease key operation

## Practice Problems

- [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)
- [kth Largest Element](https://leetcode.com/problems/kth-largest-element-in-an-array/description/): Solve this using quickselect as well......
- [Top k most frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/)

> **Note:** Solve all problems using your own custom heap
