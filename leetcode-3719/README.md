# Longest Balanced Subarray

## Problem Statement

Given an integer array `nums`, find the length of the longest contiguous subarray such that the number of **distinct even elements** is equal to the number of **distinct odd elements** within that subarray.

---

## Approach

The solution uses a brute-force strategy with two nested loops to examine all possible subarrays.

* Fix a starting index `i`.
* For each ending index `j ≥ i`, maintain:

  * an `unordered_set` for distinct even numbers
  * an `unordered_set` for distinct odd numbers
* Insert the current element into the appropriate set based on its parity.
* At each step, compare the sizes of the two sets.
* If the sizes are equal, update the maximum subarray length.

This ensures that only subarrays with an equal count of **distinct** even and odd values are considered balanced.

---

## Time Complexity

* **O(n²)** in the average case, due to checking all subarrays.
* Insertions into `unordered_set` are **O(1)** on average.

---

## Space Complexity

* **O(n)** in the worst case for storing distinct elements in the sets.
