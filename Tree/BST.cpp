#include <bits/stdc++.h>
using namespace std;

class BSTnode {
public:
    int data;
    BSTnode *left, *right;

    BSTnode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

BSTnode* insertIntoBST(BSTnode* root, int data) {
    if (root == NULL) {
        root = new BSTnode(data);
        return root;
    }
    if (data > root->data) {
        // Insert in the right subtree
        root->right = insertIntoBST(root->right, data);
    } else {
        // Insert in the left subtree
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

BSTnode* takeInput(BSTnode* root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data); 
        cin >> data;
    }
    return root;
}

void levelOrderTraversal(BSTnode* root) {
    if (!root)
        return;

    queue<BSTnode*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        BSTnode* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout << endl;
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorderTraversal(BSTnode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder : NLR
void preorderTraversal(BSTnode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder : LRN
void postorderTraversal(BSTnode *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

BSTnode *inorderSuccessor(BSTnode *root, int val){
    BSTnode *successor = nullptr;
    while (root != nullptr)
    {
        if(root -> data <= val){
            root = root -> right;
        }else {
            successor = root;
            root = root -> left;
        }
    }
    return successor;
}

BSTnode *inorderPredecessor(BSTnode *root, int val){
    BSTnode *predecessor = nullptr;
    while (root != nullptr)
    {
        if(root -> data < val){
            predecessor = root;
            root = root->right;
        }else {
            root = root -> left;
        }
    }
    return predecessor;
}

int minValue(BSTnode* root) {
        BSTnode *temp = root;
        while(temp->left != nullptr){
            temp = temp -> left;
        }
        return temp ->data;
    }

BSTnode *deleteFromBST(BSTnode *root, int val){
    if(root == nullptr){
        return nullptr;
    }
    if(root -> data == val){
        if(root -> left == nullptr && root -> right == nullptr){
            delete root;
            return nullptr;
        }
        if(root -> left != nullptr && root -> right == nullptr){
            BSTnode *temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> left == nullptr && root -> right != nullptr){
            BSTnode *temp = root -> right;
            delete root;
            return temp;
        }
        if(root -> left != nullptr && root -> right != nullptr){
            int mini = minValue(root -> right);
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }
    else if(root -> data > val){
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else{
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}


int main() {
    // Initialize root node of the BST
    BSTnode* root = nullptr; 

    // Take input from user to create the BST, where -1 stops the input
    cout << "Enter data to create BST (-1 to stop): " << endl;
    root = takeInput(root); 

    // Display the Level Order Traversal of the BST
    cout << "Level Order Traversal of BST is: " << endl;
    levelOrderTraversal(root); 

    // Display Inorder Traversal of the BST
    cout << "\nInorder traversal of BST is: " << endl;
    inorderTraversal(root);

    // Display Preorder Traversal of the BST
    cout << "\nPreorder traversal of BST is: " << endl;
    preorderTraversal(root);

    // Display Postorder Traversal of the BST
    cout << "\nPostorder traversal of BST is: " << endl;
    postorderTraversal(root);

    // Ask user for a value to find its inorder successor
    cout << "\nEnter a value to find its inorder successor: ";
    int val;
    cin >> val;
    
    // Find the inorder successor and display result
    BSTnode *successor = inorderSuccessor(root, val);
    if(successor != nullptr)
        cout << "Inorder successor of " << val << " is " << successor->data << endl;
    else
        cout << "No inorder successor found for " << val << endl;

    // Ask user for a value to find its inorder predecessor
    cout << "\nEnter a value to find its inorder predecessor: ";
    cin >> val;

    // Find the inorder predecessor and display result
    BSTnode *predecessor = inorderPredecessor(root, val);
    if(predecessor != nullptr)
        cout << "Inorder predecessor of " << val << " is " << predecessor->data << endl;
    else
        cout << "No inorder predecessor found for " << val << endl;

    // Ask user for a value to delete from the BST
    cout << "\nEnter a value to delete from BST: ";
    cin >> val;

    // Delete the value from the BST and display the new structure of the tree
    root = deleteFromBST(root, val);
    cout << "\nAfter deleting " << val << ", the BST is: " << endl;
    levelOrderTraversal(root); 

    return 0;
}

