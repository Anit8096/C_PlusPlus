#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;

        Node(int val) {
            data = val;
            left = right = NULL;
        }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();  
        q.pop();
        
        if (temp->left == NULL) {
            temp->left = new Node(val);
            break;
        } else {
            q.push(temp->left);
        }
        
        if (temp->right == NULL) {
            temp->right = new Node(val);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

void deletDeepest(Node *root, Node *d_node) {
    queue<Node*> q;
    q.push(root);
    Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }

        if (temp->right) {
            if (temp->right == d_node){
                temp->right = NULL;
                delete d_node;
                return;
            } else {
                q.push(temp->right);
            }
        }
        
        if (temp->left) {
            if (temp->left == d_node){
                temp->left = NULL;
                delete d_node;
                return;
            } else {
                q.push(temp->left);
            }
        }
    }
}

Node* deletion(Node* root, int key) {
    if (root == NULL)
        return NULL;
     
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key)
            return NULL;
        else
            return root;
    }

    queue<Node*> q;
    q.push(root);
    Node* temp;
    Node* Key_Node = NULL;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            Key_Node = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    if (Key_Node != NULL) {
        Key_Node->data = temp->data;
        deletDeepest(root, temp);
    }

    return root;
}

void inorderTraversal(Node *root) {
    if(!root) return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root) {
    if(!root) return;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if(!root) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

void levelorderTraversal(Node *root) {
    //Breadth-First Search (BFS) Algorithms
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

int main() {
    Node* root = NULL;
    // Insertion of nodes
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);

    cout << "Preorder traversal: ";
    preorderTraversal(root);

    cout << "\nInorder traversal: ";
    inorderTraversal(root);

    cout << "\nPostorder traversal: ";
    postorderTraversal(root);

    cout << "\nLevel order traversal: ";
    levelorderTraversal(root); //BFS

    // Delete the node with data = 20
    root = deletion(root, 20);

    cout << "\nInorder traversal after deletion: ";
    inorderTraversal(root);
}

/*

Insertion:-
time->O(N)	
space->O(N)

Preorder Traversal:-
time->O(N)	
space->O(N)

Inorder Traversal:-
time->O(N)
space->O(N)

Postorder Traversal:-
time->O(N)	
sapce->O(N)

Level Order Traversal:-
time->O(N)	
sapce->O(N)

Deletion:-
time->O(N)
sapce->O(N)

Searching (DFS):-
time->O(N)
space->O(N)

*/