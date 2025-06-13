# Majority Element I Problem

## Problem Statement
Given an integer array of size `n`, find all elements that appear more than ⌊n/3⌋ times.

Example:
```cpp
Input: [3,2,3]
Output: [3]

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
```

## Hash Map Approach Explanation

1. **Frequency Counting**:
   - We use an unordered map (`mpp`) to count how many times each number appears in the array.
   - This gives us a complete frequency distribution of all elements.

2. **Threshold Calculation**:
   - The threshold for being a majority element is ⌊n/3⌋, where n is the array size.
   - This means an element must appear more than n/3 times to be included in the result.

3. **Result Compilation**:
   - We iterate through the frequency map and collect all elements whose count exceeds the threshold.

### Complexity Analysis
- **Time Complexity**: O(n)
  - We make two passes through the array: 
    - One pass to count frequencies (O(n))
    - One pass through the map (O(n) in worst case)
- **Space Complexity**: O(n)
  - In the worst case, we might store all n elements in the map if all are unique

### Key Insights
- There can be **at most two** majority elements that appear more than ⌊n/3⌋ times in any array.
  - Proof: If three elements each appeared more than n/3 times, their total count would exceed n (impossible)
- The hash map approach is straightforward but uses O(n) space.

### Edge Cases
1. **Empty array**: Returns empty vector
2. **All elements same**: 
   ```cpp
   Input: [2,2,2,2]
   Output: [2]  // since 2 appears 4 > 4/3 times
   ```
3. **No majority elements**:
   ```cpp
   Input: [1,2,3,4]
   Output: []  // no element appears more than 1 time
   ```

### Alternative Approaches
1. **Boyer-Moore Voting Algorithm** (Optimal O(1) space solution):
   - Modified version of the standard voting algorithm
   - Maintains two candidates and counts since we can have at most two winners
   - Requires two passes: one to find candidates, one to verify

2. **Sorting Approach**:
   - Sort the array first
   - Then count consecutive elements in a single pass
   - Time: O(n log n), Space: O(1) if sorted in-place

### Why This Approach Works
The hash map solution is:
- **Simple** to implement and understand
- **Generalizable** to ⌊n/k⌋ cases
- **Efficient** for most practical cases where n isn't extremely large

### Visual Example
For input `[1,1,1,3,3,2,2,2]`:
1. Frequency map:
   ```
   1 → 3
   2 → 3
   3 → 2
   ```
2. Threshold = 8/3 = 2
3. Both 1 and 2 have counts > 2 → Output `[1,2]`
