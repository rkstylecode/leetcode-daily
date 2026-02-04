# LeetCode 3640 – Maximum Sum Trionic Subarray

## Problem Statement
You are given an integer array `nums`.  
A **trionic subarray** is a contiguous subarray that consists of **three consecutive phases**:

1. A **strictly increasing** phase  
2. Followed by a **strictly decreasing** phase  
3. Followed by a **strictly increasing** phase  

Each phase must be **non-empty**.

Return the **maximum possible sum** of such a trionic subarray.  
If no valid trionic subarray exists, the result is considered invalid.

---

## Approach
- Use **Dynamic Programming with recursion + memoization**.
- Define a DP state `dp[idx][phase]`:
  - `idx` → current index in the array
  - `phase`:
    - `0` → not started
    - `1` → first increasing phase
    - `2` → decreasing phase
    - `3` → final increasing phase
- At each index:
  - Either **skip** the element (only allowed before starting, i.e., phase `0`)
  - Or **take** the element and transition phases based on the comparison between
    `nums[idx]` and `nums[idx+1]`
- Only sequences that end exactly in **phase 3** are considered valid.
- Invalid paths return a very small negative value to exclude them from the maximum.

This ensures:
- Contiguity of the subarray
- Strict monotonicity in each phase
- All three phases are present

---

## Time Complexity
**O(n × 4) = O(n)**  
Each state `(idx, phase)` is computed once.

---

## Space Complexity
**O(n × 4) = O(n)**  
For the DP table and recursion stack.
