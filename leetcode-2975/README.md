## Problem
LeetCode 2975 – Maximum Square Area by Removing Fences From a Field

## Approach
- Add the boundary fences (1 and `m` / `n`) to the horizontal and vertical fence lists.
- Compute all possible distances between pairs of horizontal fences and store them in a set.
- For each pair of vertical fences, check if the same distance exists in the horizontal set.
- Track the maximum common distance, which represents the side length of the largest square.

## Complexity
- Time: O(h² + v²), where `h` and `v` are the number of horizontal and vertical fences
- Space: O(h²)
