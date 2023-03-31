//
// Created by PayThePizzo on 3/31/2023.
//

#include "iostream"
#include "vector"

using namespace std;

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
    for(int i = 0; i<=n; i++){
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



int main()
{
    vector<int> p = {0, 1,112,9,6,7,10, 18, 42, 55, 10};
    int n = 3;

    int max = BU_CR(p, n);
    cout << "" << max << "\n";

    Print_CR_BU_CR2(p, 3);


    return 0;
}
