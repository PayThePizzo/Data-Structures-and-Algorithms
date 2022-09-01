//
// Created by PayThePizzo on 9/1/2022.
//

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

// Data Structure
struct Node{
    int key;
    Node *left;
    Node *right;
};

// Quick sort
// TODO: FIX - 1
void swap(int *elem1, int *elem2){
    int temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

int partition(int *Arr, int p, int r){
    int x = Arr[r], i = p-1;
    for(int j = p; j<=r-1; j++){
        if(Arr[j]<=x){
            i++;
            swap(&Arr[i], &Arr[j]);
        }
        swap(&Arr[i+1], &Arr[r]);
    }
    return i+1;
}

void quick_sort(int* Arr, int p, int r){
    if(p<r){
        int q = partition(&Arr[0], p, r);
        quick_sort(&Arr[0], p, q-1);
        quick_sort(&Arr[0], q+1, r);
    }
}

// Print
void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "L__" );

        // print the value of the node
        std::cout << node->key << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);
}

// Build_BST
//TODO: Fix - 2

void tree_insert(Node *root, Node x){

}

Node* build_BST(int Arr[]){
    quick_sort(&Arr[0], 0, sizeof(Arr));
    if(sizeof(Arr)>0){
        Node* root;
        root->key = Arr[0];
        root->left = nullptr;
        root->right = nullptr;
        int i;

        while(i<sizeof(Arr)){
            if(Arr[i]>=root->key){
                Node *right;
                Node
                root->left = left;
            }else if (Arr[i]){
                Node *left;
                Node
                root->left = left;
            }
        }

        for(int i = 0; i<sizeof(Arr); i++){
            if(Arr[i]>root->key){
                Node *right;
                Node
                root->left = left;
            }else{
                Node *right;
                Node
                root->left = left;

            }
        }
    }

}

void transplant_tree(Node *root, Node *u, Node *v){

}

/**
 * Deletes all the nodes from Tree (with n distinct keys), whose key is greater that k
 *
 * @param root
 * @param key
 */
void delete_keys_greater(Node *root, int k){

}


// Driver Code
int main(){
    // Test Sorting
    int Arr[]={1,3,-1,5,230,0, 99};
    quick_sort(&Arr[0], 0, 6);
    for(int i = 0; i<sizeof(Arr); i++){
        std::cout<< Arr[i] << std::endl;
    }


}