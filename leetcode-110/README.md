# LeetCode 110 — Balanced Binary Tree

## Problem Statement
Given a binary tree, determine if it is height-balanced.

A binary tree is **height-balanced** if, for every node, the absolute difference between the heights of its left and right subtrees is **at most 1**.

---

## Approach
Use **Depth-First Search (DFS)** to compute the height of each subtree.

- Traverse the tree bottom-up.
- For every node:
  - Recursively compute the height of the left and right subtrees.
  - Check if the height difference exceeds 1.
  - If it does, mark the tree as unbalanced.
- Early stopping is used: once an imbalance is detected, further computation is skipped.

This ensures each node is processed only once.

---

## Time Complexity
**O(n)**  
Each node in the tree is visited exactly once.

---

## Space Complexity
**O(h)**  
Due to recursion stack, where `h` is the height of the tree.  
Worst case (skewed tree): **O(n)**  
Best case (balanced tree): **O(log n)**
