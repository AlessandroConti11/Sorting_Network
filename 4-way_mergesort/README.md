# 4-Way Mergesort


The 4-Way Mergesort is an algorithm for sorting on a two-dimensional arrays.
The 4-way mergesort is a sorting network that divides the input sequence into four subsequences rather than two as in the traditional mergesort. 
It uses multiple merge operations in parallel, leading to a potentially faster sorting process.


## Computational Cost

The computational costs of 4-way mergesort are:
- $T{\left(n \times n\right)} = 7 n - 6$ the number of steps;
- $C{\left(n \times n\right)} = 4 n^3 - 2 n^2 \log_2{n} - 4 n^2$ the number of comparators;
