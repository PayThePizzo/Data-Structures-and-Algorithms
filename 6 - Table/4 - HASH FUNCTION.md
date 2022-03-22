# Hash Functions

A hash function is any function that **can be used to map data of arbitrary size to fixed-size values**.

Values returned by a hash function are called _hash values, hash codes, digests_, or simply _hashes_. 
The values are usually used to index a fixed-size table called a hash table. 

Use of a hash function to index a hash table is called _hashing_ or scatter storage addressing.[1]

We will face the properties and the logic between hash functions.

---
## Properties

### Uniformity

A good hash function should map the expected inputs as evenly as possible over its output range.

That is, every hash value in the output range should be generated with roughly the <mark>same probability!</mark>

If a typical set of m records is hashed to n table slots, the probability of a bucket receiving many 
more than m/n records should be vanishingly small. In particular, if m is less than n, 
very few buckets should have more than one or two records. 
A small number of collisions is virtually inevitable, even if n is much larger than m. [2]


### SUHA - Simple Uniform Hashing Assumption

It is a basic assumption that facilitates the mathematical analysis of hash tables.
* This assumption generalizes the details of the hash function and allows for certain assumptions
about the stochastic system.

The assumption states that a hypothetical hashing function will evenly distribute items into the slots of a 
hash table. Moreover, <mark>each item to be hashed has an equal probability of being placed into a slot, 
regardless of the other elements already placed</mark>. 

This means the assumption of uniform hashing, given a hash function h, and a hash table of size m, 
the probability that two non-equal elements will hash to the same slot is: `P[h(a) = h(b)] = 1/m` [3]

---

## How do we hash? - Closed Addressing

Let's consider a lucky case:
* There are k real numbers which represent the keys and hash table of size m. 
These keys are randomly and uniformly distributed (like i.i.d. random variables) inside the interval `0 <= k < 1`
* The hash function **h(k) = ⌊k * m⌋** satisfies the SUHA.

Usually, hash functions assume the keys are natural numbers belonging to *N*. When
they are not natural numbers we need to interpret them as numbers (i.e. char to int)

Here we present some options of the many you can find.

### Division Hashing

A standard technique is to use a modulo function on the key, by selecting a divisor M: `h(K) = K mod M`
* M is a **prime** number close to the table size (which is usually a power of 2)
  * Not a number that is a power of 2 or 10, ex: 701

Pro: 
* It is easy to analyze
* This technique works well in practice because many key sets are sufficiently random already, a
and the probability that a key set will be cyclical by a large prime number is small.

Con: 
* One drawback is that it won't break up clustered keys. 
For example, the keys 123000, 456000, 789000, etc. modulo 1000 all map to the same address.
* We need to choose carefully M
  * Avoid choosing M as a power of 2, `M != 2**p` with p a real number
  * If k is a string, interpreted on the base 2**p, it is a bad idea to choose `M = (2**p)-1`


### Multiplicative Hashing

Another standard technique is using ⌊m * (k*A mod 1)⌋

This come from the idea of using `h(k) = m * k`, k belongs to [0,1)

Given an integer key belonging to U, we transform it in a number in this range [0,1)
* We get a constant A such that `0 < A < 1`
* We calculate `k*A`
* We extract the rest `k*A mod 1` in the range, which is equal to k*A - ⌊k*A⌋

Pros:
* M is not a critical value anymore
* Works well with any value A can take
* Knuth saw that it works well with `A = (sqrt(5)-1)/2`

To simplify the computing of the function
* **w**: the length of a memory word
* **k**, must be of the length of memory word
* **q**, must be `0 < q < 2**w`
* **m**, must be `m = 2**p`
* **A**, a constant,must be `q/(2**w)`

Now
1. `k*A = k * q/(2**w)`
2. Since `k*q = r1*(2**w) + r0`
3. We get that  
   1. `r1 = ⌊(k*q)/(2**w)⌋`
   2. `r2 = (k*q)/(2**w) mod 1`

![Calc HT](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/Resources/calcht.png?raw=TRUE)

This all means that `k * A` is r0, the less significant part of the word created by `k*q` 

So, this justifies `h(K) = ⌊m * (k*A mod 1)⌋` which is equal to `⌊(2**p) * (k*A mod 1)⌋` 
* Our hash function returns, indeed, <mark>the p-bits more significant of the less significant part of
the product between `k*q` </mark>
* It means we take the p-bits significant bits of r0

The problem is, if we receive many keys mapped to the same cell, our performances heavily drop.
* It is the case with n keys where `h(k1) = h(k2) = ... = h(kn)`

