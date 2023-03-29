# Hash Functions

A hash function is any function that **can be used to map data of arbitrary size to fixed-size values**.

Values returned by a hash function are called _hash values, hash codes, digests_, or simply _hashes_. 
The values are usually used to index a fixed-size table called a hash table. 

Use of a hash function to index a hash table is called _hashing_ or scatter storage addressing.[1]

We will face the properties and the logic between hash functions.

---

## Properties we covered


### Uniformity

A good hash function should map the expected inputs as evenly as possible over its output range.

That is, every hash value in the output range should be generated with roughly the same probability!

If a typical set of $m$ records is hashed to $n$ table slots, the probability of a bucket receiving many 
more than $m/n$ records should be vanishingly small. In particular, if $m$ is less than $n$, 
very few buckets should have more than one or two records. 
A small number of collisions is virtually inevitable, even if $n$ is much larger than $m$. [2]


### SUHA - Simple Uniform Hashing Assumption

It is a basic assumption that facilitates the mathematical analysis of hash tables.
* This assumption generalizes the details of the hash function and allows for certain assumptions
about the stochastic system.

The assumption states that a hypothetical hashing function will evenly distribute items into the slots of a 
hash table. Moreover, each item to be hashed has an equal probability of being placed into a slot, 
regardless of the other elements already placed. 

This means the assumption of uniform hashing, given a hash function $h$, and a hash table of size $m$, 
the probability that two non-equal elements will hash to the same slot is: $P[h(a) = h(b)] = 1/m$ [3]

---

## How do we hash? - Closed Addressing

Let's consider a lucky case:
* There are $k$ real numbers which represent the keys and hash table of size $m$. 
These keys are randomly and uniformly distributed (like i.i.d. random variables) inside the interval $0 \leq k \leq 1$
* The hash function $h(k) = \lfloor k * m \rfloor$ satisfies the SUHA.

Usually, hash functions assume the keys are natural numbers belonging to *N*. When
they are not natural numbers we need to interpret them as numbers (i.e. char to int)

$$h(k) = \lfloor k \cdot m \rfloor$$

Example: for a string "CLRS", we encode it through the ASCII values (128 total values):
* $C=67$
* $L=76$
* $R=82$
* $S=83$

The resulting positional notation would be:

$$CLRS \rightarrow 67 \cdot 128^{3} + 76 \cdot 128^{2} + 82 \cdot 128^{1} + 83  \cdot 128^{0} = 141764947$$


### Division Hashing

$$h(k) = k \text{ mod } m \in \lbrace 0 \ldots m-1 \rbrace$$

A standard technique is to use a modulo function on the key, by selecting a divisor $m$: a **prime** number close to 
the table size (which is usually a power of 2), and that is not close to a power of 2 or 10

Pros: 
* It is easy to analyze
* This technique works well in practice because many key sets are sufficiently random already, a
and the probability that a key set will be cyclical by a large prime number is small.

Cons: 
* One drawback is that it won't break up clustered keys. 
  * For example, the keys 123000, 456000, 789000, etc. modulo 1000 all map to the same address.
* We need to choose carefully $m$ 
  * **Avoid choosing** $m$ as a power of $2$, $m \neq 2^{p} \wedge p \in \mathbb{R}$
    * The result would be considering just a portion of the key
    * It is best for the hash function to depend on all the bits of the key
  * If $k$ is a string, interpreted on the base $2^{p}$, it is a bad idea to choose $m = (2^{p})-1$
    * The permutation of the characters in $k$ does not change the value of the hash function
    * $h(amor) = h(roma)$


### Multiplicative Hashing

$$h(k) = \lfloor m \cdot (kA \text{ mod } 1) \rfloor =  \lfloor 2^{p} \cdot (kA \text{ mod } 1) \rfloor  $$

