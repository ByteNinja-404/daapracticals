# 📊 Algorithm Complexity Master Sheet

This document serves as a quick reference guide comparing the Time and Space complexities for algorithms covered in the Design and Analysis of Algorithms (DAA) Syllabus and Practicals.

## 🗝️ Legend

| Symbol | Description |
| :---: | :--- |
| **$n$** | Number of elements / input size |
| **$k$** | Range of input (for Count/Bucket sort) |
| **$d$** | Number of digits (for Radix sort) |
| **$V$** | Number of vertices in graph |
| **$E$** | Number of edges in graph |
| **$W$** | Knapsack Capacity |

---

## 1. Searching & Sorting Algorithms

| Algorithm | Best Case ($\Omega$) | Average Case ($\Theta$) | Worst Case ($O$) | Space Complexity | Remarks |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Linear Search** | $\Omega(1)$ | $\Theta(n)$ | $O(n)$ | $O(1)$ | Simple iteration. |
| **Binary Search** | $\Omega(1)$ | $\Theta(\log n)$ | $O(\log n)$ | $O(1)$ | Requires sorted array. |
| **Bubble Sort** | $\Omega(n)$ | $\Theta(n^2)$ | $O(n^2)$ | $O(1)$ | Best case happens when array is already sorted. |
| **Selection Sort** | $\Omega(n^2)$ | $\Theta(n^2)$ | $O(n^2)$ | $O(1)$ | Comparison count is always $n(n-1)/2$. |
| **Insertion Sort** | $\Omega(n)$ | $\Theta(n^2)$ | $O(n^2)$ | $O(1)$ | Very fast for small or nearly sorted arrays. |
| **Merge Sort** | $\Omega(n \log n)$ | $\Theta(n \log n)$ | $O(n \log n)$ | $O(n)$ | Stable sort; requires extra space. |
| **Heap Sort** | $\Omega(n \log n)$ | $\Theta(n \log n)$ | $O(n \log n)$ | $O(1)$ | Not stable; In-place. |
| **Quick Sort** | $\Omega(n \log n)$ | $\Theta(n \log n)$ | $O(n^2)$ | $O(\log n)$ | Worst case when pivot is always smallest/largest. |
| **Count Sort** | $\Omega(n+k)$ | $\Theta(n+k)$ | $O(n+k)$ | $O(n+k)$ | Non-comparison sort. Fast if $k \approx n$. |
| **Radix Sort** | $\Omega(d(n+k))$ | $\Theta(d(n+k))$ | $O(d(n+k))$ | $O(n+k)$ | Sorts digit by digit. |
| **Bucket Sort** | $\Omega(n+k)$ | $\Theta(n+k)$ | $O(n^2)$ | $O(n+k)$ | Worst case if all elements land in one bucket. |

---

## 2. Advanced Algorithms & Graphs

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Remarks |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Strassen's Matrix Mult** | $O(n^{2.81})$ | $O(n^{2.81})$ | $O(n^{2.81})$ | $O(n^2)$ | Faster than standard $O(n^3)$ for large $N$. |
| **BFS (Traversal)** | $O(V+E)$ | $O(V+E)$ | $O(V+E)$ | $O(V)$ | Uses Queue. |
| **DFS (Traversal)** | $O(V+E)$ | $O(V+E)$ | $O(V+E)$ | $O(V)$ | Uses Stack (Recursion). |
| **Prim's MST** | $\Omega(E \log V)$ | $\Theta(E \log V)$ | $O(V^2)$ | $O(V^2)$ | $O(V^2)$ with Adjacency Matrix (used in practical). |
| **Dijkstra's Algorithm** | $\Omega(E \log V)$ | $\Theta(E \log V)$ | $O(V^2)$ | $O(V^2)$ | $O(V^2)$ with Adjacency Matrix (used in practical). |
| **Weighted Interval** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(n)$ | $O(n \log n)$ if Binary Search is used; $O(n^2)$ with linear scan. |
| **0/1 Knapsack** | $O(nW)$ | $O(nW)$ | $O(nW)$ | $O(nW)$ | Pseudo-polynomial time. |
