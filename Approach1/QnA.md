# 🎓 DAA Viva Questions & Answers

This document contains a comprehensive collection of potential Viva questions, covering general concepts, practical specifics, examiner traps, and theoretical proofs.

---

# PART A: Essentials & Practical Specifics

## 1. General DAA Concepts

**Q1: What is "Asymptotic Notation"? Why do we use it?**
> **Answer:** It is a mathematical notation used to describe the limiting behavior of a function. In algorithms, we use it to represent Time and Space complexity as the input size ($n$) grows to infinity. It helps us compare algorithms independent of hardware or compiler speed.
> * **Big O ($O$):** Worst-case (Upper Bound).
> * **Omega ($\Omega$):** Best-case (Lower Bound).
> * **Theta ($\Theta$):** Average/Tight Bound.

**Q2: What is the difference between Time Complexity and Wall-Clock Time?**
> **Answer:**
> * **Time Complexity:** The number of operations (steps) an algorithm takes as a function of input size (e.g., $O(n^2)$). It is theoretical.
> * **Wall-Clock Time:** The actual time in seconds/milliseconds taken to run the code. It depends on the processor, RAM, and background processes.

**Q3: What are the three main algorithm design paradigms you studied?**
> **Answer:**
> 1.  **Divide and Conquer:** Break problem into sub-problems, solve distinct sub-problems, combine results (e.g., Merge Sort).
> 2.  **Greedy:** Make the best local choice at each step to find a global optimum (e.g., Dijkstra).
> 3.  **Dynamic Programming:** Solve overlapping sub-problems and store results to avoid re-computation (e.g., Knapsack).

---

## 2. Practical-Specific Questions

### Sorting (Insertion, Merge, Heap)
**Q4: Why is Insertion Sort preferred for small arrays?**
> **Answer:** It has very low overhead (no recursion stack, no extra memory allocation). For small $N$ (approx. $< 20$), its simple $O(n^2)$ logic is faster than the complex setup of $O(n \log n)$ algorithms. It is also **Adaptive** (fast if array is nearly sorted).

**Q5: Why is Merge Sort considered "Stable"?**
> **Answer:** A sort is stable if it preserves the relative order of equal elements. Merge Sort is stable because in the merge step, if `Left[i] == Right[j]`, we pick `Left[i]` first, keeping it ahead of the equal element from the right.

**Q6: What is the difference between `heapify` and `buildHeap`?**
> **Answer:**
> * **`heapify`:** Takes a single node violating the property and fixes it downwards ($O(\log n)$).
> * **`buildHeap`:** Calls heapify on all non-leaf nodes to convert an arbitrary array into a valid heap ($O(n)$).

### Matrix Multiplication (Strassen)
**Q7: How does Strassen's Algorithm achieve better complexity?**
> **Answer:** Standard matrix multiplication takes 8 multiplications for a $2\times2$ block. Strassen discovered a way to do it with **7 multiplications** using algebraic tricks. Over large recursion depths, this reduces complexity from $O(n^3)$ to $O(n^{2.81})$.

### Linear Sorts (Radix, Bucket)
**Q8: If Radix Sort is $O(n)$, why don't we use it everywhere instead of Quick Sort?**
> **Answer:**
> 1.  It requires extra space.
> 2.  It depends on digits/bits. If numbers are huge (e.g., 64-bit integers), the constant factor becomes large.
> 3.  It is not cache-friendly compared to Quick Sort (which is in-place).

**Q9: What is the worst-case scenario for Bucket Sort?**
> **Answer:** When all elements fall into the **same bucket**. The algorithm then degrades to the speed of the sorting algorithm used for that individual bucket (often $O(n^2)$ if using Insertion Sort).

### Graph Traversals (BFS, DFS)
**Q10: Which data structure is used for BFS vs. DFS?**
> **Answer:**
> * **BFS:** Uses a **Queue** (FIFO) to explore level-by-level.
> * **DFS:** Uses a **Stack** (LIFO) or Recursion to explore depth-first.

**Q11: How do you detect a cycle in a graph using DFS?**
> **Answer:** If you encounter a visited vertex that is **not** the immediate parent of the current vertex (in the recursion stack), a cycle exists.

### Greedy Algorithms (Prim, Dijkstra)
**Q12: Why does Dijkstra's algorithm fail with negative edge weights?**
> **Answer:** Dijkstra's algorithm assumes that once a node is marked "visited" (processed), its shortest distance is final. Negative edges can create paths that reduce the total distance *after* a node has been marked visited, breaking this assumption.

