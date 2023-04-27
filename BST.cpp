#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root==NULL) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << " ";     // Print root.
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
    if (root==NULL) {  // Create Tree if there isn't a Tree.
        struct node *newNode = new node();
        newNode->key=key;
        newNode->left=newNode->right=NULL;
        root=newNode;
    }
    else if (key<=(root->key)) {  // Go to left of tree.
        root->left=insertNode(root->left,key);
    }else {                       // Go to right of the tree.
        root->right=insertNode(root->right,key);
    }
    return root;
}

// Find Maximum.
struct node *FindMax(node *root) {
    if (root->right==NULL) {
        return root;
    }else {
        return FindMax(root->right);
    }
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root==NULL) {
        return root;
    }else if (key<root->key) {
        root->left=deleteNode(root->left,key);
    }else if (key>root->key) {
        root->right=deleteNode(root->right,key);

    // Found the key........
    }else {    // ( key == root->key. )
        // First case (root hasn't any child.)
        if ((root->left==NULL)&&(root->right==NULL)) {
            delete root;
            root=NULL;
        }

        // Second case (root has only one child.)

        else if (root->left==NULL) {  // No left child.
            struct node *Temp = root;
            root = root->right;
            delete Temp;
        }
        else if (root->right==NULL) {  // No right child.
            struct node *Temp = root;
            root = root->left;
            delete Temp;
        }

        // Third case (root has both children.)
        else {
            struct node *Temp = FindMax(root->left);
            root->key = Temp->key;
            root->left = deleteNode(root->left,Temp->key);
        }
    }
    return root;
}

// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }
    
    traverseInOrder(root);
}