# Shearsort


The Shearsort is a very simple algorithm for sorting two-dimensional arrays.
The shearsort sorts the rows and the columns of the array in turn.


## Computational Cost

The computational cost of shearsort is $\Theta{\left(n \log{n}\right)}$.
More precisely: it requires $n \log{n}$ steps for row sorting plus $n$ steps for the additional row sorting operation.
In each iteration, the height of the unsorted zone decreases by a factor of 2. 
This means that the columns contain an unsorted zone of decreasing length.
Therefore, the algorithm requires $n + \frac{n}{2} + \frac{n}{4} + \ldots + 2 = {2 n} - 2$ steps for column sorting.
Altogether, shearsort has a computational cost of $n {\left(\log{\left(n\right)} + 3\right)} - 2$ steps.
