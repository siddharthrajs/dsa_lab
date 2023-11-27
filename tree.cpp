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

node* buildTree(node* root);
void inorderPrint(node* root);
void preorderPrint(node* root);
void postorderPrint(node* root);
node* buildTree_inpre(int in[], int pre[], int start, int end);
node* buildTree_inpost(int in[], int pre[], int start, int end);

int main() {

    /* For testing buildTree();
    node* root = NULL;
    root = buildTree(root);

    postorderPrint(root);
    cout << endl;
    */

    /* // For testing buildTree_inpre();
    int inorder[] = {52,51, 53, 50, 55, 54};
    int preorder[] = {50, 51, 52, 53, 54, 55};
    node* root = NULL;
    root = buildTree_inpre(inorder, preorder, 0, 5);

    inorderPrint(root);
    cout << endl;
    */

   // For testing buildTree_inpost()
   int inorder[] = {52,51, 53, 50, 55, 54};
   int postorder[] = {52, 53, 51, 55, 54, 50};
   node* root = buildTree_inpost(inorder, postorder, 0, 5);
   inorderPrint(root);
   cout << endl;

}

node* buildTree(node* root) {

    // take input
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    // termination case
    if (data == -1) return NULL;

    // make node
    root = new node(data);

    // take input and make left of node
    cout << "Enter the left data of " << data << endl;
    root->left = buildTree(root->left);

    // take input and make right of node
    cout << "Enter the right data of " << data << endl;
    root->right = buildTree(root->right);

    // return root
    return root;

}

void inorderPrint(node* root) {

    // base case
    if (root == NULL) return;

    // recursive cases
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);

}
void preorderPrint(node* root) {

    // base case
    if (root == NULL) return;

    // recursive cases
    cout << root->data << " ";
    inorderPrint(root->left);
    inorderPrint(root->right);

}
void postorderPrint(node* root) {

    // base case
    if (root == NULL) return;

    // recursive cases
    inorderPrint(root->left);
    inorderPrint(root->right);
    cout << root->data << " ";

}

int search(int in[], int start, int end, int key) {

    for (int i = start; i <= end; i++) {
        if (in[i] == key) return i;
    }
    return -1;
}

node* buildTree_inpre(int in[], int pre[], int start, int end) {


    // set index to first element
    static int idx = start;

    // base case
    if (start > end) return NULL;

    // make pre[index] element as root and update index
    int curr = pre[idx++];
    node* root = new node(curr);

    // base case2
    if (start == end) return root;

    // search pre[index] element in inorder[]
    int pos = search(in, start, end, curr);

    // recursive call for left
    root->left = buildTree_inpre(in, pre, start, pos-1);

    // recursive call for right
    root->right = buildTree_inpre(in, pre, pos+1, end);

    return root;

}

node* buildTree_inpost(int in[], int post[], int start, int end) {


    // set starting index as end
    static int idx = end;

    if (start > end) return NULL;

    // make the pre[index] element as root and update index
    int curr = post[idx];
    idx--;
    node* root = new node(curr);

    if (start == end) return root;

    // search pre[index] element in inorder[]
    int pos = search(in, start, end, curr);

    // recursive right
    root->right = buildTree_inpost(in, post, pos+1, end);

    // recursive left
    root->left = buildTree_inpost(in, post, start, pos-1);

    return root;

}

