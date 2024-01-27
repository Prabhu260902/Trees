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


int main(){
    vector<int>arr = {1,2,3,-1,5,6,7};
    queue<pair<Node*,int>>q;
    Node* head = new Node(arr[0]);
    q.push({head,0});
    while(!q.empty()){
        Node* temp = q.front().first;
        int ind = q.front().second * 2;
        q.pop();
        if(ind+1 < arr.size() and arr[ind+1] != -1){
            temp->left = new Node(arr[ind+1]);
            q.push({temp->left,ind+1});
        }
        if(ind+2 < arr.size() and arr[ind+2] != -1){
            temp->right = new Node(arr[ind+2]);
            q.push({temp->right,ind+2});
        }
    }

    inorder(head);
} 
