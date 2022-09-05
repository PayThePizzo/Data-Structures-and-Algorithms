//
// Created by PayThePizzo on 9/5/2022.
//

#include "iostream"
#include "cmath"
#include "stdlib.h"
#include "queue"
#include "vector"
#include <bits/stdc++.h>>

using namespace std;

int scarto(int arr[], int n){

}

int weight(int u, int v){
    return abs(u-v);
}

/**
 * Returns binomial coefficient
 *
 * @param n
 * @param k
 * @return
 */
int binom(int n, int k) {
    int C[k + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}


struct list{
    int key;
    list *predecessor;
};

/**
 * Returns the sum of minimum absolute differences between each couple arr_v[i], arr_v[j] such that
 * i != j, and that the sum is the minimum out of all permutations
 *
 * @param arr_v is an array[0..n-1] of positive integers, it is like an acyclic connected graph
 * @param n is an even integer
 * @param weight_foo function that returns absolute difference between x and y
 * @return integer representing the minimum
 */
int scarto_pos(std::vector<int> arr_g, int n){
    if(n>2){
        // Compute all weights #w = binom(n,2);
        // w(i,j) = abs(arr[i]-arr[j]), i!=j
        std::priority_queue<int, std::vector<int>, greater<int>> minQ;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j<n; j++){
               minQ.push(abs(arr_g[i]-arr_g[j]));
            }
        }


        // #values to consider = binom(n, 2)
        // if we consider w(i,j), we cannot consider i or j again
        // #values composing the sum = n/2
        std::vector<int>
        std::priority_queue<int, std::vector<int>, greater<int>> minQ(arr_v.begin(), arr_v.end());

    }else if(n==2){
        return abs(arr_g[n-1]-arr_g[n-2]);
    }
    return 0;
}


int ineff_scarto(int arr[], int n){
    // n x n matrix representing the connected, acyclic graph
    // each a[i,j] is the w((u,v)) = abs (u.k - v.k)
    // the degree of each vertex is |V|-1
    //n^2
    int weights[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            if(i==j){
                weights[i][j] = -1;
            }else{
                weights[i][j]= abs(arr_g[i]-arr_g[j]);
                weights[j][i] = -1;
            }
        }
    }





}