## Problem
LeetCode 2943 – Maximize Area of Square Hole in Grid

## Approach
- Sort the removed horizontal and vertical bars.
- Find the longest consecutive sequence of removed bars in both directions.
- The maximum possible square side length is `min(maxConsecutiveHorizontal, maxConsecutiveVertical) + 1`.
- Return the square of this side length as the area.

## Complexity
- Time: O(h log h + v log v), where `h` and `v` are the sizes of `hBars` and `vBars`
- Space: O(1)
