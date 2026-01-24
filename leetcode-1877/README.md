# LeetCode 1877 — Minimize Maximum Pair Sum in Array

## Problem Statement
You are given an integer array `nums` of even length.  
In one operation, you form `n / 2` pairs such that each element of the array belongs to exactly one pair.

The **pair sum** is the sum of the two elements in the pair.  
Return the **minimum possible value of the maximum pair sum** among all possible pairings.

---

## Approach
- Sort the array in ascending order.
- Use a two-pointer technique:
  - Pair the **smallest** element with the **largest** element.
  - This balancing minimizes the maximum pair sum.
- Track the maximum sum among all formed pairs.
- Return this value.

This greedy strategy works because pairing extremes distributes values evenly and prevents any single pair from having an unnecessarily large sum.

---

## Time Complexity
- **O(n log n)** due to sorting.

## Space Complexity
- **O(1)** extra space (sorting in-place).
