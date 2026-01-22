# LeetCode 3507 — Minimum Pair Removal

## Problem Statement
You are given an integer array `nums`.  
In one operation, you can choose any adjacent pair `(nums[i], nums[i+1])`, remove the pair, and replace it with their sum at the same position.

Your task is to determine the **minimum number of such operations** required to make the array **non-decreasing** (i.e., `nums[i] ≤ nums[i+1]` for all valid `i`).

Return the minimum number of operations.

---

## Approach
- Repeatedly check whether the array is already non-decreasing.
- If it is, stop.
- Otherwise:
  - Scan all adjacent pairs and compute their sums.
  - Select the pair with the **minimum sum**.
  - Replace that pair with their sum (merge the two elements).
  - Increment the operation count.
- Continue until the array becomes non-decreasing or its size becomes 1.

This greedy strategy works because merging the minimum-sum adjacent pair minimizes disruption and accelerates reaching a sorted state.

---

## Time Complexity
- **Worst-case:** `O(n²)`  
  Each merge is `O(n)` (due to scanning and erase), and up to `n` merges may occur.

## Space Complexity
- **O(1)** extra space  
  All operations are done in-place on the input array.
