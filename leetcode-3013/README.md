# LeetCode 3013 — Divide an Array Into Subarrays With Minimum Cost II

## Problem
You are given an integer array `nums`, and two integers `k` and `dist`.

You must choose `k` elements such that:
- The first chosen element is always `nums[0]`
- For the remaining `k - 1` elements, the distance between consecutive chosen indices is at most `dist`
- The total cost is the sum of the chosen elements

Return the **minimum possible cost**.

---

## Approach
- `nums[0]` is mandatory, so we only optimize the remaining `k - 1` elements.
- Use a **sliding window** over indices `[i - dist, i]` to enforce the distance constraint.
- Maintain two ordered sets:
  - `main`: holds the smallest `k - 1` elements in the current window
  - `extra`: holds the remaining elements
- Maintain a running sum of elements in `main`.
- At each step:
  - Insert the new element into `main`
  - If `main` exceeds size `k - 1`, move the largest element to `extra`
  - Update the minimum sum
  - Remove the element that goes out of the window and rebalance if needed
- Final answer is `nums[0] + minimum sum of (k - 1) elements`.

This ensures we always keep the optimal `k - 1` smallest values within a valid distance window.

---

## Time Complexity
- **O(n log n)**  
  Each insertion, deletion, and rebalancing in a `set` takes `O(log n)` and is done once per index.

---

## Space Complexity
- **O(n)**  
  Two sets are used to store elements within the sliding window.
# LeetCode 3013 — Divide an Array Into Subarrays With Minimum Cost II

## Problem
You are given an integer array `nums`, and two integers `k` and `dist`.

You must choose `k` elements such that:
- The first chosen element is always `nums[0]`
- For the remaining `k - 1` elements, the distance between consecutive chosen indices is at most `dist`
- The total cost is the sum of the chosen elements

Return the **minimum possible cost**.

---

## Approach
- `nums[0]` is mandatory, so we only optimize the remaining `k - 1` elements.
- Use a **sliding window** over indices `[i - dist, i]` to enforce the distance constraint.
- Maintain two ordered sets:
  - `main`: holds the smallest `k - 1` elements in the current window
  - `extra`: holds the remaining elements
- Maintain a running sum of elements in `main`.
- At each step:
  - Insert the new element into `main`
  - If `main` exceeds size `k - 1`, move the largest element to `extra`
  - Update the minimum sum
  - Remove the element that goes out of the window and rebalance if needed
- Final answer is `nums[0] + minimum sum of (k - 1) elements`.

This ensures we always keep the optimal `k - 1` smallest values within a valid distance window.

---

## Time Complexity
- **O(n log n)**  
  Each insertion, deletion, and rebalancing in a `set` takes `O(log n)` and is done once per index.

---

## Space Complexity
- **O(n)**  
  Two sets are used to store elements within the sliding window.
