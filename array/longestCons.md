# **Longest Consecutive Subsequence**  
**Problem:**  
Given an unsorted array (e.g., `[1, 21, 24, 3, 25, 22, 9, 23]`), find the length of the longest consecutive subsequence (e.g., `21, 22, 23, 24, 25` → length `5`).  

---

## **Approach 1: Sorting + Linear Scan**  
### **Steps:**  
1. **Sort the array** (e.g., `[1, 3, 9, 21, 22, 23, 24, 25]`).  
2. Traverse the sorted array while tracking the current (`ctr`) and maximum (`max_len`) consecutive sequence lengths:  
   - If `arr[i+1] == arr[i] + 1`, increment `ctr`.  
   - If `arr[i+1] != arr[i]` (handles duplicates), reset `ctr = 1`.  
   - Update `max_len` if `ctr > max_len`.  

### **Complexity:**  
- **Time:** O(n log n) (due to sorting).  
- **Space:** O(1) (if sorted in-place).  

### **Edge Cases:**  
- Duplicates (e.g., `[1, 2, 2, 3]` → `3`).  
- Empty array → return `0`.  

### **Code Snippet:**  
```cpp
        int long_seq = 0;
        int n = nums.size();
        if(n ==0 || n ==1) return n;
       
        sort(nums.begin(),nums.end());
        
        int curr_seq = 1;
        for(int i =1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i] == nums[i-1]+1){ 
                    curr_seq++;
                }else {
                    curr_seq = 1;
                }
            }
            long_seq = max(curr_seq,long_seq);
        }
        return long_seq;
```

---

## **Approach 2: Hash Set (Optimal)**  
### **Steps:**  
1. **Store all elements** in a hash set (`unordered_set` in C++, `set` in Python) for O(1) lookups.  
2. For each element `num` in the array:  
   - Check if `num-1` exists in the set (to avoid redundant checks).  
   - If `num-1` is **not** present, `num` is the start of a new sequence.  
   - Use a `while` loop to count consecutive elements (`num+1`, `num+2`, etc.).  
   - Update `max_len` if the current sequence is longer.  

### **Complexity:**  
- **Time:** O(n) (each element processed exactly twice).  
- **Space:** O(n) (for the hash set).  

### **Why It Works:**  
- By checking for `num-1`, we only process the **start** of each sequence, avoiding O(n²) time.  

### **Code Snippet:**  
```cpp
        unordered_map<int,int>mpp;
        int long_seq = 0;
        int n = nums.size();
        if(n ==0 || n ==1) return n;
        for(int i = 0 ;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        for(int i = 0 ; i<nums.size();i++){
            int curr_num = nums[i];
            
            int curr_seq = 0;
            while(mpp.find(curr_num+1)!=mpp.end()){
                curr_seq++;
                curr_num++;
            }
            long_seq = max(curr_seq,long_seq);
        }
        return long_seq+1;
```

---

## **Key Differences**  
| **Approach**  | **Time**       | **Space**  | **Best When**               |  
|---------------|---------------|------------|-----------------------------|  
| Sorting       | O(n log n)    | O(1)       | Small arrays, no extra space|  
| Hash Set      | O(n)          | O(n)       | Large arrays, optimal time  |  

---

## **Edge Cases to Consider**  
1. **Empty Array:** Return `0`.  
2. **All Duplicates:** `[5, 5, 5]` → `1`.  
3. **Single Element:** `[7]` → `1`.  
4. **Negative Numbers:** `[0, -1, -2]` → `3`.  

---

## **Visualization (Hash Set Approach)**  
**Input:** `[1, 21, 24, 3, 25, 22, 9, 23]`  
- **Hash Set:** `{1, 3, 9, 21, 22, 23, 24, 25}`  
- **Sequences Found:**  
  - `1` → `1` (no `0` in set).  
  - `3` → `3` (no `2` in set), but next elements missing → sequence length `1`.  
  - `21` → `21, 22, 23, 24, 25` → length `5`.  

**Output:** `5`  

---

### **Summary**  
- **Sorting** is simple but slower (`O(n log n)`).  
- **Hash Set** is optimal (`O(n)`) but uses extra space.  
- Always handle duplicates and empty arrays!  
