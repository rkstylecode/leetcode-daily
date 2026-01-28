# Minimum Cost Path in Grid with K Operations

## Problem Statement
You are given an `m x n` grid where each cell contains a non-negative cost.  
You start at the top-left cell `(0, 0)` and want to reach the bottom-right cell `(m-1, n-1)`.

From any cell, you may move **only right or down**.  
The cost of a move is the value of the cell you move into.

Additionally, you are allowed to perform **at most `k` operations**.  
Each operation allows you to **reset the cost of all cells having the same value to the minimum cost achieved so far**.

Return the minimum possible cost to reach the destination.

---

## Approach
1. **Sort grid cells by their values** so that cells with the same value can be processed together.
2. Maintain a 2D array `costs[i][j]` representing the minimum cost to reach the destination from cell `(i, j)`.
3. Repeat the following process `k + 1` times:
   - Traverse the sorted cells and propagate the **minimum cost among all cells with the same value**.
   - Perform a bottom-up dynamic programming pass from bottom-right to top-left:
     - For each cell, update its cost using the minimum of:
       - Moving right
       - Moving down
4. After all operations, the answer is stored in `costs[0][0]`.

This approach correctly models the effect of the `k` operations while maintaining valid grid movement constraints.

---

## Time Complexity
- Sorting cells: `O(mn log(mn))`
- DP transitions for each operation: `O(mn)`
- Total: **`O(k · m · n + m · n log(mn))`**

---

## Space Complexity
- Cost grid: `O(mn)`
- Auxiliary storage for points: `O(mn)`
- Total: **`O(mn)`**
