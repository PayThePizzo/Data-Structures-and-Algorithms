//
// Created by PayThePizzo on 8/22/2022.
//

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};

struct Tree{
    Node *left;
    Node *right;
};

// --- GeeksforGeeks Credits ---
// Function to create a node with 'value' as the data
// stored in it.
// Both the children of this new Node are initially null.
struct Node* newNode(int value)
{
    Node* n = new Node;
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node* insertValue(struct Node* root, int value,
                         queue<Node *>& q)
{
    Node* node = newNode(value);
    if (root == NULL)
        root = node;

        // The left child of the current Node is
        // used if it is available.
    else if (q.front()->left == NULL)
        q.front()->left = node;

        // The right child of the current Node is used
        // if it is available. Since the left child of this
        // node has already been used, the Node is popped
        // from the queue after using its right child.
    else {
        q.front()->right = node;
        q.pop();
    }

    // Whenever a new Node is added to the tree, its
    // address is pushed into the queue.
    // So that its children Nodes can be used later.
    q.push(node);
    return root;
}

// This function mainly calls insertValue() for
// all array elements. All calls use same queue.
Node* createTree(int arr[], int n)
{
    Node* root = NULL;
    queue<Node*> q;
    for (int i = 0; i < n; i++)
        root = insertValue(root, arr[i], q);
    return root;
}

// This is used to verify the logic.
void levelOrder(struct Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> n;
    n.push(root);
    while (!n.empty()) {
        cout << n.front()->key << " ";
        if (n.front()->left != NULL)
            n.push(n.front()->left);
        if (n.front()->right != NULL)
            n.push(n.front()->right);
        n.pop();
    }
}

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|__" : "L__" );

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

//--- GeeksforGeeks Credits ---

/**
 * Trova il grado di squilibrio di un nodo, ovvero il valore assoluto della differenza tra
 * la somma delle chiavi nel sotto albero sinistro e la somma delle chiavi nel sotto albero destro.
 *
 * @param u nodo
 * @return grado di squilbrio di un nodo
 */
 //TODO: FIX
int gradosquil_node(Node *root){
    //Empty
    if(!root){
        return 0;
    }else {
        // Leaf
        if(!root->left && !root->right){
            return root->key;
        }
        return abs(gradosquil_node(root->left) - gradosquil_node(root->right));
    }
}

/**
 * Trova il massimo grado di squilibrio di un albero. Cio' si traduce nel massimo grado di squilibrio
 * dei suoi nodi.
 *
 * @param root radice dell'albero
 * @return grado di squilibrio dell'albero
 *
 */
 // TODO: FIX
int gradosquil_tree(Tree *root){
    //Empty
    if(!root){
        return 0;
    }else {
        return max(gradosquil_node(root->left), gradosquil_node(root->right));
    }
}


int check_path(int path, int k, bool* flag){
    if(path>k){
        *flag = false;
        return 0;
    }else{
        return path;
    }
}

int k_limitato_aux(Node *root, int k, bool *flag){
    if(*flag){
        int path;
        if(!root->left && root->right){
            return check_path(root->key + k_limitato_aux(root->right, k, flag), k, flag);
        }else if(root->left && !root->right){
            return check_path(root->key + k_limitato_aux(root->left, k, flag), k, flag);
        }else if (root->left && root->right){
            return check_path(root->key + max(k_limitato_aux(root->left, k, flag),
                                              k_limitato_aux(root->left, k, flag)), k, flag);
        }else if (!root->left && !root->right){
            return check_path(root->key, k, flag);
        }
    }else{
        return 0;
    }
}



int k_limitato(Node *root, int k){
    bool flag = true;
    if (root){
        k_limitato_aux( root, k, &flag);
    }
    return flag == true ? 1:0;
}

int main()
{
    int arr[] = { 1, -2, -3, -4, 5, 4,3};
    int arr1[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = createTree(arr, n);
    levelOrder(root);

    cout<< "\n"<<endl;
    printBT(root);
    //cout<< "\n Il grado di squilibrio: "<< squil << "\n" << endl;
    int i = 15;

    for(i = -5; i<10; i++){
        if(k_limitato(root, i)){
            cout<< "\nL'albero e' limitato per k = "<< i << "\n" << endl;
        }else{
            cout<< "\nL'albero NON e' limitato per k = "<< i << "\n" << endl;
        }
    }
    return 0;
}