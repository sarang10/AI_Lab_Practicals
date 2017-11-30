#include <iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

node* newNode(int data){
    node* root = new node;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void DFS(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    DFS(root->left);
    DFS(root->right);
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<"The binary tree is:-\n";
    cout<<"     1 \n";
    cout<<"    / \\ \n";
    cout<<"   2   3 \n";
    cout<<"  / \\ / \\ \n";
    cout<<" 4  5 6  7 \n";
    cout<<"\nDFS: ";
    DFS(root);
    cout<<endl;
    return 0;
}
