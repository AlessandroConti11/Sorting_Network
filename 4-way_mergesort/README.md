# 4-Way Mergesort


The 4-Way Mergesort is an algorithm for sorting on a two-dimensional arrays.
The 4-way mergesort is a sorting network that divides the input sequence into four subsequences rather than two as in the traditional mergesort. 
It uses multiple merge operations in parallel, leading to a potentially faster sorting process.


## Computational Cost

The computational cost of 4-way mergesort is $\mathcal{O}{\left(n\right)}$.
More precisely: the merge procedures require ${3 n}$ comparators.
The recursive execution of 4-way merge in roughsort takes ${3 n} + {3 \frac{n}{2}} + {3 \frac{n}{4}} + \ldots + 3 \leq {6 n}$ comparators.
Thus, including $n$ steps for the subsequent sorting of the rows 4-way mergesort has a computational cost $\leq {7 n}$ comparators. 
