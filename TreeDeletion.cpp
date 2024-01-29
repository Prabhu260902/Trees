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

void DeletionAtLeaf(Node* root,int val,Node* parent,int flag){
    if(root == NULL) return;
    Node* temp = root;
    if(temp->left == NULL and temp->right == NULL and temp->data == val){
        if(flag) parent->right = NULL;
        else parent->left = NULL;
        return;
    }
    DeletionAtLeaf(root->left,val,root,0);
    DeletionAtLeaf(root->right,val,root,1);
}



int FindLeftData(Node* root){
    if(root == NULL) return -1;
    if(root->left == NULL and root->right == NULL) return root->data;
    else return FindLeftData(root->right);
}


int FindRightData(Node* root){
    if(root == NULL) return -1;
    if(root->left == NULL and root->right == NULL) return root->data;
    else return FindLeftData(root->left);
}

void DeleteNode(Node* root,int val,Node* parent,int flag){
    if(root == NULL) return;
    if(root->data == val){
        int leaf_data = FindLeftData(root->left);
        if(leaf_data == -1){
            leaf_data = FindRightData(root->right);
            if(leaf_data == -1){
                if(flag) parent->right = NULL;
                else parent->left = NULL;
                return;
            }
            root->data = leaf_data;
            DeletionAtLeaf(root->right,leaf_data,root,1);
        }
        else{
            root->data = leaf_data;
            DeletionAtLeaf(root->left,leaf_data,root,0);
        }
        return;
    }
    DeleteNode(root->left,val,root,0);
    DeleteNode(root->right,val,root,1);
}


int main(){
    vector<int>arr = {1,2,3,4,5,6,7};
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


    DeleteNode(head,1,NULL,-1);

    levelOrder(head);
    cout << endl;

} 
