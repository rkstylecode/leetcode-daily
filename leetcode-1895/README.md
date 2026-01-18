# LeetCode 1895 – Largest Magic Square

## Problem Statement

You are given a 2D integer grid.  
A **magic square** is a square subgrid where:

- The sum of every **row** is equal  
- The sum of every **column** is equal  
- The **main diagonal** sum is equal  
- The **anti-diagonal** sum is equal  

Return the **size of the largest magic square** in the grid.

**Note:** A `1 × 1` square is always considered magic.

---

## Approach

1. **Prefix Sum Preprocessing**
   - Compute row-wise prefix sums to get any row sum in O(1)
   - Compute column-wise prefix sums to get any column sum in O(1)

2. **Brute-force Square Expansion**
   - For each cell (i, j), treat it as the top-left corner of a square
   - Try all possible square sizes that fit within the grid

3. **Validation**
   - For each square:
     - Check all row sums using row prefix sums
     - Check all column sums using column prefix sums
     - Compute and check the main diagonal sum
     - Compute and check the anti-diagonal sum
   - If all sums match, update the maximum square size

---

## Time Complexity

O(m × n × min(m, n) × min(m, n))

- m × n → choosing the top-left corner  
- min(m, n) → number of possible square sizes  
- min(m, n) → validation of rows, columns, and diagonals  

---

## Space Complexity

O(m × n)

- Used for row and column prefix sum arrays
