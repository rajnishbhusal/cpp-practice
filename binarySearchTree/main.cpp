#include<iostream>
#include<vector>
using namespace std;
#define COUNT 10

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
        }
};

class bsTree{
    public:
        Node* root;

        bsTree(){
            root = NULL;
        }

        ~bsTree(){
            delete root;
        }

        void insertHelper(Node** node, int data){
            if (*node == NULL){
                *node = new Node(data);
            }
            else{
                if (data<(*node)->data){
                    insertHelper(&(*node)->left, data);
                }
                else{
                    insertHelper(&(*node)->right, data);
                }
            }

        }

        void insertNode(int data){
            insertHelper(&root, data);
        }

        // Function to print binary tree in 2D
        // It does reverse inorder traversal
        void print2DUtil(Node* node, int space){
            // Base case
            if (node == NULL){
                return;
            }
 
            // Increase distance between levels
            space += COUNT;
 
            // Process right child first
            print2DUtil(node->right, space);
 
            // Print current node after space count
            cout<<endl;
            for (int i = COUNT; i < space; i++)
                cout<<" ";
            cout<<node->data<<"\n";
 
            // Process left child
            print2DUtil(node->left, space);
        }

        // Wrapper over print2DUtil()
        void print2D(Node* root){
            // Pass initial space count as 0
            print2DUtil(root, 0);
        }

        void printbsTree(Node* node){
            if (node==NULL){
                return;
            }
            cout<< node->data;
            printbsTree(node->left);
            printbsTree(node->right);
        }

};


int main(){
    vector<int> dataVec = {10, 8, 7, 9, 12, 15};
    bsTree tree;
    for (int data:dataVec){
        tree.insertNode(data);
    }
    
    tree.print2D(tree.root);

    return 0;
}