# Bitonic Sort


The Bitonic Sort is a parallel sorting network that works by transforming a sequence into a bitonic sequence, a sequence that first increases and then decreases. 
The sequence is then sorted by recursively applying a bitonic merge operation.


## Computational Cost

The computational cost of bitonic sort is $\mathcal{O}{\left(n \log^2{n}\right)}$.
More precisely: the number of comparator stages of the entire sorting network is $T{\left(n\right)} = \log{n} + T{\left(\frac{n}{2}\right)} = \log{n} \frac{\log{\left(n\right)} + 1}{2}$.
Each stage of the sorting network consist of $\frac{n}{2}$ comparators, so totally we have $\frac{n}{2} \log{n} \frac{\log{\left(n\right)} + 1}{2}$ comparators.