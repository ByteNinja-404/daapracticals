# 📘 Algorithm Theory & Mathematical Analysis

This document outlines the step-by-step logic, strategies, and mathematical foundations (including recurrence relations) for the algorithms covered in the DAA Practical File.

---

## 1. Insertion Sort
**Strategy:** Iterative

### Algorithm Steps
1.  Start from the second element (index 1) of the array.
2.  Store the current element in a variable `key`.
3.  Compare `key` with the elements in the sorted sub-array to its left.
4.  While the left element is greater than `key`, shift it one position to the right.
5.  Insert `key` into the correct position.
6.  Repeat until the end of the array.

### Mathematical Analysis
Since it is iterative, we express cost as a Summation:

* **Worst Case:** $\sum_{j=2}^{n} (j-1) \approx \frac{n(n-1)}{2} = O(n^2)$
* **Best Case:** $\sum_{j=2}^{n} 1 = (n-1) = \Omega(n)$

---

## 2. Merge Sort
**Strategy:** Divide and Conquer

### Algorithm Steps
1.  **Divide:** Find the middle index $m = (l+r)/2$.
2.  **Conquer:** Recursively call `mergeSort` for the first half ($l \dots m$) and second half ($m+1 \dots r$).
3.  **Combine:** Merge the two sorted subarrays using the `merge()` procedure.
    * Compare elements from both halves, pick the smaller one, and move pointers.

### Recurrence Relation
$$T(n) = 2T\left(\frac{n}{2}\right) + cn$$

* $2T(n/2)$: Sorting two halves.
* $cn$: Linear time to merge.
* **Master Theorem Solution:** $a=2, b=2, d=1$. Since $a = b^d$, complexity is **$O(n \log n)$**.

---

## 3. Heap Sort
**Strategy:** Transform and Conquer (using Data Structure)

### Algorithm Steps
1.  **Build Heap:** Convert array into a Max-Heap ($A[parent] \ge A[child]$).
2.  Swap the root (maximum value) with the last element.
3.  Reduce heap size by 1.
4.  **Heapify:** Recursively correct the root to restore Max-Heap property.
5.  Repeat steps 2-4 until heap size is 1.

### Mathematical Analysis
* **Build Heap:** $\sum \frac{n}{2^{h+1}} \cdot O(h) = O(n)$
* **Extraction Phase:** $n$ calls to heapify (height $\log n$).
* **Total:** $O(n) + n \log n = O(n \log n)$.

---

## 4. Strassen's Matrix Multiplication
**Strategy:** Divide and Conquer

### Algorithm Steps
1.  Divide matrices $A$ and $B$ of size $n \times n$ into 4 sub-matrices of size $n/2$.
2.  Compute 7 intermediate products ($P_1 \dots P_7$) using specific additions/subtractions.
    * *Example:* $P_1 = A_{11}(B_{12} - B_{22})$
3.  Compute the 4 quadrants of result matrix $C$ using additions of $P$ terms.

### Recurrence Relation
$$T(n) = 7T\left(\frac{n}{2}\right) + O(n^2)$$

* $7T(n/2)$: 7 Recursive multiplications (Standard uses 8).
* $O(n^2)$: Matrix additions/subtractions.
* **Master Theorem Solution:** $\log_b a = \log_2 7 \approx 2.81$.
* **Complexity:** $O(n^{2.81})$.

---

## 5. Radix Sort
**Strategy:** Distribution Sort (Non-Comparison)

### Algorithm Steps
1.  Find the maximum number to determine the number of digits $d$.
2.  For each digit position (unit's place, ten's place...):
    * Use a Stable Sorting algorithm (Counting Sort) to sort elements based on that specific digit.
3.  The array becomes sorted after the most significant digit is processed.

### Mathematical Analysis
$$T(n) = d \times (n + k)$$

* $d$: Number of digits (passes).
* $n$: Number of elements.
* $k$: Range of digits (10 for decimal system).
* **Complexity:** $O(n)$ (Linear time, assuming $d$ is constant).

---

## 6. Bucket Sort
**Strategy:** Distribution / Scatter-Gather

### Algorithm Steps
1.  Create $n$ empty buckets.
2.  For each element, calculate bucket index: $idx = n \times A[i]$.
3.  Insert element into the corresponding bucket.
4.  Sort individual buckets (typically using Insertion Sort).
5.  Concatenate all sorted buckets.

