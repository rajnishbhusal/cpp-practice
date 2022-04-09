#include<iostream>
using namespace std;

// Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1 
// Preorder Output: 1 2 4 5 7 3 6

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }

        ~Node(){
            delete left;
            delete right;

            cout<< "Deleting node" << data;
        }
};

Node* buildTree(){
    int data;
    cin>> data;

    if (data == -1){
        return NULL;
    }

    Node* n = new Node(data);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printPreorder(Node* root){
    if (root==NULL){
        return;
    }
    cout<< root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node* root){
    if (root==NULL){
        return;
    }
    printInorder(root->left);
    cout<< root->data << " ";
    printInorder(root->right);
}

void printPostorder(Node* root){
    if (root==NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<< root->data << " ";
}

int main(){
    Node* root = buildTree();
    //printPreorder(root); 
    //printInorder(root); 
    printPostorder(root);  
    return 0;
}