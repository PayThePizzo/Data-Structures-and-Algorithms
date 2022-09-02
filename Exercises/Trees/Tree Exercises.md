# Tree Exercises

## K-Limited

![k-limited](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Exercises/Trees/Esercizio%20Alberi%205.png?raw=TRUE)

```c++
int k_limitato_aux(Node *root, int k, bool *flag){
    if(*flag){
        int path = root->key;
        if(!root->left && root->right){
            int r_sub_sum = k_limitato_aux(root->right, k, flag);
            path += r_sub_sum;
            return check_path(path, k, flag);

        }else if(root->left && !root->right){
            int l_sub_sum = k_limitato_aux(root->left, k, flag);
            path += l_sub_sum;
            return check_path(path, k, flag);

        }else if (root->left && root->right){
            int r_sub_sum = k_limitato_aux(root->right, k, flag);
            int l_sub_sum = k_limitato_aux(root->left, k, flag);
            path += max(r_sub_sum, l_sub_sum);
            return check_path(path, k, flag);

        }else if (is_leaf(root)){
            return check_path(path, k, flag);
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
In the best case, we find immediately that our tree is k-limited (case of empty tree).
In the worst case we must perform a post-order visit of all leaves, in the tree.

In fact, it is not possible to start from the top to check the condition of the sum of key being less or equal than k, since
it would fail in case of negative weights. A top-down solution would mean considering always every internal node's path to the 
leaves, and would take more time than starting directly from the leaves!

At worst, we visit every node of the tree, so O(n) visits!

T(k_limitato) = O(n):
* O(1), if n==0 (empty tree);
* T(k_limitato_aux()), n>0;

T(k_limitato_aux()):
* O(1), if flag is false
  * s 
* 



---

