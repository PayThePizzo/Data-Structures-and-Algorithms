//
// Created by PayThePizzo on 3/30/2022.
//

#include "first_assignment.h"
#include <vector>

using namespace std;

int max_lev(std::vector<int> my_vector){
    int max = -1;

    for(int x : my_vector){
        if(x>max){
            max = x;
        }
    }

    return max;
}
// T(n) = Θ(n)
//
// We pass through the whole list once.

int tot_siblings(PNodeG r){
    int siblings = 1;

    while(r){
        siblings++;
        r=r->right_sib;
    }

    return siblings;
}
// T(n) = Θ(n)
//
// We pass through the siblings once.

//TODO: initialize vector
int larghezza_aux(PNodeG r, std::vector<int>& my_vector, int h){
    if(r){
        if(r->left_child && r->right_sib){          //Both
            my_vector[h] += tot_siblings(r) ;
            my_vector[h+1] += larghezza(r->left_child);

        }
        else if(r->left_child && !r->right_sib){   //Only Child, 1+ Children
            my_vector[h] += 1;
            my_vector[h] += larghezza(r->left_child);
        }
        else if(!r->left_child && r->right_sib){   //No Children, 1+ Siblings
            my_vector[h] += tot_siblings(r);
        }
        else if(!r->left_child && !r->right_sib){   //leaf node
            my_vector[h] += 1;
        }
    }

    return 0;
}

int larghezza(PNodeG r){
    std::vector<int> my_vector;
    my_vector.reserve(10);

    larghezza_aux(r, my_vector[0], 0);

    return max_lev(my_vector);
}

// Every time you go down