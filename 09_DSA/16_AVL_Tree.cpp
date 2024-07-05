#include <iostream>
using namespace std;

struct node {
    int key, height;
    node *left, *right;
};

int height(node *root) {
    if (root == NULL)
        return 0;
    
    return root->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

node *newNode(int key) {
    node *newNode = new node();
    newNode->height = 1;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return (newNode);
}

node *rightRotate (node *y) {
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *leftRotate (node *x) {
    node *y = x->right;  
    node *T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
  
    x->height = max(height(x->left), height(x->right)) + 1;  
    y->height = max(height(y->left), height(y->right)) + 1;  
  
    return y;  
}

int getBalance(node *N) {  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
 
node* insert(node* node, int key) {
    if (node == NULL)  
        return(newNode(key));  
  
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else  
        return node;  
  
    node->height = 1 + max(height(node->left),  
                        height(node->right));  

    int balance = getBalance(node);  
   
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  

    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  

    if (balance > 1 && key > node->left->key) {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    if (balance < -1 && key < node->right->key) {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}  

void preOrder(node *root) {  
    if(root != NULL) {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

int main()  
{  
    node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
      
    /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
    cout << "Preorder traversal of the constructed AVL tree is \n";  
    preOrder(root);  
      
    return 0;  
}  