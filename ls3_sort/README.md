# LS3 Sort


The LS3 Sort is a very simple algorithm for sorting on a two-dimensional arrays.
The algorithm is based on a merge algorithm that merges $4$ sorted $\frac{k}{2} \times \frac{k}{2}$-arrays to one sorted $k \times k$-array. 
The sorting direction is the snake. 
The merge algorithm use of the basic operations shuffle and oets.


## Computational Cost

The computational cost of LS3 sort is $\mathcal{O}{\left(n\right)}$.
More precisely: the merge procedures require ${4.5 n}$ comparators. 
So totally we have $4.5 {\left(n + \frac{n}{2} + \frac{n}{4} + \ldots + 2\right)} \leq {9 n}$ comparators.