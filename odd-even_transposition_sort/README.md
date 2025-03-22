# Odd-Even Transposition Sort


The Odd-Even Transposition Sort for *n* input data consists of *n* comparators stages. 
In each stage, either all inputs at odd index positions or all inputs at even index positions are compared with their neighbours.
The network performs an iteration where in the first pass, it compares elements at odd-indexed positions with their neighbors, and in the next pass, compares even-indexed elements.

The odd-even transposition sort is an elementary sorting network biased on the bubble-sort technique, which compares every two consecutive numbers in the array and swap them if first is greater than the second to get an ascending order array.


## Computational Cost

The computational cost of odd-even transposition sort is $\mathcal{O}{\left(n\right)}$, more precisely requires $n \frac{n - 1}{2}$ comparators.