//
// Created by PayThePizzo on 3/31/2023.
//

#include "iostream"
#include "vector"

using namespace std;

int Naive_Cut_Rod(vector<int> p, int n) {
    if (n == 0) {
        return 0;
    }else{
        int q = -1;
        for(int i = 0; i<n; i++) {
            q = max(q, p[i] + Naive_Cut_Rod(p, n - i));
        }
        return q;
    }
}

int main()
{
    vector<int> p = {1,3,9,6,7,10, 15};
    int q = Naive_Cut_Rod(p, 6);
    cout << "" << q;

    return 0;
}
