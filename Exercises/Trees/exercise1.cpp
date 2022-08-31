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

// Esercizio Alberi 1.png
int gradosquil_rec(Node *root){
    //Empty
    if(!root){
        return 0;
    }else {
        // Leaf
        if(!root->left && !root->right){
            return root->key;
        }
        return abs(gradosquil_rec(root->left) - gradosquil_rec(root->right));
    }
}

// Esercizio 5.png
// Dobbiamo esplorare tutti i cammini dalla radice alle foglie, altrimenti rischiamo che ci siano pesi negativi.
// TODO: Fix that subtrees are ignored if total sum from root to leaf <=k
int k_limited_aux(Node *root, int k, int w){
    // Empty Tree
    if(!root){
        return 0;
    }else {
        //Leaf
        w +=root->key;
        if(!root->left && !root->right){
            // Consider path from leaf to itself
            // Consider path to the leaf
            if(root->key <= k && w <= k){
                return 1;
            }else{
                std::cout<< "Il peso del cammino dalla foglia a se' stessa e' " << root->key << ", mentre il cammino"
                                                                                                " dai suoi parenti e' "<< w << std::endl;
                return 0;
            }
            //Subtree
        }else {
            // Return True if w(p)<=k & subpaths to leaf are <=k
            if ((k_limited_aux(root->left, k, w)) && k_limited_aux(root->right, k, w)) {
                return 1;
            } else {
                std::cout << "Il peso del cammino da " << root->key << " e' maggiore di k, infatti k<" << w
                          << std::endl;
                return 0;
            }
        }
    }
}

// Complessita = Theta(leaves) =
int k_limitato_rec(Node *root, int k){
    return k_limited_aux(root, k, 0);
}



int main()
{
    int arr[] = { -21, -20, 2, 14, -30, 10, 4, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = createTree(arr, n);
    levelOrder(root);
    int squil = gradosquil_rec(root);

    cout<< "\n"<<endl;
    printBT(root);
    //cout<< "\n Il grado di squilibrio: "<< squil << "\n" << endl;

    int k = 40;
    if(k_limitato_rec(root, k)){
        cout<< "\nL'albero e' limitato per k = "<< k << "\n" << endl;
    }else{
        cout<< "\nL'albero NON e' limitato per k = "<< k << "\n" << endl;
    }

    return 0;
}