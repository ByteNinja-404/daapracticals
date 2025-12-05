# 📝 Design & Analysis of Algorithms - MCQ Practice

This document contains **50 Multiple Choice Questions** covering the entire DAA syllabus (Asymptotic Notation, Sorting, Graphs, Greedy, and DP).

> **Instructions:** Try to solve these without looking at the answers first.
> ⬇️ **The Answer Key is provided at the very bottom of this document.**

---

## Section 1: Asymptotic Notations & Foundations

**1. What does Big O notation ($O$) represent?**
- ( ) a) Lower Bound
- ( ) b) Tight Bound
- ( ) c) Upper Bound
- ( ) d) Average Case

**2. What is the lower bound for any comparison-based sorting algorithm?**
- ( ) a) $\Omega(n)$
- ( ) b) $\Omega(n^2)$
- ( ) c) $\Omega(n \log n)$
- ( ) d) $\Omega(\log n)$

**3. If an algorithm takes $T(n) = 2T(n/2) + n$ time, what is its complexity using Master Theorem?**
- ( ) a) $O(n)$
- ( ) b) $O(n^2)$
- ( ) c) $O(n \log n)$
- ( ) d) $O(\log n)$

**4. Which property is required to prove the correctness of an iterative algorithm?**
- ( ) a) Recursion Tree
- ( ) b) Loop Invariance
- ( ) c) Optimal Substructure
- ( ) d) Overlapping Subproblems

**5. What is the time complexity of Binary Search in the worst case?**
- ( ) a) $O(1)$
- ( ) b) $O(n)$
- ( ) c) $O(\log n)$
- ( ) d) $O(n \log n)$

**6. Which notation represents the "Best Case" scenario?**
- ( ) a) Big O ($O$)
- ( ) b) Theta ($\Theta$)
- ( ) c) Omega ($\Omega$)
- ( ) d) Little o ($o$)

**7. An algorithm with complexity $O(1)$ is called:**
- ( ) a) Linear Time
- ( ) b) Constant Time
- ( ) c) Exponential Time
- ( ) d) Logarithmic Time

**8. Which of the following complexities is the slowest (largest growth rate)?**
- ( ) a) $O(n!)$
- ( ) b) $O(2^n)$
- ( ) c) $O(n^3)$
- ( ) d) $O(n \log n)$

---

## Section 2: Sorting Algorithms

**9. Which of the following is a stable sorting algorithm?**
- ( ) a) Heap Sort
- ( ) b) Quick Sort
- ( ) c) Merge Sort
- ( ) d) Selection Sort

**10. What is the worst-case time complexity of Insertion Sort?**
- ( ) a) $O(n)$
- ( ) b) $O(n \log n)$
- ( ) c) $O(n^2)$
- ( ) d) $O(\log n)$

**11. Which sorting algorithm is the best choice for sorting a nearly sorted array?**
- ( ) a) Merge Sort
- ( ) b) Quick Sort
- ( ) c) Insertion Sort
- ( ) d) Selection Sort

**12. In Heap Sort, what is the time complexity of the `heapify` function?**
- ( ) a) $O(n)$
- ( ) b) $O(\log n)$
- ( ) c) $O(n \log n)$
- ( ) d) $O(1)$

**13. What is the space complexity of Merge Sort?**
- ( ) a) $O(1)$
- ( ) b) $O(\log n)$
- ( ) c) $O(n)$
- ( ) d) $O(n^2)$

**14. Bucket Sort works best when the input is:**
- ( ) a) All integers
- ( ) b) Uniformly distributed over a range
- ( ) c) Reverse sorted
- ( ) d) Containing negative numbers

**15. Which algorithm sorts by processing individual digits (LSD/MSD)?**
- ( ) a) Counting Sort
- ( ) b) Radix Sort
- ( ) c) Bucket Sort
- ( ) d) Quick Sort

**16. What is the worst-case complexity of Quick Sort?**
- ( ) a) $O(n)$
- ( ) b) $O(n \log n)$
- ( ) c) $O(n^2)$
- ( ) d) $O(n!)$

**17. Counting Sort is efficient only when:**
- ( ) a) The range of input $k$ is not significantly larger than $n$
- ( ) b) The input is floating point numbers
- ( ) c) The array is reverse sorted
- ( ) d) Memory is very limited

