# LeetCode 3315 — Minimum Bitwise Array

## Problem Statement

You are given an integer array `nums`. For each element `y = nums[i]`, find the **minimum non-negative integer** `x` such that:

```
x | (x + 1) = y
```

If no such `x` exists, store `-1` for that index.

Return the resulting array.

---

## Key Observations

1. The expression `x | (x + 1)` is **always odd**.

   * Therefore, if `y` is even, **no valid `x` exists**.

2. In binary form, `y` produced by `x | (x + 1)` looks like:

   ```
   ????111...111
   ```

   (one or more trailing `1`s)

3. To recover the minimum possible `x`, we must:

   * Find the **first zero bit** in `y` (from LSB towards MSB)
   * Flip the bit **just below it**

This guarantees the smallest valid `x`.

---

## Approach

For each element `y = nums[i]`:

1. Initialize the answer as `-1`.
2. If `y == 2`, skip it directly (no valid solution).
3. Iterate over bit positions `j` from `1` to `31`:

   * If the `j`-th bit is set, continue.
   * Otherwise:

     * Flip the `(j-1)`-th bit using XOR:

       ```cpp
       x = y ^ (1 << (j - 1));
       ```
     * Store `x` as the answer and break.

This finds the **minimum valid `x`** that satisfies the condition.

---

## Time Complexity

* For each element, we scan up to **32 bits**.

```
O(n × 32) ≈ O(n)
```

Where `n` is the size of the array.

---

## Space Complexity

* Output array of size `n`.
* No extra auxiliary space.

```
O(n)
```
