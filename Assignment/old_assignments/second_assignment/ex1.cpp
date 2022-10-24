//
// Created by PayThePizzo on 4/14/2022.
//

#include "second_assignment.h"
#include <math.h>
#include <vector>
#include <limits>

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

    return true;
}

