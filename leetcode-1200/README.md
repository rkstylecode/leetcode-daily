# LeetCode 1200 – Minimum Absolute Difference

## Problem Statement
Given an array of **distinct integers** `arr`, find all pairs of elements with the **minimum absolute difference** of any two elements in the array.

Return a list of pairs `[a, b]` such that:
- `a < b`
- `|a - b|` is the minimum possible absolute difference
- Pairs are returned in **ascending order**

---

## Approach
1. **Sort the array** in ascending order.  
   - After sorting, the minimum absolute difference must occur between **adjacent elements**.
2. Traverse the array once to find the **minimum difference** between consecutive elements.
3. Traverse the array again and collect all adjacent pairs whose difference equals the minimum difference.
4. Return the collected pairs.

This avoids checking all possible pairs and keeps the solution efficient.

---

## Time Complexity
- Sorting: `O(n log n)`
- Two linear passes: `O(n)`
- **Overall:** `O(n log n)`

---

## Space Complexity
- Extra space for result: `O(n)`
- Sorting is done in-place
- **Overall:** `O(n)`