**Q13: What is the main difference between Prim's and Kruskal's algorithm?**
> **Answer:**
> * **Prim's:** Grows a single tree from a starting source node. Good for **Dense** graphs.
> * **Kruskal's:** Adds edges one by one (sorted by weight) to merge forests. Good for **Sparse** graphs.

### Dynamic Programming (Knapsack, Scheduling)
**Q14: What does "0/1" mean in the Knapsack problem?**
> **Answer:** It means for every item, you have a binary choice: take the whole item (1) or leave it (0). You cannot break items (like cutting a gold bar), which would be the "Fractional Knapsack" problem (solvable by Greedy).

**Q15: Explain the term "Pseudo-Polynomial Time" regarding Knapsack.**
> **Answer:** The complexity is $O(n \times W)$. While $n$ is the number of items, $W$ is the value of the capacity. If $W$ requires $k$ bits to represent, then $W = 2^k$. The complexity is exponential in terms of the number of bits ($O(n \cdot 2^k)$), hence "pseudo" polynomial.

**Q16: Why do we sort jobs by "Finish Time" in Weighted Interval Scheduling?**
> **Answer:** Sorting by finish time allows us to linearize the problem. When we are at job $i$, we know that all compatible previous jobs must have finished before job $i$ starts. This makes finding the `latestNonConflict` job possible and enables the DP approach.

---

## 3. Examiner's Trap Questions (Be Careful!)

**Q17: Is Quick Sort $O(n^2)$?**
> **Answer:** In the worst case, yes. But on average, it is $O(n \log n)$ and is generally the fastest sorting algorithm in practice due to small constant factors and cache efficiency.

**Q18: Can we use Binary Search on a Linked List?**
> **Answer:** We can, but it is inefficient ($O(n)$) because we cannot access the middle element in $O(1)$ time; we have to traverse the list to find it. Binary search works best on Arrays.

**Q19: Which is better: Adjacency Matrix or Adjacency List?**
> **Answer:**
> * **Matrix:** Better for **Dense Graphs** (many edges) or when we frequently need to check `isEdge(u, v)`. Space: $O(V^2)$.
> * **List:** Better for **Sparse Graphs** (few edges) and iterating over neighbors. Space: $O(V+E)$.

**Q20: What is the difference between NULL and void?**
> **Answer:**
> * **NULL** (or `nullptr` in C++): A pointer value representing "nowhere" or address 0.
> * **void:** A data type representing "nothing" or "no type" (used for function return types).

---
---

# PART B: Deep Dive & Theory

## 1. Theoretical Foundations & Correctness

**Q1: What is "Loop Invariance"?**
> **Answer:** Loop invariance is a property used to prove the correctness of an iterative algorithm. It is a condition that is true:
> 1.  **Initialization:** Before the loop starts.
> 2.  **Maintenance:** Before and after each iteration.
> 3.  **Termination:** When the loop ends, giving us a useful property (like "the array is sorted").

**Q2: What is the "Lower Bound" for Comparison-based Sorting?**
> **Answer:** It is mathematically proven that any sorting algorithm that works by comparing elements (like Merge, Heap, Quick) requires at least **$\Omega(n \log n)$** comparisons in the worst case. This is why we can't make a generic comparison sort faster than $n \log n$.

**Q3: Explain the "Master Theorem".**
> **Answer:** It is a formula to solve recurrence relations of the form $T(n) = aT(n/b) + f(n)$. It provides three cases to determine complexity based on the relationship between $a$ (number of subproblems), $b$ (size reduction factor), and $f(n)$ (cost of dividing/merging).

**Q4: What is the difference between "Internal" and "External" sorting?**
> **Answer:**
> * **Internal Sorting:** All data fits into the main memory (RAM). (e.g., Quick Sort, Insertion Sort).
> * **External Sorting:** Data is too large for RAM and resides on a disk; only chunks are loaded at a time. (e.g., External Merge Sort).

---

## 2. Sorting Algorithms (Deep Dive)

**Q5: Which sorting algorithms are "In-Place"?**
> **Answer:** An algorithm is in-place if it requires only a constant amount of extra space ($O(1)$).
> * **In-Place:** Insertion Sort, Bubble Sort, Heap Sort, Quick Sort (ignoring stack space).
> * **Not In-Place:** Merge Sort ($O(n)$), Counting Sort, Radix Sort.

