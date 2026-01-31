# LeetCode 744 — Find Smallest Letter Greater Than Target

## Problem Statement
You are given a sorted array of characters `letters` and a character `target`.  
Return the smallest character in the array that is strictly greater than `target`.  
The letters wrap around, meaning if no character is greater than `target`, return the first character in the array.

## Approach
Use **binary search** on the sorted array:
- Initialize `ans` with `letters[0]` to handle the wrap-around case by default.
- Perform binary search:
  - If `letters[mid] > target`, update `ans` and search the left half.
  - Otherwise, search the right half.
- Return `ans`.

## Time Complexity
**O(log n)** — binary search on the array.

## Space Complexity
**O(1)** — constant extra space.
