
#include <iostream>

// Dynamic Programming Fibonacci!
// n<=0 -> 0
// n==1 -> 1
// n>1 --> n-1 + n-2

/**
 * Naive implementation of Fibonacci's formula with T(n)= O(n^2)
 *
 * @param n
 * @return
 */
int fib_rec(int n){
    if(n<=0){
        return 0;
    }else if (n<=1){
        return 1;
    }
    return fib_greedy(n-1)+ fib_greedy(n-2);
}

/* Dynamic Programming
 *
 * 1) Characterize the structure of an optimal solution.
 *
 * 2) Recursively define the value of an optimal solution.
 *      Fib(n) =
 *              Fib[n-1] + Fib[n-2],    if n>=3
 *              F[n],                   else.
 *
 * 3) Compute the value of an optimal solution, typically in a bottom-up fashion.
 *      TD: We can start from fib(n). If it is already in Fib[n] we return it, else we split recursively the
 *      subproblems fib(n-1), fib(n-2) and saved them in Fib[n-1], Fib[n-2] respectively.
 *
 *      BU: We can start from the base cases (smallest) and climb our way up the final solution, while saving our computations
 *      in Fib[]
 *
 * 4) Construct an optimal solution from computed information
 */

int fib_td_aux(int n, int *ptr){
    if(*(ptr+n)<=-1){
        *(ptr+n) = fib_td_aux(n-1, ptr)+ fib_td_aux(n-2, ptr);
    }
    return *(ptr+n);
}

/**
 * Fibonacci Dynamic Programming Top Down Solution with T(n) = O(2n), S(n) = Theta(n)
 *
 * @param n
 * @return
 */
int fib_td(int n) {
    // Array initialization with base cases
    int Fib[n];
    Fib[0] = 0, Fib[1] = 1;
    for (int i = 2; i <= n; i++)
        Fib[i] = -1;

    // Return the answer if is present or compute it and save it;
    return fib_td_aux(n, &Fib[0]);
}

/**
 * Fibonacci Dynamic Programming Bottom Up Solution with T(n) = Theta(n), S(n) = Theta(n)
 *
 * @param n
 * @return
 */
int fib_bu(int n){
    int Fib[n];
    Fib[0] = 0, Fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        Fib[i] = Fib[i-1] + Fib[i-2];
    }

    return Fib[n];
}

int fib_optimized(int n){
    int result = 1, fib1 = 1 , fib2 = 1;
    for(int i = 3; i<=n; i++){
        result = fib1 + fib2;
        fib1 = fib2;
        fib2 = result;
    }
    return result;
}


int main(){
    std::cout << fib_td(5) << std::endl;
    return 0;
}