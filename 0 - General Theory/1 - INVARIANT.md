# Invariant

It is an assertion which is TRUE **before, after and during** any iteration of a cycle

## Goal
It is needed to demonstrate:
* A property 
* Capture the semantics of a while
* The correctness of a function

It can be as simple as a formula but it must have 3 properties:
1. Initialization
2. Preservation
3. Conclusion

### Initialization - 1
The assertion must be TRUE before the first iteration of the cycle.

### Preservation - 2
If it is true before a particular iteration, it must be true before the following one too.

### Conclusion - 3 
When the iteration stops, the invariant must be true.

