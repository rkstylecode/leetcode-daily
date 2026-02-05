# LeetCode 3379 — Construct Transformed Array

## Problem Statement
You are given an integer array `nums` of size `n`.  
Create a new array `result` of the same size such that for each index `i`:

- If `nums[i] == 0`, then `result[i] = 0`.
- Otherwise, move `nums[i]` steps forward (if positive) or backward (if negative) from index `i`, wrapping around the array cyclically, and set:

The array is circular, so indices wrap using modulo `n`.

Return the transformed array.

---

## Approach
- Let `n` be the size of the array.
- Initialize a `result` array of size `n` with default values.
- Iterate through each index `i`:
- If `nums[i] == 0`, skip it (default `0` stays).
- Otherwise:
  - Compute the new index using safe modulo to handle negatives:
    ```
    newIdx = ((i + nums[i]) % n + n) % n
    ```
  - Assign `result[i] = nums[newIdx]`.
- Return the `result` array.

This approach directly simulates the transformation in a single pass without extra overhead.

---

## Time Complexity
- **O(n)** — Single traversal of the array.

## Space Complexity
- **O(n)** — Extra array used to store the result.