**18. Which sorting algorithm is NOT "In-Place"?**
- ( ) a) Insertion Sort
- ( ) b) Heap Sort
- ( ) c) Merge Sort
- ( ) d) Quick Sort

**19. What is the minimum number of comparisons required to find the maximum in an array of size $n$?**
- ( ) a) $\log n$
- ( ) b) $n-1$
- ( ) c) $n/2$
- ( ) d) $n$

**20. In Strassen’s Matrix Multiplication, how many sub-matrix multiplications are performed?**
- ( ) a) 8
- ( ) b) 7
- ( ) c) 4
- ( ) d) 9

---

## Section 3: Graph Algorithms

**21. Which data structure is used to implement Breadth First Search (BFS)?**
- ( ) a) Stack
- ( ) b) Priority Queue
- ( ) c) Queue
- ( ) d) Hash Map

**22. Which data structure is implicitly used in Depth First Search (DFS)?**
- ( ) a) Queue
- ( ) b) Stack
- ( ) c) Heap
- ( ) d) Tree

**23. Dijkstra’s Algorithm is based on which paradigm?**
- ( ) a) Divide and Conquer
- ( ) b) Dynamic Programming
- ( ) c) Greedy
- ( ) d) Backtracking

**24. What is the time complexity of Prim’s Algorithm using an Adjacency Matrix?**
- ( ) a) $O(V)$
- ( ) b) $O(V^2)$
- ( ) c) $O(E \log V)$
- ( ) d) $O(V+E)$

**25. Why does Dijkstra’s algorithm fail for graphs with negative weight edges?**
- ( ) a) It gets stuck in an infinite loop
- ( ) b) It cannot handle cycles
- ( ) c) The greedy choice property fails once nodes are visited
- ( ) d) It uses too much memory

**26. Which algorithm is best for finding the Minimum Spanning Tree (MST)?**
- ( ) a) BFS
- ( ) b) Strassen’s
- ( ) c) Prim’s
- ( ) d) Floyd-Warshall

**27. What is the Space Complexity of representing a graph using an Adjacency Matrix?**
- ( ) a) $O(V)$
- ( ) b) $O(E)$
- ( ) c) $O(V^2)$
- ( ) d) $O(V+E)$

**28. To detect a cycle in a graph, which traversal is most commonly used?**
- ( ) a) BFS
- ( ) b) DFS
- ( ) c) Dijkstra
- ( ) d) Prim

**29. The operation used in Dijkstra’s to update the shortest distance is called:**
- ( ) a) Heapify
- ( ) b) Partition
- ( ) c) Relaxation
- ( ) d) Memoization

**30. Which graph traversal finds the shortest path in an unweighted graph?**
- ( ) a) DFS
- ( ) b) BFS
- ( ) c) Prim’s
- ( ) d) Kruskal’s

---

## Section 4: Advanced Design Techniques (DP, Greedy)

**31. The 0/1 Knapsack problem is solved using:**
- ( ) a) Greedy Method
- ( ) b) Divide and Conquer
- ( ) c) Dynamic Programming
- ( ) d) Branch and Bound

**32. The Fractional Knapsack problem is solved using:**
- ( ) a) Greedy Method
- ( ) b) Dynamic Programming
- ( ) c) Backtracking
- ( ) d) Divide and Conquer

**33. In Weighted Interval Scheduling, jobs are sorted based on:**
- ( ) a) Start Time
- ( ) b) Finish Time
- ( ) c) Profit
- ( ) d) Duration

**34. The complexity of the 0/1 Knapsack problem is:**
- ( ) a) $O(n^2)$
- ( ) b) $O(2^n)$
- ( ) c) $O(nW)$
- ( ) d) $O(n \log n)$

**35. What defines a Dynamic Programming problem?**
- ( ) a) Greedy Choice Property
- ( ) b) Overlapping Subproblems & Optimal Substructure
- ( ) c) Disjoint Subproblems
- ( ) d) Local Optimization

**36. "Memoization" is also known as:**
- ( ) a) Bottom-Up approach
- ( ) b) Top-Down approach
- ( ) c) Divide and Conquer
- ( ) d) Greedy approach

