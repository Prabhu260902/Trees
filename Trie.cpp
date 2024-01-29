#include<bits/stdc++.h>
using namespace std;
struct trie{
	trie* links[26];
	bool flag=false;
};

trie* root;

void insert(string s){
	trie* temp=root;
	for(auto i:s){
		if(temp->links[i-'a']==NULL) temp->links[i-'a']=new trie();
		temp=temp->links[i-'a'];
	}
	temp->flag=true;
}

bool search(string s){
	trie* temp=root;
	for(auto i:s){
		if(temp->links[i-'a']==NULL) return false;
		temp=temp->links[i-'a'];
	}
	return temp->flag;
}

bool startsWith(string s){
	trie* temp=root;
	for(auto i:s){
		if(temp->links[i-'a']==NULL) return false;
		temp=temp->links[i-'a'];
	}
	return true;
}



int main(){
	root=new trie();
	vector<string>a={"cat","cats","and","sand","dog"};
	for(auto i:a) insert(i);
	cout<<search("and")<<endl;
	cout<<startsWith("an")<<endl;

}