**Q6: Why is Quick Sort's worst case $O(n^2)$? How can we avoid it?**
> **Answer:** It happens when the pivot is always the smallest or largest element (e.g., sorting an already sorted array). This creates unbalanced partitions ($1$ vs $n-1$).
> * **Fix:** Use Randomized Pivot or "Median of Three" pivot selection.

**Q7: In Heap Sort, how do you map binary tree indices to an array?**
> **Answer:** For a node at index `i` (0-based):
> * **Parent:** `(i - 1) / 2`
> * **Left Child:** `2 * i + 1`
> * **Right Child:** `2 * i + 2`

**Q8: Why does Counting Sort fail if the range of numbers ($k$) is very large?**
> **Answer:** We need to allocate an auxiliary array of size $k$. If we sort just 5 elements but their values range from 1 to $10^9$, we would need a massive array, causing Memory Overflow and inefficiency ($O(n+k)$ becomes huge).

---

## 3. Advanced Algorithms (Strassen & Matrix)

**Q9: In Strassen's Algorithm, what happens if the matrix size $N$ is NOT a power of 2?**
> **Answer:** We use **Padding**. We add extra rows and columns of zeros to the matrix until its dimensions reach the next power of 2 (e.g., pad a $3\times3$ matrix to $4\times4$).

---

## 4. Graph Algorithms

**Q10: What is the "Cut Property" in MST (Minimum Spanning Tree)?**
> **Answer:** It states that for any cut (a split of vertices into two disjoint sets), the minimum weight edge crossing the cut must belong to the MST. This is the theoretical basis for Prim's and Kruskal's algorithms.

**Q11: Can BFS find the shortest path in a Weighted Graph?**
> **Answer:** **No.** BFS only finds the shortest path in terms of the number of edges. In a weighted graph, a path with more edges could have a smaller total weight. You must use Dijkstra’s.

**Q12: What are "Discovery Time" and "Finish Time" in DFS?**
> **Answer:**
> * **Discovery Time:** When a node is first visited (turned gray).
> * **Finish Time:** When all its descendants have been visited and we backtrack (turned black).
> * These are used in Topological Sorting.

**Q13: How do you handle graph algorithms if the graph is Disconnected?**
> **Answer:** You must wrap the algorithm in a loop that iterates through all vertices $1$ to $V$. If a vertex is unvisited, call the algorithm (BFS/DFS/Prim) starting from that vertex. This processes all "Connected Components".

**Q14: What is the difference between an Adjacency Matrix and an Adjacency List in terms of "checking if an edge exists"?**
> **Answer:**
> * **Matrix:** $O(1)$ time (Direct access `A[u][v]`).
> * **List:** $O(degree(u))$ time (Must traverse the linked list of `u`).

---

## 5. Greedy vs. Dynamic Programming

**Q15: What is "Memoization" vs "Tabulation"?**
> **Answer:**
> * **Memoization (Top-Down):** Recursive. Solves the main problem and caches result of sub-problems. Solves only necessary sub-problems.
> * **Tabulation (Bottom-Up):** Iterative. Fills a table from base cases up to the final answer. Solves all sub-problems.

**Q16: Why does the Greedy strategy work for "Fractional Knapsack" but not "0/1 Knapsack"?**
> **Answer:** In Fractional, we can take parts of items to fill the gap perfectly based on Value/Weight ratio. In 0/1, taking the item with the highest ratio might leave a gap that cannot be filled efficiently, resulting in a suboptimal total value.

**Q17: What happens to Weighted Interval Scheduling if all weights are 1?**
> **Answer:** It reduces to the Interval Scheduling (or Activity Selection) problem, which can then be solved using a simple Greedy Algorithm (pick earliest finish time) in $O(n \log n)$.

---

## 6. Conceptual & Tricky Questions

**Q18: Is the MST of a graph unique?**
> **Answer:**
> * If all edge weights are **distinct**, the MST is unique.
> * If some edges have equal weights, there can be multiple valid MSTs (though the total weight will be the same).

**Q19: What is the physical meaning of "Relaxation" in Dijkstra's?**
> **Answer:** It effectively asks: "Can I improve the current known shortest distance to vertex $V$ by taking a detour through vertex $U$?" If yes, update the distance.

**Q20: What is the Space Complexity of a Recursive Algorithm?**
> **Answer:** It is determined by the maximum depth of the recursion stack.
> * Merge Sort: $O(\log n)$
> * DFS: $O(V)$ (in worst case)
> * Quick Sort: $O(n)$ worst case, $O(\log n)$ average.
