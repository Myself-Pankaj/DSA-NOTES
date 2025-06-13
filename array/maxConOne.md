# Maximum Consecutive Ones

## Problem Statement
Given a binary array `nums` (containing 0s and 1s), find the maximum number of consecutive 1s.

Example:
```python
Input: [1,0,1,1,1,1,0,1,0,1,0]
Output: 4 
Explanation: The longest sequence of consecutive 1s is `[1,1,1,1]`
```

## Optimal Approach: Single Pass with Counter

### Solution Code
```js
function findMaxConsecutiveOnes(nums) {
    let maxOne = 0;
    let currentStreak = 0;
    
    for (const num of nums) {
        if (num === 1) {
            currentStreak++;
            maxOne = Math.max(maxOne, currentStreak);
        } else {
            currentStreak = 0;
        }
    }
    
    return maxOne;
}
```

### Approach Explanation
1. **Initialize counters**:
   - `max_count` to track the overall maximum consecutive 1s found
   - `current_count` to count consecutive 1s in the current streak

2. **Linear scan**:
   - For each element in the array:
     - If the element is `1`, increment `current_count` and update `max_count`
     - If the element is `0`, reset `current_count` to 0

3. **Return result**:
   - After processing all elements, `max_count` holds the answer

### Complexity Analysis
- **Time Complexity**: O(n)
  - Single pass through the array
- **Space Complexity**: O(1)
  - Uses only constant extra space

### Key Insights
- The solution efficiently tracks consecutive 1s by maintaining a running counter
- Resets the counter immediately when a 0 is encountered
- Only needs to compare/update the maximum when we're in a streak of 1s

### Edge Cases
1. **All 1s**:
   ```js
   Input: [1,1,1,1]
   Output: 4
   ```
2. **All 0s**:
   ```js
   Input: [0,0,0]
   Output: 0
   ```
3. **Empty array**:
   ```js
   Input: []
   Output: 0
   ```
4. **Alternating 1s and 0s**:
   ```js
   Input: [1,0,1,0,1]
   Output: 1
   ```

### Visual Walkthrough
For input `[1,0,1,1,1,0,1]`:
```
Index: 0: 1 (current=1, max=1)
       1: 0 (current=0, max=1)
       2: 1 (current=1, max=1)
       3: 1 (current=2, max=2)
       4: 1 (current=3, max=3)
       5: 0 (current=0, max=3)
       6: 1 (current=1, max=3)
Final result: 3
```

### Alternative Approaches
1. **Sliding Window**:
   - Maintain a window of consecutive 1s
   - Expand right when seeing 1, reset left when seeing 0
   - Same O(n) time but more complex to implement

2. **Split by 0s**:
   - Convert array to string and split by '0'
   - Find longest substring of '1's
   - Less efficient due to string operations

### Why This Approach Works Best
- **Simple and intuitive**: Easy to understand and implement
- **Optimal**: Achieves the best possible time complexity
- **Space efficient**: Uses only two variables regardless of input size
- **Early termination**: Could stop early if remaining elements can't beat current max

### Variations
1. **With at most K flips** (harder version):
   - Can flip at most K 0s to 1s
   - Solved using sliding window technique

2. **Consecutive 1s in 2D array**:
   - Find in rows, columns or diagonals
   - Requires more complex traversal
``` 
