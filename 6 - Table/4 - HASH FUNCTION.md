# Hash Functions

A hash function is any function that **can be used to map data of arbitrary size to fixed-size values**.

Values returned by a hash function are called _hash values, hash codes, digests_, or simply _hashes_. 
The values are usually used to index a fixed-size table called a hash table. 

Use of a hash function to index a hash table is called _hashing_ or scatter storage addressing.[1]

---
## Uniformity

A good hash function should map the expected inputs as evenly as possible over its output range.

That is, every hash value in the output range should be generated with roughly the <mark>same probability!</mark>

if a typical set of m records is hashed to n table slots, the probability of a bucket receiving many 
more than m/n records should be vanishingly small. In particular, if m is less than n, 
very few buckets should have more than one or two records. 
A small number of collisions is virtually inevitable, even if n is much larger than m. [2]


---

## SUHA - Simple Uniform Hashing Assumption

It is a basic assumption that facilitates the mathematical analysis of hash tables.
* This assumption generalizes the details of the hash function and allows for certain assumptions
about the stochastic system.

The assumption states that a hypothetical hashing function will evenly distribute items into the slots of a 
hash table. Moreover, <mark>each item to be hashed has an equal probability of being placed into a slot, 
regardless of the other elements already placed</mark>. 

This means the assumption of uniform hashing, given a hash function h, and a hash table of size m, 
the probability that two non-equal elements will hash to the same slot is: `P[h(a) = h(b)] = 1/m` [3]


---

## How do we hash?

Let's consider a lucky case:
* There are k real numbers which represent the keys and hash table of size m. 
These keys are randomly and uniformly distributed (like i.i.d. random variables) inside the interval `0 <= k < 1`
* The hash function **h(k) = ⌊k * m⌋** satisfies the SUHA.

Usually, hash functions assume the keys are natural numbers belonging to *N*. When
they are not natural numbers we need to interpret them as numbers (i.e. char to int)

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
  * Avoid choosing M as a power of 2, `m != 2**p` with p a real number
  * If k is a string, interpreted on the base 2**p, it is a bad idea to choose `m = (2**p)-1`


--- 

### Extra Credits
* [1] [Wikipedia - Hash Function](https://en.wikipedia.org/wiki/Hash_function)
* [2] [Wikipedia - Hash Function/Properties](https://en.wikipedia.org/wiki/Hash_function#Properties)
* [3] [Wikipedia - SUHA](https://en.wikipedia.org/wiki/SUHA_(computer_science))