# Pascal's Triangle Implementation Guide

## Table of Contents
1. [Problem Statement](#problem-statement)
2. [Approach 1: Mathematical Combination (nCr)](#approach-1-mathematical-combination-ncr)
3. [Approach 2: Dynamic Row Generation](#approach-2-dynamic-row-generation)
4. [Approach 3: Complete Triangle Generation](#approach-3-complete-triangle-generation)
5. [Complexity Analysis](#complexity-analysis)
6. [Edge Cases](#edge-cases)
7. [Alternative Implementations](#alternative-implementations)

## Problem Statement
Pascal's Triangle is a triangular array where each number is the sum of the two directly above it. Given an integer `numRows`, generate the first `numRows` of Pascal's triangle.

Example for `numRows = 5`:
```

     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]

```

## Approach 1: Mathematical Combination (nCr)
### Key Insight
Each element in Pascal's Triangle can be calculated using the combination formula:
```
element = C(row, col) = row! / (col! * (row-col)!)
```

### Implementation
```cpp
int generatEle(int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
```

### Characteristics
- **Time Complexity**: O(r) per element
- **Space Complexity**: O(1) per element
- **Best For**: Generating specific elements without building the entire triangle

## Approach 2: Dynamic Row Generation
### Key Insight
Each row can be generated from the previous element in the same row using:
```
element = previous_element * (row - col) / col
```

### Implementation
```cpp
vector<int> printRow(int r) {
    int row = r-1;
    vector<int> ans;
    int ele = 1;
    ans.push_back(ele);
    for(int i = 0; i < row; i++) {
        ele = ele * (row - i);
        ele = ele / (i + 1);
        ans.push_back(ele);
    }
    return ans;
}
```

### Characteristics
- **Time Complexity**: O(n) per row
- **Space Complexity**: O(n) for row storage
- **Best For**: Generating individual rows efficiently

## Approach 3: Complete Triangle Generation
### Key Insight
Build the triangle row by row where each element is the sum of the elements above-left and above-right.

### Implementation
```cpp
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle(numRows);
    for(int i = 1; i <= numRows; i++) {
        vector<int> ans = printRow(i);
        triangle.push_back(ans);
    }
    return triangle;
}
```

### Characteristics
- **Time Complexity**: O(numRows²) total
- **Space Complexity**: O(numRows²) for output
- **Best For**: Generating the complete triangle

## Complexity Analysis
| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| nCr Element | O(r) per element | O(1) |
| Single Row | O(n) per row | O(n) |
| Full Triangle | O(n²) total | O(n²) |

## Edge Cases
1. **numRows = 0**: Should return empty vector
2. **numRows = 1**: Should return `[[1]]`
3. **Large numRows**: Integer overflow potential in calculations

