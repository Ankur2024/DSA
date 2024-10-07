#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return nullptr;
    }
    cout << "Enter data for inserting in the left" << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in the right" << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    stack<vector<int>> st;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();

            if (temp)
            {
                currentLevel.push_back(temp->data);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        st.push(currentLevel);
    }

    while (!st.empty())
    {
        vector<int> level = st.top();
        st.pop();

        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

//Inorder :- LNR
void inorderTraversal(node *root){
    if(root == nullptr){
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

//Preorder : NLR
void preorderTraversal(node *root){
     if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


//Postorder : LRN
void postorderTraversal(node *root){
     if(root == nullptr){
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";

}

void buildTreeFromLevelOrderTraversal(node *root){
    queue<node *> q;
    cout << "Enter the root node data: ";
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1)
    {
        return;
    }
    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        cout << "Enter left child of " << temp->data << ": ";
        int left_data;
        cin >> left_data;
        if(left_data!= -1){
            temp->left = new node(left_data);
            q.push(temp->left);
        }
        cout << "Enter right child of " << temp->data << ": ";
        int right_data;
        cin >> right_data;
        if(right_data!= -1){
            temp->right = new node(right_data);
            q.push(temp->right);
        }
    }


}

int main()
{
    node *root = nullptr;
    root = buildTree(root);
    // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);
    reverseLevelOrderTraversal(root);

    cout << "\nInorder traversal: ";
    inorderTraversal(root);
    cout << "\nPreorder traversal: ";
    preorderTraversal(root);
    cout << "\nPostorder traversal: ";
    postorderTraversal(root);
    return 0;
}
