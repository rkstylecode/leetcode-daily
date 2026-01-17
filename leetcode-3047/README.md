# LeetCode 3047 – Largest Square Area Inside Two Rectangles

## Problem Statement
You are given two arrays:
- `bottomLeft[i] = [x1, y1]`
- `topRight[i] = [x2, y2]`

Each pair represents an axis-aligned rectangle.

The task is to find the **largest possible square area** that can be formed inside the **overlapping region of any two rectangles**.  
If no two rectangles overlap, return `0`.

---

## Approach
- Consider every pair of rectangles
- For each pair:
  - Calculate overlap along the x-axis
  - Calculate overlap along the y-axis
  - The maximum square that fits inside the overlap has side length:
    ```
    min(overlapWidth, overlapHeight)
    ```
- Track the maximum square area found

This brute-force approach is acceptable due to small constraints.

---

## Complexity Analysis
- **Time Complexity:** `O(n²)`  
  All pairs of rectangles are checked.

- **Space Complexity:** `O(1)`  
  Only constant extra variables are used.

---

## Notes
- If there is no overlap between two rectangles, they contribute nothing.
- Square area is calculated using 64-bit integers to avoid overflow.

---

## LeetCode Link
https://leetcode.com/problems/find-the-largest-square-area-inside-two-rectangles/
