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
- **Heap Property**: Each node is the maximum (in a Max Heap) or minimum (in a Min Heap) among all its children.

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
- **Range of Leaves**: The range of leaves is from `ceil(n/2)` to `n`.

  (Assuming 0-based indexing; if using 1-based indexing, add 1 to the indexes.)

## Algorithms

- **Heapify**:
- **Build Heap**:
- **Heapsort**:
