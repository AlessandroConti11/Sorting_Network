# Rotatesort


The rotatesort is an algorithm for sorting on a two-dimensional arrays.
The rotatesort is a sorting network based on cyclic rotations of a sequence.
It works by applying rotations to the sequence, ensuring that the elements are sorted by making systematic comparisons and rotations.
The rotatesort algorithm is based on three operations: balance, unblock and shear.


## Computational Cost

The computational costs of rotatesort are:
- $T{\left(n \times n\right)} = \num{10} n + 5 \sqrt{n} + 11$ the number of steps;
- $C{\left(n \times n\right)} = \frac{9}{2} n^3 + \frac{3}{2} n^{\frac{5}{2}} - \frac{9}{2} n^2 - \frac{3}{2} n^{\frac{3}{2}} + 19 n$ the number of comparators;