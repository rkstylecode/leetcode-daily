# LeetCode 3650 – Minimum Cost to Reach Destination

## Problem Statement
You are given an integer `n` representing the number of nodes (labeled `0` to `n-1`) and a 2D array `edges`, where each edge is of the form `[u, v, w]`.

- Moving from node `u` to node `v` costs `w`
- Moving from node `v` to node `u` costs `2 * w`

Find the **minimum cost** to travel from node `0` to node `n-1`.  
If it is not possible, return `-1`.

---

## Approach
1. Build a **weighted adjacency list**:
   - Add edge `u → v` with cost `w`
   - Add edge `v → u` with cost `2w`
2. Use **Dijkstra’s algorithm** since all edge weights are positive.
3. Maintain a `cost` array where `cost[i]` stores the minimum cost to reach node `i`.
4. Use a **min-heap priority queue** to always process the node with the smallest current cost.
5. Relax edges and update costs whenever a cheaper path is found.
6. Return the cost to reach node `n-1`, or `-1` if unreachable.

---

## Time Complexity
- Building adjacency list: `O(E)`
- Dijkstra’s algorithm: `O((V + E) log V)`
- **Overall:** `O((V + E) log V)`

---

## Space Complexity
- Adjacency list: `O(V + E)`
- Cost array and priority queue: `O(V)`
- **Overall:** `O(V + E)`
