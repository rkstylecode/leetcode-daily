# Champagne Tower (LeetCode 799)

## Problem Statement

You are given an integer `poured` representing the amount of champagne poured into the top glass of a champagne tower.

The tower is structured such that:

- The first row has 1 glass.
- The second row has 2 glasses.
- The third row has 3 glasses.
- And so on.

Each glass can hold **at most 1 unit** of champagne.

If a glass overflows, the excess amount is split equally between the two glasses immediately below it.

Given `query_row` and `query_glass`, return how full the specified glass is (value between 0 and 1).

---

## Approach

### Simulation using 2D DP

1. Create a 2D array `glass[100][100]` initialized to 0.
2. Set `glass[0][0] = poured`.
3. Iterate row by row:
   - For each glass in row `i-1`, check if it contains more than 1 unit.
   - If so:
     - Compute overflow = `glass[i-1][j] - 1`
     - Distribute `overflow / 2` to:
       - `glass[i][j]`
       - `glass[i][j+1]`
4. Stop early if no overflow occurs in a row.
5. Return `min(1, glass[query_row][query_glass])`.

### Key Idea

We simulate the overflow propagation level by level.
Each glass passes only the excess amount downward.
The final answer is capped at 1 because a glass cannot exceed its capacity.

---

## Time Complexity

We iterate through at most 100 rows, and for each row up to 100 glasses.

\[
\textbf{Time Complexity: } O(100 \times 100) = O(1)
\]

Since 100 is constant (problem constraint), this is constant time.

---

## Space Complexity

We use a 2D array of size 100 × 100.

\[
\textbf{Space Complexity: } O(100 \times 100) = O(1)
\]

Again constant space due to fixed constraints.
