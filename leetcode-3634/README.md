# LeetCode 3634 – Minimum Removals to Satisfy Condition

## Problem Statement
Given an integer array `nums` and an integer `k`, you can remove elements from the array.
After removals, the remaining array must satisfy the condition:

For the minimum element `x` in the remaining array, all elements `y` must satisfy  
`y ≤ k * x`.

Return the **minimum number of removals** required to satisfy this condition.

---

## Approach
1. **Sort** the array in non-decreasing order.
2. Fix an index `i` as the position of the **minimum element** in the remaining array.
3. For `nums[i]`, the maximum allowed value is `k * nums[i]`.
4. Use **binary search (`upper_bound`)** to find the first index where elements exceed `k * nums[i]`.
5. Elements to remove:
   - All elements **before `i`**
   - All elements **after the valid range**
6. Compute removals for each `i` and take the minimum.

This works because the array is sorted, allowing efficient range validation.

---

## Time Complexity
- Sorting: `O(n log n)`
- Loop with binary search: `O(n log n)`
- **Overall:** `O(n log n)`

---

## Space Complexity
- Sorting overhead: `O(1)` (ignoring input storage)
- **Overall:** `O(1)`