### Universal Hashing 
Universal Hashing refers to **selecting a hash function at _random_ from a family of hash functions** with a certain 
mathematical property.

This guarantees a low number of collisions in expectation, even if the data is chosen by an adversary.[4]

---
## How do we hash? - Open Addressing

### Open

The hash function is now different from the one we faced before
* Input: `U x {0,1,...,m-1}`
  * Key, chosen from *U* 
  * **Order of inspection**, a number in the interval `[0, m-1]` 
* Output: 
  * An **index** in the hash table, in the interval `[0, m-1]`

So `h(K,i)` <mark>represents the position of the key k after **i** failed inspections.</mark>
* We want that for every key `k`, the sequence of inspections <h(k, 0), h(k,1), ..., h(k,m-1)> must be a permutation of all the
hash table's indexes. This means we use our table exhaustively.
* The permutation must let every cell, be considered like a possible cell for an insertion of a key (using the tables' indexes)

---

## Probe
In our analysis, we assume **uniform hashing** at every iteration: the probe sequence of each key
is equally likely to be any of the _m!_ permutations of <0, 1, ..., m-1> of our hash table.
* h(k,0) distributes the keys uniformly on the *m* cells
* h(k,0) distributes the keys uniformly on the *m-1* cells

### Linear Probe

Given an auxiliary ordinary hash function `h'`: _U_ --> {0,1,..., m-1}

The method of linear probing uses the hash function: `h(k,i) = (h'(k) + i) mod m`

<mark>We cannot alter the order of the keys we want to insert</mark>, this completely
alters the outcome of the function.

Example:
![Linear Probe](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/Resources/linearprobe.png?raw=TRUE)

Pros: 
* Linear probing is easy to implement

Cons:
* There are only <mark>m distinct sequences of probe</mark> since the first cell probed determines the entire sequence of probes.
* It suffers from a problem known as **primary clustering**. 
  * Long runs of occupied slots **tend to get longer**, and the average search time increases.
  * Clusters arise because an empty slot preceded by `i` full slots gets filled next with probability `(i+1)/m`. 
  

### Quadratic Probe

Quadratic probing uses a hash function of the form: `h(k,i) = (h'(k) + (c1*i) + (c2*(i**2)) mod m`
* h' is an auxiliary hash function
* c1 and c2 are positive auxiliary constants such that `c1 != 0 && c2 != 0`
* i takes value in {0, 1,..., m-1}

Pros:
* Better performances than linear probe

Cons:
* _c1, c2 and m_ must not have arbitrary values.
  * `c1 = c2 = 1/2` and `m = (2**p)`.
* The first position determines the entire sequence, again the count of permutations is m and not *m!*
* It suffers from a problem known as **secondary clustering**.
  * Secondary clusters are generated when **two distinct keys** are mapped to the same cell. This means
  their **sequences turns out to be the same**.


### Double Hashing

Here we combine two hashing auxiliary functions: `h(k,i) = ((h1(k)*i) + h2(k)) mod m`

The initial probe goes to position T[h1(k)]; successive probe positions are offset
from previous positions by the amount h2(k), modulo m.

Thus, unlike the case of linear or quadratic probing, the probe sequence here depends in
two ways upon the key k, since the initial probe position, the offset, or both, may vary.

The value of h2(k) must be relatively prime to the hash-table size m for the entire
hash table to be searched

What is the role of these hash functions?
1. <mark>The first one determines the starting point
2. The second one the pace of probing</mark> (the distance between the keys)

![doublehash](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/Resources/doublehash.jpg?raw=TRUE)

How do we ensure this?
* A convenient way to ensure this condition is to let m be a power of 2 and to design h2 so
  that it always produces an odd number.
* Another way is to let m be prime and to design h2 so that it always
  returns a positive integer less than m.

Pros:
* Double hashing uses Theta(`m**2`) sequences of probing since every possible pair `(h1(k), h2(k))` produces a
distinct sequence of probing.
* We get closer to the uniform distribution

Cons:

---

### Extra Credits
* [1] [Wikipedia - Hash Function](https://en.wikipedia.org/wiki/Hash_function)
* [2] [Wikipedia - Hash Function/Properties](https://en.wikipedia.org/wiki/Hash_function#Properties)
* [3] [Wikipedia - SUHA](https://en.wikipedia.org/wiki/SUHA_(computer_science))
* [4] [Wikipedia - Universal Hashing](https://en.wikipedia.org/wiki/Universal_hashing)