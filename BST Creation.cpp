#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

Node* create(Node* root,int val){
    if(root == NULL) return new Node(val);
    if(val < root->data) root->left = create(root->left,val);
    else root->right = create(root->right,val);
    return root;
}


int main(){
    vector<int>arr = {1,2,4,3,5,6,7};

    Node* root = NULL;
    for(auto it:arr){
        root = create(root,it);
    }

    inorder(root);
    cout << endl;

} 
