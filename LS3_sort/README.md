# LS3 Sort


The LS3 Sort is a very simple algorithm for sorting on a two-dimensional arrays.
The algorithm is based on a merge algorithm that merges $4$ sorted $\frac{k}{2} \times \frac{k}{2}$-arrays to one sorted $k \times k$-array. 
The sorting direction is the snake. 
The merge algorithm use of the basic operations shuffle and oets.


## Computational Cost

The computational costs of LS3-sort are:
- $T{\left(n \times n\right)} = 9 n - 9$ the number of steps;
- $C{\left(n \times n\right)} = 4 n^3 -\frac{1}{2} n^2 \log_2{n} - 4 n^2$ the number of comparators;