### Mathematical Analysis
* **Average Case:** Assuming uniform distribution, each bucket has $\approx 1$ element. Sorting takes constant time. Total $O(n)$.
* **Worst Case:** All elements fall into one bucket. Sorting takes $O(n^2)$.

---

## 7. Breadth First Search (BFS)
**Strategy:** Graph Traversal (Level Order)

### Algorithm Steps
1.  Use a **Queue**. Mark start node $s$ visited and enqueue it.
2.  While Queue is not empty:
    * Dequeue vertex $u$ and print it.
    * For every neighbor $v$ of $u$:
        * If $v$ is unvisited: Mark visited and Enqueue.

### Analysis
* **Vertex Visits:** Each vertex enqueued once: $O(V)$.
* **Edge Checks:** Each edge checked once (directed) or twice (undirected): $O(E)$.
* **Total:** $O(V + E)$.

---

## 8. Depth First Search (DFS)
**Strategy:** Graph Traversal (Backtracking)

### Algorithm Steps
1.  Use **Recursion (Stack)**.
2.  `DFS(u)`:
    * Mark $u$ visited and print it.
    * For every neighbor $v$ of $u$:
        * If $v$ is unvisited: Recursively call `DFS(v)`.

### Analysis
Same logic as BFS. We traverse every node and every adjacency list.
* **Total:** $O(V + E)$.

---

## 9. Prim's Algorithm (MST)
**Strategy:** Greedy Algorithm

### Algorithm Steps
1.  Maintain `key[]` (min weight to connect), `parent[]`, and `mstSet[]`.
2.  Initialize keys to $\infty$, start node to 0.
3.  Repeat $V$ times:
    * Pick vertex $u$ with minimum key not in `mstSet`.
    * Add $u$ to `mstSet`.
    * Update neighbors $v$:
        * If edge $(u,v)$ exists and $weight(u,v) < key[v]$:
            * $key[v] = weight(u,v)$, $parent[v] = u$.

### Analysis
* **With Adjacency Matrix:** $V \times (O(V) \text{ scan} + O(V) \text{ update}) = O(V^2)$.
* **With Binary Heap:** $O(E \log V)$.

---

## 10. Dijkstra's Algorithm (Shortest Path)
**Strategy:** Greedy Algorithm

### Algorithm Steps
1.  Maintain `dist[]` and `sptSet[]`. Set `dist[src]=0`, others $\infty$.
2.  Repeat $V$ times:
    * Pick vertex $u$ with min `dist` not in `sptSet`.
    * **Relaxation:** For every neighbor $v$ of $u$:
        * If $dist[u] + weight(u,v) < dist[v]$:
            * $dist[v] = dist[u] + weight(u,v)$.

### Analysis
Same as Prim's.
* $O(V^2)$ (Matrix)
* $O(E \log V)$ (Heap).

---

## 11. Weighted Interval Scheduling
**Strategy:** Dynamic Programming

### Algorithm Steps
1.  Sort jobs by **Finish Time**.
2.  Calculate $p(j)$ for each job: the largest index $i < j$ compatible with job $j$.
3.  Define $M[j]$: Max profit using first $j$ jobs.
4.  Recurrence: For job $j$:
    * **Include:** Profit $w_j + M[p(j)]$
    * **Exclude:** Profit $M[j-1]$
    * Take the maximum.

### Recurrence Relation
$$M[j] = \max(w_j + M[p(j)], \quad M[j-1])$$

* **Complexity:** $O(n \log n)$ (due to sorting).

---

## 12. 0/1 Knapsack Problem
**Strategy:** Dynamic Programming

### Algorithm Steps
1.  Create table $K[n+1][W+1]$.
2.  Iterate $i$ (items) from $0 \to n$ and $w$ (capacity) from $0 \to W$.
3.  If $wt[i] \le w$:
    * Max of (Value of item $i$ + Value of remaining capacity) OR (Value without item $i$).
4.  Else:
    * Value is same as without item $i$.

### Recurrence Relation
$$K[i, w] = \max(val_i + K[i-1, w-wt_i], \quad K[i-1, w])$$

* **Complexity:** $O(n \times W)$ (Pseudo-Polynomial).
