# Balance a Binary Search Tree (LeetCode 1382)

## Problem Statement
Given the root of a Binary Search Tree (BST), return a **balanced BST** with the same node values.  
A BST is considered balanced if for every node, the height difference between its left and right subtrees is at most 1.

---

## Approach
1. **Inorder Traversal**  
   Perform an inorder traversal of the BST to collect all nodes in a vector.  
   Since inorder traversal of a BST yields nodes in sorted order, this gives a sorted list of nodes.

2. **Rebuild Balanced BST**  
   Use divide-and-conquer on the sorted list:
   - Choose the middle element as the root.
   - Recursively build the left subtree from the left half.
   - Recursively build the right subtree from the right half.

   This guarantees the height difference between subtrees is minimized, producing a balanced BST.

---

## Time Complexity
- **O(n)**  
  - Inorder traversal visits each node once.
  - Rebuilding the BST also processes each node once.

---

## Space Complexity
- **O(n)**  
  - Extra space for storing nodes in a vector.
  - Recursive call stack in the worst case is O(log n) for a balanced tree.
