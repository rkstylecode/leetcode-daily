# Longest Balanced Substring (a, b, c)

## Problem Statement

Given a string `s` consisting only of characters `'a'`, `'b'`, and `'c'`, return the length of the longest balanced substring.

A substring is considered balanced if it satisfies **any one** of the following conditions:

1. It contains only one repeating character (e.g., `"aaa"`).
2. It contains exactly two distinct characters and their counts are equal (e.g., `"aabb"`).
3. It contains all three characters `'a'`, `'b'`, and `'c'` and their counts are equal (e.g., `"abcabc"`).

---

## Approach

We evaluate three possible balanced cases separately and take the maximum length among them.

---

### 1️⃣ Single Character Case

Goal: Find the longest consecutive block of the same character.

Method:
- Traverse the string once.
- Maintain a running count of consecutive identical characters.
- Reset the counter when the character changes.
- Track the maximum length.

Time: `O(n)`  
Space: `O(1)`

---

### 2️⃣ Two-Character Balanced Case

For each pair:
- (`a`, `b`)
- (`b`, `c`)
- (`c`, `a`)

We use a **prefix difference + hashmap** technique.

Let:
diff = count(ch1) - count(ch2)

If the same `diff` appears at indices `i` and `j`, then the substring between them has equal counts of `ch1` and `ch2`.

If a third character appears:
- Reset `diff`
- Clear the hashmap
- Restart from next position

Time per pair: `O(n)`  
Total: `O(n)`  
Space: `O(n)`

---

### 3️⃣ Three-Character Balanced Case

Track counts of:
a, b, c

Define:
diff1 = a - b
diff2 = a - c

If the same pair `(diff1, diff2)` appears at two indices, then the substring between them has:
count(a) = count(b) = count(c)

Store the first occurrence of each `(diff1, diff2)` in a hashmap.

Time: `O(n)`  
Space: `O(n)`

---

## Overall Complexity

### Time Complexity

- Single scan → `O(n)`
- Three paired scans → `O(3n)`
- Triplet scan → `O(n)`

Overall: O(n)

---

### Space Complexity

- Hashmap for paired case → `O(n)`
- Hashmap for triplet case → `O(n)`

Overall: O(n)
