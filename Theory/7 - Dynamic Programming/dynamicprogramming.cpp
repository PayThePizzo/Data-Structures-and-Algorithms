//
// Created by PayThePizzo on 3/31/2023.
//

#include "iostream"
#include "vector"

using namespace std;

// Fibonacci


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
    return fib_rec(n-1)+ fib_rec(n-2);
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
 * Fibonacci Dynamic Programming Bottom Up Solution with T(n) = O(n), S(n) = Theta(n)
 *
 * @param n
 * @return
 */
int fib_bu(int n){
    if(n>0){
        int Fib[n];
        Fib[0] = 0, Fib[1] = 1;

        for (int i = 2; i <= n; i++) {
            Fib[i] = Fib[i-1] + Fib[i-2];
        }
        return Fib[n];
    }else{
        return 0;
    }
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


// Cut Rod Solutions

int Naive_CR(vector<int> p, int n) {
    if (n == 0) {
        return 0;
    }else{
        int q = -1;
        for(int i = 1; i<=n; i++) {
            q = max(q, p[i] + Naive_CR(p, n - i));
        }
        return q;
    }
}

int Memoized_CR_Aux(vector<int> p, vector<int> r, int j){
    if(r[j]<0){
        if(j==0){
            r[j]=0;
        }else{
            int q = -1;
            for(int i = 1; i<=j; i++){
                q = max(q, p[i]+ Memoized_CR_Aux(p, r, j-i));
            }
            r[j]=q;
        }
    }
    return r[j];
}

int Memoized_CR(vector<int> p, int n){
    vector<int> r;
    r.push_back(-1);
    for(int i = 0; i<n; i++){
        r.push_back(-1);
    }
    return Memoized_CR_Aux(p, r, n);
}

int BU_CR(vector<int> p, int n){
    vector<int> r;
    for(int k=0; k<=n; k++){
        r.push_back(-1);
    }
    r[0]=0;

    for(int j=1; j<=n;j++){
        int q=-1;
        for(int i=1; i<=j; i++){
            q = max(q, p[i]+r[j-i]);
        }
        r[j]=q;
    }
    return r[n];
}

std::pair<vector<int>, vector<int>> BU_CR2(vector<int> p, int n){
    vector<int> r;
    vector<int> s;
    for(int k=0; k<=n; k++){
        r.push_back(-1);
        s.push_back(-1);
    }
    r[0]=0;
    s[0]=0;
    for(int j=1; j<=n;j++){
        int q=-1;
        for(int i=1; i<=j; i++){
            if(q < p[i]+r[j-i]){
                q = p[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }
    std::pair<vector<int>, vector<int>> sol = {r,s};
    return sol;
}

void Print_CR_BU_CR2(vector<int>p, int n){
    std::pair<vector<int>, vector<int>> sol = BU_CR2(p, n);
    int tot = 0;
    while(n>0){
        tot+= sol.first[sol.second[n]];
        n-= sol.second[n];
    }
    cout << "" << tot;
}

// LCS Solutions



// Palindrome



int main()
{
    vector<int> p = {0, 1,112,9,6,7,10, 18, 42, 55, 10};
    int n = 3;

    int max = BU_CR(p, n);
    cout << "" << max << "\n";

    Print_CR_BU_CR2(p, 3);


    return 0;
}
