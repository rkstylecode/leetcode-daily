# LeetCode 1984 — Minimum Difference Between Highest and Lowest of K Scores

## Problem Statement
You are given an integer array `nums` and an integer `k`.  
Choose any `k` elements from the array such that the **difference between the highest and lowest** selected elements is minimized.

Return this minimum possible difference.

---

## Approach
- Sort the array in **descending order**.
- After sorting, any group of `k` consecutive elements represents a valid selection.
- For each window of size `k`, compute the difference between the first element (maximum) and the last element (minimum).
- Track and return the minimum difference across all such windows.

Sorting ensures that the maximum and minimum of each group can be accessed in constant time.

---

## Time Complexity
- **O(n log n)** due to sorting.

## Space Complexity
- **O(1)** extra space (sorting in-place).
