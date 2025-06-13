# **Array Problems: Approaches & Complexities**  
*(Expanded with Explanations)*  

---

## **1. Find Smallest and Largest Element in Array**  
**Problem:**  
Given an array (e.g., `[1, 56, 8, 7, 90]`), return the smallest (`1`) and largest (`90`) elements.  

### **Approach 1: Sorting**  
1. **Steps:**  
   - Sort the array in ascending order.  
   - The first element is the **smallest**, and the last is the **largest**.  
2. **Complexity:**  
   - **Time:** O(n log n) (due to sorting).  
   - **Space:** O(1) (if sorted in-place).  
3. **Edge Cases:**  
   - Empty array → Handle with a check.  
   - All elements identical → Still works (smallest == largest).  

### **Approach 2: Linear Scan**  
1. **Steps:**  
   - Initialize `mini = +∞` and `maxi = -∞`.  
   - Traverse the array:  
     - If `arr[i] < mini`, update `mini`.  
     - If `arr[i] > maxi`, update `maxi`.  
2. **Complexity:**  
   - **Time:** O(n) (single pass).  
   - **Space:** O(1).  
3. **Why It Works:**  
   - Guarantees correctness by checking every element exactly once.  

---

## **2. Find Second Largest Element**  
**Problem:**  
Given `[1, 56, 8, 9, 90]`, return the second largest (`56`).  

### **Approach 1: Sorting + Right Scan**  
1. **Steps:**  
   - Sort the array.  
   - Start from the end and find the first element smaller than the largest.  
2. **Complexity:**  
   - **Time:** O(n log n).  
   - **Space:** O(1).  
3. **Edge Cases:**  
   - All elements equal → No second largest.  
   - Duplicate largest values (e.g., `[5, 5, 2]`) → Skip duplicates.  

### **Approach 2: Single Traversal**  
1. **Steps:**  
   - Initialize `largest` and `second_largest` as `-∞`.  
   - Traverse the array:  
     - If `arr[i] > largest`:  
       - Update `second_largest = largest`.  
       - Update `largest = arr[i]`.  
     - Else if `arr[i] > second_largest` and `arr[i] != largest`:  
       - Update `second_largest`.  
2. **Complexity:**  
   - **Time:** O(n).  
   - **Space:** O(1).  
3. **Key Insight:**  
   - Maintains the two largest values dynamically without sorting.  

---

## **3. Check Rotated Sorted Array**  
**Problem:**  
Given `[4, 5, 6, 1, 2, 3]`, return `true` if rotating it can make it sorted (e.g., rotating by 3 gives `[1, 2, 3, 4, 5, 6]`).  

### **Approach: Count Inversions**  
1. **Steps:**  
   - Traverse the array and count how many times `arr[i] > arr[i+1]`.  
   - If the count is **≤ 1**, it’s a rotated sorted array.  
   - Use `% n` to handle circular checks (e.g., compare `arr[n-1]` with `arr[0]`).  
2. **Complexity:**  
   - **Time:** O(n).  
   - **Space:** O(1).  
3. **Why It Works:**  
   - A sorted array rotated once will have exactly one inversion point.  

---

## **4. Remove Duplicates from Sorted Array**  
**Problem:**  
Given `[4, 4, 5, 6, 7, 7, 8, 9]`, return `[4, 5, 6, 7, 8, 9]` (in-place).  

### **Approach: Two Pointers**  
1. **Steps:**  
   - Initialize pointer `i = 0`.  
   - Traverse with pointer `j`:  
     - If `arr[j] != arr[i]`, increment `i` and copy `arr[j]` to `arr[i]`.  
   - Return `i + 1` as the new length.  
2. **Complexity:**  
   - **Time:** O(n).  
   - **Space:** O(1).  
3. **Visualization:**  
   ```
   [4, 4, 5, 6, ...]  
    i  j → j moves, copies 5 to i+1 → [4, 5, 6, ...]
   ```

---

## **5. Rotate Array by K Positions**  
**Problem:**  
Rotate `[11, 12, 13, 1, 9, 8]` by `k=3` to get `[1, 9, 8, 11, 12, 13]`.  

### **Approach 1: Brute Force (K Rotations)**  
1. **Steps:**  
   - Rotate left by 1 position (shift left and move first element to end).  
   - Repeat `k` times.  
2. **Complexity:**  
   - **Time:** O(n * k).  
   - **Space:** O(1).  

### **Approach 2: Reversal Algorithm**  
1. **Steps:**  
   - Reverse subarray `[0, k-1]`.  
   - Reverse subarray `[k, n-1]`.  
   - Reverse the entire array.  
2. **Example:**  
   ```
   Original: [11, 12, 13, 1, 9, 8]  
   Step 1: Reverse first 3 → [13, 12, 11, 1, 9, 8]  
   Step 2: Reverse rest → [13, 12, 11, 8, 9, 1]  
   Step 3: Reverse all → [1, 9, 8, 11, 12, 13]  
   ```  
3. **Complexity:**  
   - **Time:** O(n).  
   - **Space:** O(1).  

---

## **6. Move Zeroes to End**  
**Problem:**  
Given `[1, 2, 0, 1, 3, 12, 0, 0, 32, 0]`, move zeroes to end (`[1, 2, 1, 3, 12, 32, 0, 0, 0, 0]`).  

### **Approach: Two Pointers (Like Duplicates)**  
1. **Steps:**  
   - Pointer `i` tracks the position for the next non-zero.  
   - Traverse with `j`: if `arr[j] != 0`, copy to `i` and increment `i`.  
   - Fill remaining positions with zeroes.  
2. **Complexity:**  
   - **Time:** O(n).  
   - **Space:** O(1).  

---

## **7. Rearrange Positive & Negative Alternately**  
**Problem:**  
Given `[12, -1, -13, -14, -21, 2, 3, 4]`, return `[12, -1, 2, -13, 3, -14, 4, -21]`.  

### **Approach 1: Two Arrays**  
1. **Steps:**  
   - Separate positives and negatives into two arrays.  
   - Merge alternately.  
2. **Complexity:**  
   - **Time:** O(n).  
   - **Space:** O(n).  

### **Approach 2: In-Place (Optimal)**  
1. **Steps:**  
   - Use two pointers: `pos = 0` (for positives), `neg = 1` (for negatives).  
   - Traverse and swap misplaced elements.  
2. **Complexity:**  
   - **Time:** O(n).  
   - **Space:** O(1).  

---

### **Key Takeaways**  
- **Sorting** is straightforward but often suboptimal for time.  
- **Two Pointers** are powerful for in-place operations.  
- **Edge Cases:** Empty arrays, all duplicates, single-element arrays.  
