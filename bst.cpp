#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node *left, *right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* insertBST(node* root, int data);
bool searchBST(node* root, int key);
void deleteBST(node* root, int val);

// heightBST() is maxDept()
int heightBST(node* root);
int minDepth(node* root);

int inorderSucc(node* root, int val);
int inorderPred(node* root, int val);

bool checkBST(node* root);

int main() {

    /*
    // Tree for checking height
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    */

    // taking tree as input
    node* root = NULL;

    cout << "Enter the elements of the tree: ";
    // input (example tree) : 10 7 15 20 5 9 -1
    // input 2 : 10 7 8 4 5 6 20 15 18 -1
    /* Tree
        10
       /  \
      7   15
     / \    \
    5   9   20
    */

    int d;
    cin >> d;
    while (d > 0) {
        root = insertBST(root, d);
        cin >> d;
    }


    // print inorder
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    /* for checking searchBST()

    // take input for searchBST()
    cout << "Enter element to search for: ";
    int key;
    cin >> key;

    // print statement for searchBST
    bool flag = searchBST(root, 18);
    if (flag == true)
        cout << key << " is present in tree" << endl;
    else
        cout << key << " is not present in tree" << endl;
    */

   // for printing height  of tree
   cout << "Height of this tree: " << heightBST(root);
   cout << endl;

   cout << "Min depth of this tree: " << minDepth(root) << endl;

    node* root2 = new node(5);
    root2->left = new node(3);
    root2->left->left = new node(2);
    root2->left->right = new node(4);
    root2->right = new node(6);
    cout << checkBST(root2) << endl;

}

node* insertBST(node* root, int data) {

    // base case: if root is NULL create new node and return the root
    if (root == NULL){
        root = new node(data);
        return root;
    }

    // if data is less than root's data, run recursive left
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    }

    // if data is more than root's data
    else {
        root->right = insertBST(root->right, data);
    }

    return root;

}

bool searchBST(node* root, int key) {

    if (root == NULL) return false;

    if (root->data == key) {
        return true;
    }
    else {
        if (key < root->data) {
            // recursive left
            return searchBST(root->left, key);
        }
        else {
            // recursive right
            return searchBST(root->right, key);
        }
    }

}

int heightBST(node* root) {

    // base case: if root is NULL
    if (root == NULL) return 0;

    // check height for left subtree
    int leftHeight = heightBST(root -> left);

    // check height for right subtree
    int rightHeight = heightBST(root -> right);

    // return maximum height
    return max(leftHeight, rightHeight) + 1;

}

bool checkBST(node* root) {

    // base case
    if (root == NULL) return false;

    int leftData = root->left->data;
    int rightData = root->right->data;

    if (leftData < root->data && rightData > root->data)
        return true;
    else
        return false;
    // recursive left
    return checkBST(root->left);

    // recursive right
    return checkBST(root->right);

}

int minDepth(node* root) {

    // base case
    if (root == NULL) return 0;

    // if either subtree is empty, return the depth of the non-empty subtree
    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;

    // both subtrees are non-empty, return the minimum depth
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

