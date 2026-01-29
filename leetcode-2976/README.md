# LeetCode 2976 — Minimum Cost to Convert String I

## Problem Statement
You are given two strings `source` and `target` of equal length, along with three arrays:  
`original`, `changed`, and `cost`, where each index represents a possible character transformation  
`original[i] -> changed[i]` with cost `cost[i]`.

Each character can be transformed multiple times through intermediate characters.  
Return the **minimum total cost** to convert `source` into `target`.  
If it is impossible, return `-1`.

---

## Approach
- Model the problem as a **directed weighted graph** of 26 lowercase letters.
- Build a `26 x 26` cost matrix where `minCost[u][v]` represents the minimum cost to convert `u` to `v`.
- Initialize the matrix with infinity and take the **minimum cost** for duplicate transformations.
- Apply **Floyd–Warshall algorithm** to compute all-pairs shortest paths.
- For each index `i`, add the cost of converting `source[i]` to `target[i]`.
- If any conversion is unreachable, return `-1`.

---

## Time Complexity
- Floyd–Warshall: `O(26³)`  
- Final traversal: `O(n)`  
- **Overall:** `O(n)`

---

## Space Complexity
- Cost matrix: `O(26²)`  
- **Overall:** `O(1)` (constant space)
