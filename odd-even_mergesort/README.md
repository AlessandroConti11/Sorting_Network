# Odd-Even Mergesort


The Odd-Even Mergesort algorithm is based on a merge algorithm that merges two sorted halves of a sequence to a completely sorted sequence.

It is a parallel version of the traditional mergesort algorithm. 
It divides the input sequence into smaller subsequences and then recursively merges them in parallel. 
The merging process is done in an odd-even manner, meaning it alternates between comparing elements at odd and even indices.


## Computational Cost

The computational cost for odd-even mergesort is $\mathcal{O}{\left(n \log^2{n}\right)}$. 
More precisely: we have $T{\left(n > 2\right)} = {2 T{\left(\frac{n}{2}\right)}} + \frac{n}{2} - 1$, $T{\left(2\right)} = 1$, so $T{\left(n\right)} = \frac{n}{2} {\left(\log{\left(n\right)} - 1\right)} + 1$ merge comparison.
This means that overall we have $\log{n} {\left(\frac{n}{2} {\left(\log{\left(n\right)} - 1\right)} + 1\right)}$ comparators.