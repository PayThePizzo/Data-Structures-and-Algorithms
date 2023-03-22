# BST Exercises:

## k
Remo

```c++
struct Node{
};

struct Tree{
};


void remove(Node n){
    if(n != null){
        remove(n->left);
        remove(n->right);
        free(n);
    }
}

void transplant(Tree t, Node u, Node v){
    if(u->parent == t->root){
        t->root = v;
    }else if(u == u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    if(v!=NULL){
        v->parent = u->parent;
    }
}

void removeIfLEQ(Tree t, int k){
    Node iter, temp;
    iter = t->root;
    while(iter->key != k){
        if(iter->key < k){
            remove(iter->left);
            iter->left = NULL;
            temp = iter;
            transplant(t, iter, iter->right);
            iter = iter->right;
            free(temp);
        }else{
            iter = iter->left;
        }
    }
    remove(iter->left);
    iter->left = NULL;
}

```