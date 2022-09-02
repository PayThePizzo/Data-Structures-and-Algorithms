# Tree Exercises

## K-Limited

![k-limited](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/Trees/Esercizio%20Alberi%205.png?raw=TRUE)

### Data Structure and Solution
```c++
struct Node{
    int key;
    Node *left;
    Node *right;
};
```

```c++
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
```

### Complexity
It is not possible to start from the top to check the condition of the sum of key being less or equal than k, since
it would fail in case of negative weights. A top-down solution would mean considering always every internal node's path to the 
leaves, and would take more time than starting directly from the leaves!

In the best case, we find immediately that our tree is k-limited (case of empty tree).
In the worst case we must perform a post-order visit of nodes, in the tree.

The algorithm k_limitato() utilizes a boolean flag as a global value to check whether the condition is respected.
I.f.f the initial tree is not empty, we can check the condition on the subtrees. Otherwise, we would be considering 
a tree with no node, therefore no key or sub-sum of keys can violate the condition!

Then the function passes its input and a pointer to the boolean flag, to k_limitato_aux(). If the flag is false, we return 0.
In the case we the condition is not violated, we 


# Theorem
Any visit algorithm applied to the root of a tree Tree with n nodes:
1. T(n)=O(n)
2. S(n)=O(n)

Hypothesis: Every node is inserted and extracted from Tree T(n)=O(1)

Dim: Every node is inserted and extracted from Tree exactly **once**:
1. By construction, the data structure does not include a pointer to the parent of node
2. By construction, we can only go from a node `u` to its descendants and not the opposite way.


T(k_limitato) = O(n):
* O(1), if n==0 (empty tree);
* T(k_limitato_aux()), n>0;

T(k_limitato_aux()):
* O(1), if flag is false
  * s 
* 



---

