# Binary Tree Exercises

The exercises consider the following struct as the type for a node of a tree:
```c++
struct Node{
    int key;
    Node *left;
    Node *right;
};
```

## K-Limited

![k-limited](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/Trees/Esercizio%20Alberi%205.png?raw=TRUE)

### Solution
The only available option here, by construction of the exercise, is to check a universal condition through a post-order visit.
The boolean variable flag represents whether there is a violation of the upperbound k.
In the best case, we immediately update flag to false when we find either an empty tree or a leaf that violates the property. Therefore, it
causes to stop all the recursion calls immediately and does not modify the content of flag anymore. To sum up, only if the condition is always true,
we need to check the whole tree (n nodes).

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
T(check_path) = O(1)
* Simple condition control and return

T(k_limitato_aux) = O(n)
* O(1), if flag is false it immediately fails
* T(n) = max{ if-else block } = T(n) = Θ(n), else
  * The third block where we have two recursive calls on the left and the right subtree is the most expensive.
  * The function first gets to the leaves, and then returns the content.
  * We visit each node exactly once, in the worst case, since we do not have a pointer to the parent of a node
  * All the checks and other operations are done in constant time by hypothesis.

T(k_limitato) = O(n)
* O(1), n = 0
* T(k_limitato) = O(n), n > 0;

---

## Degree of Inbalance

![grado squilibrio](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/Trees/Esercizio%20Alberi%201.png?raw=TRUE)

### Solution

```c++
int gradosquil_aux(Node *root, int *max_gs){
    if(!root){
        return 0;
    }else{
        if(!root->left && !root->right){
            return root->key;
        }else {
            int gsn = abs(gradosquil_aux(root->left, max_gs)- gradosquil_aux(root->right, max_gs));
            if(gsn > *max_gs){
               *max_gs = gsn;
            }
            return gsn;
        }
    }
}

int gradosquil_tree(Node *root){
    int max = 0;
    return gradosquil_aux(root, &max);
}
```

### Complexity
T(gradosquil_tree()) = Θ(n) = O(1) + T(gradosquil_aux())

T(gradosquil_aux()):
* c, if n==0;
* T(k) + T(n-k-1) + d, if n>0
  * Calls on left subtree + Calls on the right subtree.

For the substitution method: 
1. Our hypothesis is to have a linear function since we cover all nodes exactly once: T(n) = a * n + b
2. Demonstration by induction that T(n) is a linear function, we need to **find a and b**

Dem:
1. Base Case, n = 0:
   * T(0) = a*0+b = **b = c**, by construction; 
2. Inductive Hypothesis, assume m<n T(m) = a*m+b
3. Inductive Step
   * T(n) = T(k) + T(n-k-1) + d
     * k < n, n-k-1 < n
   * T(n) = ak+b + a(n-k-1) + b + d = ak + b + an - ak - a + b + d = an - a + 2b + d
     * We want to demonstrate that **T(n) = an+b**
     * T(n) = an - a + 2b + d = an + b
     * b-a+d = 0 -->  a = b+d -->  a = c + d 
     * T(n) = (c+d)n + c, by point 2.
4. T(n) = Θ(n)