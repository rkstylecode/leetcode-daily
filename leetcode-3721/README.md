# Longest Balanced Subarray

## Problem Statement

Given an integer array `nums`, find the length of the longest contiguous subarray such that:

* The number of even elements equals the number of odd elements.
* Each element inside the subarray is considered only once based on its latest occurrence (duplicates are handled by removing the previous contribution).

Return the maximum possible length of such a balanced subarray.

---

## Approach

* Treat even numbers as `+1` and odd numbers as `-1`.
* Maintain a segment tree with lazy propagation to:

  * Perform range updates.
  * Track minimum and maximum prefix values.
* For each index `i`:

  * Convert the value to `+1` or `-1`.
  * If the element was seen before, remove its previous contribution using a range update.
  * Apply the new contribution using another range update.
  * Query the segment tree to find the leftmost index where prefix sum becomes zero.
  * Update the maximum subarray length.
* Use a hash map to store the latest index of each element.

---

## Time Complexity

* Each index performs range updates and a query on the segment tree.
* Each operation takes `O(log n)`.
* Overall Time Complexity: **O(n log n)**.

---

## Space Complexity

* Segment tree arrays: `O(n)`.
* Hash map for tracking last occurrences: `O(n)`.
* Overall Space Complexity: **O(n)**.
