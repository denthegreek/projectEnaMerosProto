#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 
//----------------------------------------------------------------------------
struct Node { 
    int key; 
    struct Node *left, *right, *back; 
}; 
  
Node* newNode(int data) 
{ 
    Node* temp = new Node; 
  
    temp->key = data; 
  
    temp->left = NULL; 
    temp->right = NULL;
    temp->back = NULL;
  
    return temp; 
} 
//----------------------------------------------------------------------------
void print2DUtil(Node *root, int space)  
{  
    int COUNT= 5;
    if (root == NULL)  
        return;  
  
    space += COUNT;  
  
    print2DUtil(root->right, space);  
  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->key<<"\n";  
  
    print2DUtil(root->left, space);  
}  
  
void print2D(Node *root)  
{  
    print2DUtil(root, 0);  
}  
//----------------------------------------------------------------------------
Node* insertIter(Node* root, int key) { 
    Node* newnode = newNode(key); 
    Node* x = root; 
    Node* y = NULL; 
  
    while (x != NULL) { 
        y = x; 
        if (key < x->key) 
            x = x->left; 
        else
            x = x->right; 
    } 
  

    if (y == NULL) 
        y = newnode; 
    else if (key < y->key) 
        y->left = newnode; 
    else
        y->right = newnode; 
    return y; 
} 
//----------------------------------------------------------------------------
Node* minimumKey(Node* curr)
{
	while(curr->left != nullptr) {
		curr = curr->left;
	}
	return curr;
}

void searchKey(Node* &curr, int key, Node* &parent)
{
	while (curr != nullptr && curr->key != key)
	{
		parent = curr;

		if (key < curr->key)
			curr = curr->left;
		else
			curr = curr->right;
	}
}

void deleteIter(Node*& root, int key)
{
	Node* parent = nullptr;

	Node* curr = root;

	searchKey(curr, key, parent);

	if (curr == nullptr)
		return;

	if (curr->left == nullptr && curr->right == nullptr)
	{
		if (curr != root)
		{
			if (parent->left == curr)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		else
			root = nullptr;
		free(curr);	 
	}
	else if (curr->left && curr->right)
	{
		Node* successor  = minimumKey(curr->right);
		int val = successor->key;
		deleteIter(root, successor->key);
		curr->key = val;
	}

	else
	{
		Node* child = (curr->left)? curr->left: curr->right;

		if (curr != root)
		{
			if (curr == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}
		else
			root = child;
		free(curr);
	}
}
//----------------------------------------------------------------------------
int findMax(Node* root)  
{   
    if (root == NULL){return INT_MAX;}
    
    while(root->right!=NULL){root=root->right;}
    return root->key;
}  

int findMin(struct Node* root) 
{ 
    if (root == NULL){return INT_MAX;}
    
    while(root->left!=NULL){root=root->left;}
    return root->key;
}
//----------------------------------------------------------------------------
void Inorder(Node* root) 
{ 
    if (root == NULL) 
        return; 
    else { 
        Inorder(root->left); 
        cout << root->key << " "; 
        Inorder(root->right); 
    } 
} 
//----------------------------------------------------------------------------
Node* search(Node* root, int key) 
{ 
    while (root != NULL) { 
        if (key > root->key) 
            root = root->right; 
  
        else if (key < root->key) 
            root = root->left; 
        else
            return root; 
    } 
    return root; 
} 
//----------------------------------------------------------------------------
Node * findNextRec(Node *root, Node *n) 
{ 
    if( n->right != NULL ) 
        return search(root,findMin(n->right));
  
    Node *successor = NULL; 
  
    while (root != NULL) 
    { 
        if (n->key < root->key) 
        { 
            successor = root; 
            root = root->left; 
        } 
        else if (n->key > root->key) 
            root = root->right; 
        else
           break; 
    } 
  
    return successor; 
} 

//----------------------------------------------------------------------------
int main() 
{ 
	int del;
	int src;
    Node* root = NULL; 
    root = insertIter(root, rand() % 100 + 1); 
    for(int i=0 ; i<9 ; i++){int x=rand() % 100 + 1; insertIter(root,x);if(i==4){del=x;}if(i==6){src=x;}}
    
    cout<<"----------------------------------------------------------------\n";
    
    print2D(root);
	
	deleteIter(root,del);
	
	cout<<"Deleting: "<<del<<"----------------------------------------------------------------\n";
    
    print2D(root);
	
	cout<<"----------------------------------------------------------------\n";
	
	cout<<"Max:\t"<<findMax(root)<<endl;
	cout<<"Min:\t"<<findMin(root)<<endl;
	
	cout<<"----------------------------------------------------------------\n";
	Node* some= findNextRec(root,search(root,src));
	cout<<"Going through findNextRec("<<src<<"):\n";
	if(some!=NULL){cout<<"Searching for "<<src<<". \nNext would be "<<some->key<<"."<<endl;}
	
    return 0; 
} 