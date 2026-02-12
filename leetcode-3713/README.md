# Longest Balanced Substring

## Problem Statement

Given a string `s`, find the length of the longest contiguous substring such that all characters present in the substring appear with the same frequency.

Return the maximum length of such a balanced substring.

---

## Approach

* Use a brute-force approach by fixing a starting index `i`.
* Maintain a frequency map for characters while expanding the ending index `j`.
* For every substring `s[i...j]`:

  * Update the frequency of the current character.
  * Check whether all characters in the current substring have the same frequency.
  * If they do, update the maximum length.
* Continue this process for all possible starting indices.

---

## Time Complexity

* Outer loop runs `n` times.
* Inner loop runs up to `n` times.
* For each substring, checking frequencies takes up to `O(k)` where `k` is the number of distinct characters (at most 26 for lowercase letters).
* Overall Time Complexity: **O(n^2 * k)**, which simplifies to **O(n^2)**.

---

## Space Complexity

* Frequency map stores at most 26 characters.
* Space Complexity: **O(1)** (since alphabet size is constant).
