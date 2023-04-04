//
// Created by PayThePizzo on 3/15/2023.
//

#include "iostream"
#include "list"

using namespace std;

// Binary Tree

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *sx = nullptr, Node *dx = nullptr)
            : key{k}, left{sx}, right{dx} {}
};

typedef Node *PNode;

PNode newTree(int key) {
    PNode t = new Node(key);
    return t;
}

bool treeEmpty(PNode t) {
    return t == nullptr;
}

void insert_left(PNode t, int key) {
    // empty tree
    if(!treeEmpty(t)){
        // left is already present
        if(!treeEmpty(t->left)){
            insert_left(t->left, key);
        }else{
           PNode left_node = newTree(key);
            t->left = left_node;
        }
    }
}

void insert_right(PNode t, int key) {
    if(!treeEmpty(t)){
        // left is already present
        if(!treeEmpty(t->right)){
            insert_left(t->right, key);
        }else{
            PNode right_node = newTree(key);
            t->right = right_node;
        }
    }
}

void visit_DFS(PNode t){
    if(!treeEmpty(t)){
        std::cout << t->key << std::endl;
        visit_DFS(t->left);
        visit_DFS(t->right);
    }
}

void visit_PostOrder(PNode t){
    if(!treeEmpty(t)){
        visit_PostOrder(t->left);
        visit_PostOrder(t->right);
        std::cout << t->key << std::endl;
    }
}

std::pair<int, bool> k_compreso_aux(PNode t, int k, int sum){
    if(t == nullptr){
        std::pair<int,bool> p = {0, true};
        return p;
    }else{
        std::pair<int, bool> left = k_compreso_aux(t->left,  k, sum);
        std::pair<int, bool> right = k_compreso_aux(t->right, k, sum);
        int total = t->key + left.first + right.first;

        if((total >= -k && total <= k) && (left.second && right.second)){
            std::pair<int,bool> p = {total, true};
            return p;
        }else{
            std::pair<int,bool> p = {total, false};
            return p;
        }
    }

}

int k_compreso(PNode t, int k){
    if(t == nullptr){
        return 0;
    }else{
        return k_compreso_aux(t, k, 0).second ? 1 : 0 ;
    }
}

int gradosquil_aux(PNode t){
    if(t == nullptr){
        return 0;
    }else{
        int l = gradosquil_aux(t->left);
        int r = gradosquil_aux(t->right);
        int grado = abs(l-r);

    }
    return 0;
}

int gradosquil(PNode t){
    if (t== nullptr){
        return 0;
    }else{
        return gradosquil_aux(t);
    }
}

int k_limitato(PNode t){

}



PNode test_tree_1(){
    PNode tree = newTree(0);
    insert_left(tree, 1);
    insert_right(tree, 2);
    insert_left(tree->left, 3);
    insert_right(tree->left, 4);
    insert_left(tree->right, 5);
    insert_right(tree->right, 6);
    return tree;
}

PNode test_tree_2(){
    PNode tree = newTree(543);
    insert_left(tree, 12);
    insert_right(tree, 82);
    insert_left(tree->left, 73);
    insert_right(tree->left, 44);
    insert_left(tree->right, 15);
    insert_right(tree->right, 6);
}

PNode test_tree_3(){
    PNode tree = newTree(-3);
    insert_left(tree,  1);
    insert_right(tree, -2);
    insert_left(tree->left, 3);
    insert_right(tree->left, -4);
    insert_left(tree->right, 5);
    insert_right(tree->right, 6);
}

// -- LCRS

struct NodeG {
    int key;
    NodeG* left_child;
    NodeG* right_sib;
    NodeG(int k, NodeG* sx = nullptr, NodeG* dx = nullptr)
            : key{k}, left_child{sx}, right_sib{dx} {}

};

typedef NodeG* PNodeG;

PNodeG newTree2(int key){
    PNodeG t = new NodeG(key);
    return t;
}

void insert_left_child(PNodeG tree, int key){
    if(tree != nullptr){
        if(tree->left_child != nullptr){
            insert_left_child(tree, key);
        }else{
            PNodeG left = newTree2(key);
            tree->left_child = left;
        }
    }
}

void insert_right_sibling(PNodeG tree, int key){
    if(tree != nullptr){
        if(tree->right_sib != nullptr){
            insert_right_sibling(tree->right_sib, key);
        }else{
            PNodeG right = newTree2(key);
            tree->right_sib = right;
        }
    }
}

void Visit_PreOrder(PNodeG tree){
    if(tree == nullptr){
        return ;
    }else{
        cout << "" << tree->key;
        Visit_PreOrder(tree->left_child);
        Visit_PreOrder(tree->right_sib);
    }
}

// Theta(n)
// Preorder Visit on the general tree to verify the existential property of being a leaf
// As we have a general tree, we must iterate through all the nodes to find out whether each node
// is a leaf.
// We must check each node to get our final answer as at any point, a node could be a leaf.
// Thus, be covering the tree exactly once, we perform a Preorder Visit of complexity T(n) = O(n).
int count_leaves(PNodeG tree){
    if(tree == nullptr){
        return 0;
    }else{
        if(tree->left_child== nullptr){
            return 1 + count_leaves(tree->right_sib);
        }else{
            return count_leaves(tree->left_child) + count_leaves(tree->right_sib);
        }
    }
}

int k_completo_aux(PNodeG tree, int k){

}

// Existential property, verify
bool k_completo(PNodeG tree, int k){


}

PNodeG test_tree4(){
    PNodeG tree = newTree2(0);
    insert_left_child(tree, 1);
    insert_right_sibling(tree->left_child, 2);
    insert_left_child(tree->left_child, 3);
    insert_right_sibling(tree->left_child->left_child, 4);
    insert_left_child(tree->left_child->right_sib, 5);
    insert_right_sibling(tree->left_child->right_sib->left_child, 6);
    return tree;
}

PNodeG test_tree5(){
    PNodeG tree = newTree2(0);
    insert_left_child(tree, 1);
    insert_right_sibling(tree->left_child, 2);
    insert_right_sibling(tree->left_child->right_sib, 7);
    insert_left_child(tree->left_child, 3);
    insert_right_sibling(tree->left_child->left_child, 4);
    insert_right_sibling(tree->left_child->left_child->right_sib, 9);
    insert_left_child(tree->left_child->right_sib, 5);
    insert_right_sibling(tree->left_child->right_sib->left_child, 6);
    insert_left_child(tree->left_child->right_sib->left_child, 10);
    return tree;
}

// 4 leaves
PNodeG test_tree6(){
    PNodeG tree = newTree2(0);
    insert_left_child(tree, 1);
    insert_right_sibling(tree->left_child, 2);
    insert_right_sibling(tree->left_child->right_sib, 3);
    insert_left_child(tree->left_child, 4);
    insert_right_sibling(tree->left_child->left_child, 5);
    insert_left_child(tree->left_child->left_child->right_sib, 6);
    return tree;
}

PNodeG test_tree7(){
    PNodeG tree = newTree2(0);
    insert_left_child(tree, 1);
    insert_right_sibling(tree->left_child, 2);
    insert_right_sibling(tree->left_child->right_sib, 3);
    insert_right_sibling(tree->left_child->right_sib->right_sib, 7);
    insert_left_child(tree->left_child, 4);
    insert_right_sibling(tree->left_child->left_child, 5);
    insert_left_child(tree->left_child->left_child->right_sib, 6);
    return tree;
}


int main ()
{
    PNodeG t = test_tree7();
    int a = count_leaves(t);
    cout << " " << a;

    Visit_PreOrder(t);
    return 0;
}