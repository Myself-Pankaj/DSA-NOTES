### ✅ 1. **BFS for Unweighted Graphs (Undirected or Directed)**

* **Use BFS** when all edges have **equal weight** (typically 1).
* It finds the **shortest path in terms of number of edges**.

✅ Example:

```text
Graph with unit weights (0-1 edges)
```

🟢 You’re correct — **BFS works for undirected/directed graphs with equal weights**.

---

### ✅ 2. **Topological Sort + Edge Relaxation (for DAGs)**

* Works only for **Directed Acyclic Graphs (DAGs)**.
* Process nodes in **topological order**, and **relax all outgoing edges**.

✅ Efficient: **O(V + E)** time.

🟢 Yes — for DAGs, this is the **best approach** for shortest paths.

---

### ✅ 3. **Dijkstra’s Algorithm (Greedy + Min Heap)**

* Works for graphs with **non-negative weights**, directed or undirected.
* Can handle:

  * Varying weights
  * No cycles or cyclic graphs
  * More general cases than BFS/topo sort

✅ Time: `O(E log V)` with min-heap (priority\_queue).

🟡 **BFS fails when weights ≠ 1**, and **DAG method fails if cycles exist** — this is where Dijkstra shines.

---

### 🔴 When to use what?

| Graph Type | Edge Weights      | Best Algorithm      |
| ---------- | ----------------- | ------------------- |
| Unweighted | All edges = 1     | BFS                 |
| DAG        | Any weight        | Topological + Relax |
| General    | Non-negative      | Dijkstra            |
| General    | Can have negative | Bellman-Ford        |

---

### 🧠 Summary (Yes, you're mostly right):

* ✅ **BFS** → Undirected/Directed **unit-weighted** graphs
* ✅ **Topo Sort + Relaxation** → **DAGs**
* ✅ **Dijkstra** → **General graphs with non-negative weights**
* ❌ Dijkstra doesn't work with **negative weights**


