# 3n Sort of Schnorr and Shamir


The 3n Sort of Schnorr and Shamir is an algorithm for sorting on a two-dimensional arrays.
The 3n sort decomposes the two-dimensional array into vertical slices, horizontal slices, and blocks.
It uses the unshuffle operation, a permutation that corresponds to dealing $n$ cards to $k$ players, to sort the elements.


## Computational Cost

The computational costs of 3n sort of Schnorr and Shamir are:
- $T{\left(n \times n\right)} = 3 n + 22 n^{\frac{3}{4}} - 18$ the number of steps;
- $C{\left(n \times n\right)} = n^3 + \frac{25}{2} n^{\frac{11}{4}} - \frac{9}{2} n^2 \log_2{n} - 13 n^2$ the number of comparators;
