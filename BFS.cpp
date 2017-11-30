#include <iostream>
#define size 100
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

class queue{
    node* array[size];
    int front, rear;
    public:
    queue(){
        front = rear = -1;
    }
    node* peek(){
        if(front == -1)
            return NULL;
        return array[front];
    }
    void push(node* root){
        if(rear == size - 1)
            return;
        else if(front == -1){
            front = rear = 0;
            array[rear] = root;
        }
        else
            array[++rear] = root;
    }
    void pop(){
        if(front == -1)
            return;
        else if(front == rear)
            front = rear = -1;
        else
            front++;
    }
    bool isEmpty(){
        if(front == -1)
            return true;
        else
            return false;
    }
};

void BFS(node* root){
    if(root == NULL)
        return;
    queue q;
    q.push(root);
    while(!q.isEmpty()){
        node* temp = q.peek();
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        q.pop();
    }
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
    cout<<"\nBFS: ";
    BFS(root);
    cout<<endl;
    return 0;
}
