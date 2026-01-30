# LeetCode 2977 – Minimum Cost to Convert String II

## Problem Statement
You are given two strings `source` and `target` of equal length, and three arrays `original`, `changed`, and `cost`.

Each `original[i]` can be converted to `changed[i]` at cost `cost[i]`.  
You may apply conversions on **substrings** of `source`.

Return the **minimum total cost** to convert `source` into `target`.  
If it is impossible, return `-1`.

---

## Approach

### Graph Modeling
- Treat each string in `original` and `changed` as a **node**
- Each conversion rule forms a **directed weighted edge**
- Use an adjacency list to represent the graph

### Dijkstra with Memoization
- For a given `(sourceSubstring → targetSubstring)` pair, compute the shortest conversion cost using **Dijkstra**
- Cache results in a 2D map to avoid recomputation

### Dynamic Programming
- Define `dp[i]` = minimum cost to convert `source[i:]` → `target[i:]`
- Transitions:
  - If `source[i] == target[i]`, move to `i+1` with no cost
  - Try all valid substring lengths:
    - Convert `source[i:i+len]` → `target[i:i+len]`
    - Add shortest conversion cost + `dp[i+len]`
- Use memoization to ensure linear DP states

---

## Time Complexity

Let:
- `N` = length of `source`
- `K` = number of distinct strings in conversion rules
- `E` = number of conversion rules
- `L` = number of distinct substring lengths

### Dijkstra
- Each `(start, end)` pair is computed **once**
- Cost per run: `O(E log K)`

### Time Complexity
- O(N × L × E log K) (worst case)


### Space Complexity
- Graph storage: `O(E)`
- DP array: `O(N)`
- Memoized shortest paths: `O(K²)` (only for queried pairs)

