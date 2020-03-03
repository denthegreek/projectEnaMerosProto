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
Node* insertRec(Node* root, int key) 
{ 
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
  
    else if (key < y->key){y->left = newnode;y->left->back=y;} 
  
    else{y->right = newnode;y->right->back=y;}
    
    return y; 
} 

Node * minValueNode(Node* node) 
{ 
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

Node* deleteRec(struct Node* root, int key) 
{ 
    if (root == NULL) return root; 
  
    if (key < root->key) 
        root->left = deleteRec(root->left, key); 
  
    else if (key > root->key) 
        root->right = deleteRec(root->right, key); 
  
    else
    { 
        if (root->left == NULL) 
        { 
            Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            Node *temp = root->left; 
            free(root); 
            return temp; 
        } 
   
        Node* temp = minValueNode(root->right); 
  
        root->key = temp->key; 
  
        root->right = deleteRec(root->right, temp->key); 
    } 
    return root; 
} 
//----------------------------------------------------------------------------
int findMax(Node* root)  
{   
    if (root == NULL){return INT_MIN;}
    
    int result = root->key;  
    int leftResult = findMax(root->left);
    int rightResult = findMax(root->right);
    
    if (leftResult > result)
    result = leftResult;  
    
    if (rightResult > result)  
    result = rightResult;
    return result;
}  

int findMin(struct Node* root) 
{ 
    if (root == NULL){return INT_MAX;}
  
    int result = root->key; 
    int leftResult = findMin(root->left); 
    int rightResult = findMin(root->right); 
    if (leftResult < result) 
      result = leftResult; 
    if (rightResult < result) 
      result = rightResult; 
    return result; 
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
    if(root==NULL){cout<<"EMPTY TREE!\n";return root;}
    if( root->key == key){return root;} 
    if(root->key < key){return search(root->right, key);}
    return search(root->left, key); 
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
    root = insertRec(root, rand() % 100 + 1); 
    for(int i=0 ; i<19 ; i++){int x=rand() % 100 + 1; insertRec(root,x);if(i==4){del=x;}if(i==6){src=x;}}
    
    cout<<"----------------------------------------------------------------\n";
    
    print2D(root);
	
	root=deleteRec(root,del);
	
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