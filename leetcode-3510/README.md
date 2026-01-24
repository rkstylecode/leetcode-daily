# LeetCode 3510 — Minimum Pair Removal to Sort Array II

## Problem Statement
You are given an integer array `nums`. You may perform the following operation any number of times:

- Select the **adjacent pair with the minimum sum**.  
- If multiple such pairs exist, choose the **leftmost** one.
- Replace the selected pair with their sum.

Return the **minimum number of operations** required to make the array **non-decreasing**.

An array is non-decreasing if `nums[i] ≥ nums[i-1]` for all valid `i`.

---

## Approach
- Model the array as a **doubly linked list** using `prevIndex` and `nextIndex` arrays to maintain dynamic adjacency after merges.
- Maintain a `set` of pairs `{sum, index}` representing the sum of every adjacent pair, which allows retrieving the **minimum-sum adjacent pair** in `O(log n)` time.
- Track the number of **bad pairs** (`nums[i] > nums[i+1]`). The process stops once no bad pairs remain.
- In each operation:
  - Extract the adjacent pair with the minimum sum.
  - Merge the pair into a single value.
  - Update neighboring links and adjacent pair sums in the set.
  - Adjust the count of bad pairs locally around the merge point (constant-time updates).
- Repeat until the array becomes non-decreasing.

This ensures correctness while avoiding full rescans of the array after each merge.

---

## Time Complexity
- **O(n log n)**  
  Each merge involves `set` insertions/deletions, and there can be at most `n−1` merges.

## Space Complexity
- **O(n)**  
  Additional arrays for linked-list simulation and a set to store adjacent pair sums.
