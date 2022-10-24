//
// Created by PayThePizzo on 3/30/2022.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <limits>

using namespace std;



bool unione(vector<pair<int, int>>& arr, pair<int, int>& ris){
    int min = INT_MAX;
    int max = INT_MIN;

    for(pair<int,int> p : arr){
        if( (p.first<=p.second) &&
            (arr.size()>=p.first>=1)){
            if(min>p.first){
                min = p.first;
            }
            if(max<p.second){
                max = p.second;
            }

        }else{
            return false;
        }
    }

    ris.first = min;
    ris.second = max;

    cout << ris.first <<  " ";
    cout << ris.second << endl;

    return true;
}

int main(){

    vector<pair<int, int>> arr;
    arr.push_back({1, 2});
    arr.push_back({3, 4});


    pair<int, int> ris;
    ris.first = 0;
    ris.second = 0;

    unione(arr, ris);


    return 0;
}