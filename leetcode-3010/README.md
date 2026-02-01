# LeetCode 3010 – Minimum Cost

## Problem Statement

You are given an integer array `nums` of length `n`.

You need to choose **three indices**:

* The first index must be `0`
* The other two indices must be different and greater than `0`

The **cost** is defined as the sum of the elements at these three indices.

Return the **minimum possible cost**.

---

## Approach

* The first element `nums[0]` is **mandatory**, so it is always included in the sum.
* We need to choose **two more distinct elements** from the remaining array (`nums[1 ... n-1]`).
* The brute-force approach checks all possible pairs from indices `1` to `n-1`.
* For every valid pair, compute:

  ```
  nums[0] + nums[i] + nums[j]
  ```
* Track the minimum sum encountered.

This works because the constraints are small enough to allow checking all combinations.

---

## Time Complexity

* **O(n²)**

  * Two nested loops are used to try all pairs after index `0`.

---

## Space Complexity

* **O(1)**

  * Only a few variables are used; no extra data structures.