Given an integer key $k$ belonging to $U$, and a hash function $h(k) = mk$, we transform it in a real number in $[0,1)$
* We get a constant $A$ such that $0 < A < 1$
* We calculate $k \cdot A$
* We extract the fractional part $k \cdot A \text{ mod } 1 = kA - \lfloor kA \rfloor  \in [0,1)$

Pros:
* $m$ is not a critical value anymore, it works well with any value $A$ can take
  * Typically $m$ is a power of $2$, $m \neq 2^{p} \wedge p \in \mathbb{R}$
* Knuth saw that it works well with $A = \frac{\sqrt{5}-1}{2} \approx 0.6180$

To simplify the computing of the function
* $w$: the length of a memory word
* $k$, must be of the length of memory word
* $q$, is an arbitrary integer that must be in $0 < q < 2^{w}$
* $m$, must be $m = 2^{p}$
  * $p = h(k)$
* $A$, a constant, must be $A = q/(2^{w}) \Rightarrow q = A2^{w}$

Now
1. $kA = k \frac{q}{2^{w}}$
2. Since $kq = r_{1}2^{w} + r_{0}$
   1. Where $r_{0}$ is the fractional part
3. We get that  
   1. $r_{1} = \lfloor \frac{kq}{2^{w}} \rfloor = \lfloor kA \rfloor$
   2. $r_{0} = \frac{kq}{2^{w}} \text{ mod } 1 = kA \text{ mod } 1$
      1.  The less significant part of the word created by $kq$

![multiplicativehashing](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/multiplicativehashing.png?raw=TRUE)

So, this justifies $h(k) = \lfloor m \cdot (kA \text{ mod } 1) \rfloor =  \lfloor 2^{p} \cdot (kA \text{ mod } 1) \rfloor  $
* Our hash function returns, indeed, the p-bits more significant of the less significant part of
the product between $kq$ 
* It means we take the p-bits significant bits of $r_{0}$

The problem is, if we receive many keys mapped to the same cell, our performances heavily drop.
* It is the case with $n$ keys where $h(k_{1}) = h(k_{2}) = \ldots = h(k_{n})$

We can avoid this through universal hashing


### Universal Hashing 
Universal Hashing refers to **selecting a hash function at _random_ from a family of hash functions** with a certain 
mathematical property.

This guarantees a low number of collisions in expectation, even if the data is chosen by an adversary.[4]

---

## How do we hash? - Open Addressing

Since all the possible elements are in the table, the table must be as large as $n$ at most, $S(n) = \mathcal{O}(n)$.
However, this does not mean the table is always full, nor that the elements are in some kind of order, beside the one
dictated by the hash function and the solutions of possible collisions.

For this reason when probing we **always start from** the index $i = 0$ and in the worst case we might need to examine
the whole table, which might require $T(n) = \Theta(n)$ if there is a way to keep track of the cells previously
visited.

To determine which slots to probe, we extend the hash function to include the **probe number** (starting from 0)
as a second input. 

To sum up, the hash function takes into account the key being inserted $k \in U$ and the order of inspection 
$i \in \lbrace 0, 1, \ldots , m-1 \rbrace$. It then returns an index $j \in T \Rightarrow i \in 0, 1, \ldots , m-1$

$$h: U \times \lbrace 0, 1, \ldots , m-1  \rbrace \rightarrow \lbrace 0, 1, \ldots , m-1  \rbrace $$

With open addressing, we require that for every key $k \in U$, the probe/inspection sequence:

$$\langle h(k, 0), h(k, 1), \ldots, h(k, m-1) \rangle$$

be a permutation of all the hash-table's indexes $\langle 0, 1, \ldots, m-1 \rangle $ so that every hash-table 
position is eventually considered as a possible slot for a new key as the table fills up. If this is respected,
the table is being used exhaustively.

> So $h(k,i)$ represents the position of the key $k$ after $i$ failed inspections.


### Probe
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
![Linear Probe](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/linearprobe.png?raw=TRUE)

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

![doublehash](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/doublehash.jpg?raw=TRUE)

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