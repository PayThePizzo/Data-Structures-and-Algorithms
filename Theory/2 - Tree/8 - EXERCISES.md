# Exercises on trees
To represent the trees in c++ we need to use either a struct (more c-style version) or a class.

Normally, for each kind of tree we must be ready to perform the following actions
* General Tree
* Binary Tree
  * Perform some mathematical operation on all the keys (i.e. total sum)
  * 
* BST
  * Build a BST 

---

## Binary Trees - Pointers to Children

### Implementation

```c++
#include <iostream>
#include <vector>

using std:: pair;

class Node{
public:
    int info;
    Node* right;
    Node* left;
    
    // Constructor
    Node(int info){
        this->info = info;
        this->left = nullptr;
        this ->right = nullptr;
    }
    
    void insertChildrenSX(int info){
        Node* children = new Node(info);
        this->left = children;
    }

    void insertChildrenDX(int info){
        Node* children = new Node(info);
        this->right = children;
    }
    
    void printablePOSTORDER(){
        printablePOSTORDER_ric(this);
    }
    
    void printablePOSTORDER_ric(Node* nodo){
        if(nodo != nullptr) {
            printablePOSTORDER_ric(nodo->left);
            printablePOSTORDER_ric(nodo->right);
            std::cout << nodo->info << " ";
        }
    }
}
```

### 1 - Intermediate vertices


```c++
int intermedi(){
    return intermedi_ric(this, 0).first;
}

pair <int,int> intermedi_ric(Node* u, int SumP){
    if(u == nullptr){
        return {0,0};
    }else{
        pair<int,int> sx = intermedi_ric(u->left, SumP+u->info);
        pair<int,int> dx = intermedi_ric(u->right, SumP+u->info);
        if(sx.second + dx.second + u->info == SumP){
            return {sx.first + dx.first +1, sx.second + dx.second + u->info };
        }else{
            return {sx.first + dx.first, sx.second + dx.second + u->info };
        }
    }
}
```



### 2 - t-Balanced Tree


### 3 - Print a level of a tree

#### 4 - Tree with depth



---

## General Trees - Left Child Right Sibling

### Implementation

```c++

```

### 1 - Verify if the tree is a complete k-ary tree

### 2 - Halfing the keys of even levels

### 3 - Minimum Common Ancestor

---

## BST

### Implementation

```c++

```

### 1

### 2

### 3


---