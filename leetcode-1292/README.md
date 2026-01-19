# LeetCode 1292: Maximum Side Length of a Square with Sum ≤ Threshold

## Problem Statement

You are given an `m × n` matrix `mat` consisting of non-negative integers and an integer `threshold`.

Your task is to find the **maximum possible side length** of a **square submatrix** such that the **sum of all its elements is less than or equal to ****`threshold`**.

If no such square exists, return `0`.

---

## Approach

This solution combines **prefix sums** with **binary search** to efficiently determine the largest valid square size.

### 1. Row-wise Prefix Sum

We first compute a **row-wise prefix sum matrix** `rowPrefSum`, where:

```
rowPrefSum[i][j] = mat[i][0] + mat[i][1] + ... + mat[i][j]
```

This allows us to compute the sum of any horizontal segment in **O(1)** time.

---

### 2. Checking Validity of a Square (isValid)

For a given side length `k`, we check whether **any ****`k × k`**** square** has sum ≤ `threshold`.

Steps:

* Iterate over all possible top-left corners `(i, j)` of a `k × k` square.
* For each square:

  * Compute its sum by accumulating row-wise segment sums using the prefix array.
* If **any square satisfies the condition**, return `true`.

This check runs in:

```
O((m − k + 1) × (n − k + 1) × k)
```

---

### 3. Binary Search on Side Length

Since:

* Smaller squares are always easier to satisfy than larger ones
* The answer is **monotonic**

We apply **binary search** on the side length:

* Search space: `1` to `min(m, n)`
* If a square of size `mid` is valid → try larger sizes
* Otherwise → try smaller sizes

---

## Final Algorithm

1. Build row-wise prefix sum matrix
2. Binary search on square side length
3. For each mid, validate using prefix sums
4. Return the maximum valid side length

---

## Time Complexity

* Prefix sum construction: `O(m × n)`
* Binary search iterations: `O(log(min(m, n)))`
* Validity check per iteration: `O(m × n × k)` (worst case)

### Overall Time Complexity:

```
O(m × n × log(min(m, n)))
```

---

## Space Complexity

* Prefix sum matrix: `O(m × n)`

### Overall Space Complexity:

```
O(m × n)
```

---

## Notes

* This solution is efficient enough for the given constraints
* Can be further optimized using a **2D prefix sum** to reduce validity check to `O(1)` per square

---
