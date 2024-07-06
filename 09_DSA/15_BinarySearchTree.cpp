#include <iostream>
using namespace std;
struct Node {
    int key;
    struct Node *left, *right;
};

struct Node *NewNode(int val) {
    struct Node* temp = new struct Node;
    temp->key = val;
    temp->right = temp->left = NULL;
    return temp;
}

Node *insert( Node *root, int keyy) {
    if (!root)
        return NewNode(keyy);

    (keyy < root->key)
        ? root->left = insert(root->left, keyy)
        : root->right = insert(root->right, keyy);

    return root;
}

Node* search(Node* root, int val) {
    if (root == nullptr || root->key == val)
        return root;

    if (root->key < val)
        return search(root->right, val);
    else
        return search(root->left, val);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int d_val) {
    if (root == NULL)
        return root;

    (d_val < root->key)
        ? root->left = deleteNode(root->left, d_val)
        : root->right = deleteNode(root->right, d_val);

    if (root->key == d_val){
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout<<" "<< root->key;
        inorder(root->right);
    }
}

int main()
{
    
    /* 
    Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */
    Node* root = NULL;

    // Creating the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Function Call
    cout << "Inorder Traversal ->";
    inorder(root);
    
    return 0;
}