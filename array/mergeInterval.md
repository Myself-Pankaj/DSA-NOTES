# Merge Overlapping Intervals

## Problem Statement
Given an array of intervals where `intervals[i] = [starti, endi]`, merge all overlapping intervals and return an array of non-overlapping intervals that cover all intervals in the input.

### Example
```javascript
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Intervals [1,3] and [2,6] overlap → merged into [1,6]
```

## Optimal Approach
1. **Sort intervals** by start time (crucial for linear merging)
2. **Initialize result** with first interval
3. **Iterate through intervals**:
   - If current interval overlaps with last merged interval, merge them
   - Else add current interval to result

## JavaScript Implementation
```javascript
function merge(intervals) {
    if (intervals.length <= 1) return intervals;
    
    // Sort intervals by start time
    intervals.sort((a, b) => a[0] - b[0]);
    
    const merged = [intervals[0]];
    
    for (let i = 1; i < intervals.length; i++) {
        const last = merged[merged.length - 1];
        const current = intervals[i];
        
        // Check for overlap
        if (current[0] <= last[1]) {
            // Merge intervals
            last[1] = Math.max(last[1], current[1]);
        } else {
            merged.push(current);
        }
    }
    
    return merged;
}
```

## Key Steps Explained
1. **Sorting**:
   ```javascript
   intervals.sort((a, b) => a[0] - b[0]);
   ```
   - Ensures all potentially mergeable intervals are adjacent

2. **Merging Logic**:
   ```javascript
   if (current[0] <= last[1]) {
       last[1] = Math.max(last[1], current[1]);
   }
   ```
   - If current interval starts before previous ends → merge by taking maximum end time

3. **Non-overlapping Case**:
   ```javascript
   else {
       merged.push(current);
   }
   ```
   - Add to result when no overlap detected

## Complexity Analysis
- **Time Complexity**: O(n log n)
  - Dominated by sorting step (O(n log n))
  - Merging pass is O(n)
- **Space Complexity**: O(n)
  - For storing the result (worst case: no merges)

## Test Cases
```javascript
console.log(merge([[1,3],[2,6],[8,10],[15,18]])); 
// [[1,6],[8,10],[15,18]]

console.log(merge([[1,4],[4,5]])); 
// [[1,5]]

console.log(merge([[1,4],[0,4]])); 
// [[0,4]]

console.log(merge([[1,4],[2,3]])); 
// [[1,4]]
```

## Edge Cases
1. **Empty Input**:
   ```javascript
   merge([]) → []
   ```
2. **Single Interval**:
   ```javascript
   merge([[1,3]]) → [[1,3]]
   ```
3. **Complete Overlap**:
   ```javascript
   merge([[1,4],[2,3]]) → [[1,4]]
   ```
4. **Multiple Merges Needed**:
   ```javascript
   merge([[1,4],[2,5],[6,8],[7,9]]) → [[1,5],[6,9]]
   ```

