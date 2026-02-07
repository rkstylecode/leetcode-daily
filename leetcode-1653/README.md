# LeetCode 1653 – Minimum Deletions to Make String Balanced

## Problem Statement
You are given a string `s` consisting only of characters `'a'` and `'b'`.
A string is considered **balanced** if there is no index pair `(i, j)` such that  
`i < j`, `s[i] = 'b'`, and `s[j] = 'a'`.

Return the **minimum number of deletions** required to make the string balanced.

---

## Approach
1. Build prefix arrays:
   - `aCount[i]`: number of `'a'` characters from index `0` to `i`
   - `bCount[i]`: number of `'b'` characters from index `0` to `i`
2. Consider every index `i` as a split point:
   - All `'b'` characters **before** `i` must be deleted
   - All `'a'` characters **after** `i` must be deleted
3. Deletions required at index `i`:
4. Compute this for all indices and take the minimum.

---

## Time Complexity
- Prefix computation: `O(n)`
- Split evaluation: `O(n)`
- **Overall:** `O(n)`

---

## Space Complexity
- Two prefix arrays of size `n`
- **Overall:** `O(n)`
