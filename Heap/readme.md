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
