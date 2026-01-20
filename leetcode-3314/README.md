# LeetCode 3314 — Minimum Bitwise Array

## Problem Statement

You are given an integer array `nums`. For each element `x` in the array, find the **minimum non-negative integer** `y` such that:

```
y | (y + 1) == x
```

If no such `y` exists, replace the element with `-1`.

Return the modified array after processing all elements.

---

## Key Observation

For a number `y`, the expression `y | (y + 1)` turns **all trailing 1s of `y` into 1s** and also sets the next higher bit to 1.

So, to reverse this process for a given `x`:

* We want to **unset the lowest set bit** of `x` that can be flipped such that `y | (y + 1)` reconstructs `x`.
* The best (minimum) `y` is obtained by subtracting the **lowest power of two corresponding to a trailing 1** in `x`.
* If `x` has no zero bit after a sequence of trailing 1s, no valid `y` exists.

---

## Approach

For each element `x` in `nums`:

1. Initialize:

   * `res = -1` (default answer if no valid `y` exists)
   * `d = 1` (represents powers of two)

2. While the bitwise AND `(x & d)` is non-zero:

   * This means the current bit is set.
   * Try removing this bit: `res = x - d`
   * Move to the next bit by left-shifting `d`

3. Once a zero bit is found, stop.

4. Replace `x` with `res`.

This guarantees the smallest possible `y` because we remove the **lowest contributing bit first**.

---

## Time Complexity

* For each number, we scan its trailing set bits.
* Each number takes **O(log x)** time in the worst case.

**Overall:**

```
O(n log M)
```

Where:

* `n` = size of `nums`
* `M` = maximum value in `nums`

---

## Space Complexity

* No extra space used apart from variables.

```
O(1)
```

---

## Final Notes

* This solution is optimal and avoids brute-force checking of all candidates.
* Direct bit manipulation is the key insight—anything else will TLE on large inputs.
