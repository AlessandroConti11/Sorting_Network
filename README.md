# Sorting_Network


Author: Alessandro Conti - [AlessandroConti11](https://github.com/AlessandroConti11)

License: [MIT license](LICENSE).


Tags: .


## Specification

In this repository you can find the implementation of some sorting networks. 

A **Sorting Network** is a comparator network that sorts all input sequences. 
Sorting networks are special cases of general sorting algorithms, since all comparisons are data-independent. 
This makes sorting network suitable for the implementation in hardware or in parallel processor arrays, sorting on two-dimensional processor arrays.

The implemented sorting networks are:
- [odd-even transposition sort](odd-even_transposition_sort/README.md)
- [odd-even mergesort](odd-even_mergesort/README.md)
- [bitonic sort](bitonic_sort/README.md)
- [adapted bitonic sort](adapted_bitonic_sort/README.md)
- [LS3 sort](ls3_sort/README.md)
- [4-way mergesort](4-way_mergesort/README.md)
- [rotatesort](rotatesort/README.md)
- [3n sort of Schnorr and Shamir](3n_sort_Schnorr_and_Shamir/README.md)
- [2D odd-even transposition sort](2D_odd-even_transposition_sort/README.md)
- [shearsort](shearsort/README.md).


## How to run




## Contribute

- If you find a security vulnerability, do NOT open an issue. Email [Alessandro Conti](mailto:ale.conti.1101@gmail.com) instead.
- If you find a bug or error or want to add some other function that is not implemented yet
    1. **FORK** the repo
    2. **CLONE** the project to your own machine
    3. **COMMIT** to your own branch
    4. **PUSH** your work back up to your fork
    5. submit a **PULL REQUEST** so that I can review your changes
  > NOTE: Be sure to merge the latest from "upstream" before making a pull request!

### Code Style

Each new function must be documented using the following style:
- *Short function description*: A brief description explaining what the function does.
- *@warning*: A section listing all the assumptions made by the function, such as the preconditions that the parameters must fulfil.
- *Blank line*: Add a blank line to separate the documentation sections.
- *@details*: A detailed section describing how the function works, explaining the algorithms and logic used.
- *Blank line*: Add a blank line to separate the documentation sections.
- *@param*: A list of the parameters required by the function, each accompanied by a brief description of its role and type.
- *@return*: A description of what the function returns, including the data type.

In general, any additional comments that might improve understanding of the code are welcome. 😃
