#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key) {
    
    if (node == NULL)
        return newNode(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }

    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << " " << root->key;
        inorder(root->right);
    }
}

node* search (node* root, int f_val) {
    if (root == NULL)
        return NULL;

    if (root->key == f_val)
        return root;

    if (root->key > f_val) 
        return search(root->right, f_val);
    
    return search(root->left, f_val);
}

int main() {
     
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */
    struct node* root = NULL;

    // Creating the BST
    root = insert(root, 50);
    insert(root, 80);
    insert(root, 20);
    insert(root, 40);
    insert(root, 30);
    insert(root, 60);
    insert(root, 70);

    // Function Call

    cout<<"In-order-> ";
    inorder(root);
    cout<<endl;

    if (search(root, 100) == NULL) 
        cout<<"Key Dosen't Exist\n";
    else
        cout<<"Key Exist\n";

    return 0;
}