#include <iostream>

using namespace std;

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

bool search(Node* root, int key) 
{ 
    while (root != NULL) { 
        if (key > root->key) 
            root = root->right; 
  
        else if (key < root->key) 
            root = root->left; 
        else
            return true; 
    } 
    return false; 
} 

void getRandomArray(int n){
    int count=0;
    int arr[n];
    Node* root = NULL; 
    if(n>0){root = insertRec(root, rand());arr[count]=root->key;count++;} 
    for(int i=1 ; i<n ; i++){
        int x=rand(); 
        if(!search(root,x)){
            insertRec(root,x);
            arr[count]=x;
            count++;
        }
        else{
            while(search(root,x)){x=rand();}
            insertRec(root,x);
            arr[count]=x;
            count++;
        }
    }
    
    for(int i=0; i<count; i++){cout<<arr[i]<<" ";}
    cout<<endl;

}

int main()
{
    int n;
    int count=0;
    cout<<"Give n for arr[n]:\n";
    cin>>n;
    getRandomArray(n);

    return 0;
}
