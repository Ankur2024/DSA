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

int main() {
    BSTnode* root = nullptr; 
    cout << "Enter data to create BST (-1 to stop): " << endl;
    root = takeInput(root); 
    cout << "Level Order Traversal of BST is: " << endl;
    levelOrderTraversal(root); 
    cout << "\nInorder traversal of BST is: " << endl;
    inorderTraversal(root);
    cout << "\nPreorder traversal of BST is: " << endl;
    preorderTraversal(root);
    cout << "\nPostorder traversal of BST is: " << endl;
    postorderTraversal(root);

    return 0;
}