**37. Which of the following is NOT a Greedy Algorithm?**
- ( ) a) Prim’s Algorithm
- ( ) b) Kruskal’s Algorithm
- ( ) c) Dijkstra’s Algorithm
- ( ) d) Floyd-Warshall Algorithm

**38. The recurrence relation for Strassen’s Matrix Multiplication is:**
- ( ) a) $T(n) = 8T(n/2) + O(n^2)$
- ( ) b) $T(n) = 7T(n/2) + O(n^2)$
- ( ) c) $T(n) = 2T(n/2) + O(n)$
- ( ) d) $T(n) = 4T(n/2) + O(n)$

**39. In Weighted Interval Scheduling, if all weights are 1, the problem becomes:**
- ( ) a) Activity Selection Problem
- ( ) b) Knapsack Problem
- ( ) c) Vertex Cover
- ( ) d) Traveling Salesman

**40. $O(nW)$ for Knapsack is called:**
- ( ) a) Polynomial Time
- ( ) b) Linear Time
- ( ) c) Pseudo-Polynomial Time
- ( ) d) Exponential Time

---

## Section 5: Conceptual & Mixed

**41. Which of these algorithms is useful for checking if a graph is connected?**
- ( ) a) Merge Sort
- ( ) b) BFS/DFS
- ( ) c) Radix Sort
- ( ) d) Binary Search

**42. The pivot element is a specific feature of which sorting algorithm?**
- ( ) a) Merge Sort
- ( ) b) Heap Sort
- ( ) c) Quick Sort
- ( ) d) Insertion Sort

**43. If a graph is disconnected, Prim’s algorithm will:**
- ( ) a) Fail to terminate
- ( ) b) Only find the MST of the starting component
- ( ) c) Find the MST of the whole graph automatically
- ( ) d) Return an error

**44. What is the time complexity of building a heap from an array of $n$ elements?**
- ( ) a) $O(n)$
- ( ) b) $O(n \log n)$
- ( ) c) $O(\log n)$
- ( ) d) $O(n^2)$

**45. Which of the following is true for Strassen’s Algorithm?**
- ( ) a) It uses more additions than standard multiplication
- ( ) b) It uses fewer additions than standard multiplication
- ( ) c) It is always faster than standard multiplication
- ( ) d) It has a complexity of $O(n^3)$

**46. What does the "Cut Property" help justify?**
- ( ) a) Why Quick Sort works
- ( ) b) Correctness of Greedy MST algorithms
- ( ) c) Stability of Merge Sort
- ( ) d) Efficiency of Hash Tables

**47. If $f(n) = 3n^2 + 10n$, then $f(n)$ is:**
- ( ) a) $O(n)$
- ( ) b) $\Omega(n^3)$
- ( ) c) $\Theta(n^2)$
- ( ) d) $O(\log n)$

**48. Which algorithm uses the idea of "Relaxation"?**
- ( ) a) Merge Sort
- ( ) b) Dijkstra's Algorithm
- ( ) c) BFS
- ( ) d) DFS

**49. An algorithm that calls itself is known as:**
- ( ) a) Iterative
- ( ) b) Recursive
- ( ) c) Dynamic
- ( ) d) Greedy

**50. What is the value of `K[0][w]` in the Knapsack DP table?**
- ( ) a) $\infty$
- ( ) b) $w$
- ( ) c) $0$
- ( ) d) $n$

---
---

# 🔑 Answer Key

| Q | Ans | Q | Ans | Q | Ans | Q | Ans | Q | Ans |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **1** | c | **11** | c | **21** | c | **31** | c | **41** | b |
| **2** | c | **12** | b | **22** | b | **32** | a | **42** | c |
| **3** | c | **13** | c | **23** | c | **33** | b | **43** | b |
| **4** | b | **14** | b | **24** | b | **34** | c | **44** | a |
| **5** | c | **15** | b | **25** | c | **35** | b | **45** | a |
| **6** | c | **16** | c | **26** | c | **36** | b | **46** | b |
| **7** | b | **17** | a | **27** | c | **37** | d | **47** | c |
| **8** | a | **18** | c | **28** | b | **38** | b | **48** | b |
| **9** | c | **19** | b | **29** | c | **39** | a | **49** | b |
| **10** | c | **20** | b | **30** | b | **40** | c | **50** | c |
