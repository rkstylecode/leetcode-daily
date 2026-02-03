# LeetCode 3637 – Check if Array is Trionic

## Problem
An array `nums` is called **trionic** if it can be divided into three **non-empty** consecutive parts such that:
1. The first part is **strictly increasing**
2. The second part is **strictly decreasing**
3. The third part is **strictly increasing**

Return `true` if the array is trionic, otherwise return `false`.

---

## Approach
- Traverse the array once using a pointer.
- First, move forward while elements are strictly increasing.
- Then, continue while elements are strictly decreasing.
- Finally, continue while elements are strictly increasing again.
- Ensure:
  - Each segment has at least one valid comparison (non-empty)
  - The entire array is consumed by these three phases

If all conditions are satisfied, return `true`; otherwise, return `false`.

---

## Time Complexity
**O(n)** — single pass through the array.

---

## Space Complexity
**O(1)** — constant extra space.
