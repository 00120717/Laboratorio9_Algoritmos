#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
struct node
{
int key;
struct node *left, *right;
};
// A utility function to create a new BST node
struct node *newNode(int item)
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d \n", root->key);
inorder(root->right);
}
}
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
/* If the tree is empty, return a new node */
if (node == NULL) return newNode(key);
/* Otherwise, recur down the tree */
if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
/* return the (unchanged) node pointer */
return node;
}

//Encontrar el LCA
node* LCA(node * root, int n1,int n2) 
{ 
    // Your code here 
    if (root == NULL) 
       return root; 
    if (root->key == n1 || root->key == n2) 
       return root; 
  
    node* left = LCA(root->left, n1, n2); 
    node* right = LCA(root->right, n1, n2); 
  
    if (left != NULL && right != NULL) 
         return root; 
    if (left != NULL) 
        return LCA(root->left, n1, n2); 
  
    return LCA(root->right, n1, n2); 
}

//funcion encontrar distancia entre dos nodos
int findDistance(nodo* root, int a, int b){
    nodo* lca = LCA(root,a,b);
    
}

// Driver Program to test above functions
int main()
{
    node * root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->left = newNode(13); 
    
    cout << "ancestro entre 1 y 13 es " << LCA(root, 1, 13)->key<<endl; 
    cout << "ancestro entre 1 y 6 es " << LCA(root, 1, 6)->key<<endl; 
return 0;
}
