### 🚀 1. **Looping over a container (modern C++)**

```cpp
for (auto& x : vec) doSomething(x);
```

* **Idiomatic** because `range-based for` is preferred for readability.
* **Compact** and eliminates the need for indexing.

---

### 🎯 2. **Swapping two variables (idiomatic use of `std::swap`)**

```cpp
std::swap(a, b);
```

* Much cleaner and safer than manually swapping:

  ```cpp
  int temp = a;
  a = b;
  b = temp;
  ```

---

### 🌳 3. **Pushing all left children in a BST (like your earlier code)**

```cpp
for (; node; st.push(node), node = node->left);
```

* One-liner tree traversal helper.
* Common in implementing in-order iterators.

---

### 📌 4. **Safe minimum/maximum of two values**

```cpp
auto minVal = std::min(a, b);
auto maxVal = std::max(a, b);
```

* Clean and avoids manual if-checks.

---

### 🔁 5. **Using `std::iota` to generate a sequence**

```cpp
std::vector<int> v(10);
std::iota(v.begin(), v.end(), 1); // fills with 1 to 10
```

* Compact and idiomatic for generating a series of numbers.

---

### 🎲 6. **Lambda for quick filtering or operations**

```cpp
std::sort(vec.begin(), vec.end(), [](int a, int b) {
    return abs(a) < abs(b);
});
```

* Idiomatic use of lambda functions for custom sorting.
* Compact and inline.

---

### 🧹 7. **RAII with smart pointers**

```cpp
std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
```

* Idiomatic memory management (no `new` / `delete` needed).
* Compact, modern, and safe.

---

### 💥 8. **One-liner ternary assignment**

```cpp
int result = (a > b) ? a : b;
```

* Idiomatic for quick decision assignment.

---

### 🧪 9. **Check if value exists in a set/map**

```cpp
if (mySet.count(x)) { /* x exists */ }
```

* More idiomatic than `find(x) != mySet.end()` for sets.

---

### 📚 10. **Initializer list constructor**

```cpp
std::vector<int> nums{1, 2, 3, 4};
```

* Idiomatic way to initialize STL containers.
* Clean and compact.

---

### 🌿 1. **Push all left nodes (iterative in-order traversal helper)**

```cpp
void pushLeft(TreeNode* node) {
    for (; node; st.push(node), node = node->left);
}
```

* Idiomatic and compact for pushing all left descendants.
* Used in in-order or BST iterators.

---

### 🔁 2. **Iterative In-order Traversal (using stack)**

```cpp
std::vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> st;
    TreeNode* curr = root;
    std::vector<int> res;

    while (curr || !st.empty()) {
        for (; curr; st.push(curr), curr = curr->left);
        curr = st.top(); st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}
```

* **Idiomatic** iterative traversal that mimics recursion without needing flags or visited markers.

---

### 🔙 3. **Post-order Traversal (recursive, idiomatic)**

```cpp
void postOrder(TreeNode* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->val << " ";
}
```

* Idiomatic recursion pattern for all DFS traversals.
* Same template for pre-order, in-order, and post-order.

---

### 🌳 4. **Recursive height of a tree**

```cpp
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(height(root->left), height(root->right));
}
```

* Clean and elegant — shows natural recursive structure of trees.

---

### 🔍 5. **Finding a node in BST (recursive)**

```cpp
TreeNode* find(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    return val < root->val ? find(root->left, val) : find(root->right, val);
}
```

* **Idiomatic BST search** using ternary operator.
* Compact and expressive.

---

### 🧩 6. **Balanced BST construction from sorted array**

```cpp
TreeNode* buildBST(const std::vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBST(nums, l, mid - 1);
    root->right = buildBST(nums, mid + 1, r);
    return root;
}
```

* Shows natural divide-and-conquer recursion.
* Very idiomatic for tree building.

---

### 🧠 7. **Lambda inside tree traversal (modern C++)**

```cpp
std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
    if (!node) return;
    dfs(node->left);
    std::cout << node->val << " ";
    dfs(node->right);
};
dfs(root);
```

* **Modern idiomatic style** using `std::function` and lambda.
* Great for local traversal logic (e.g., in competitive coding or function encapsulation).

---

### 💎 Bonus: Use of `nullptr` instead of `NULL`

```cpp
if (node == nullptr) return;
```





