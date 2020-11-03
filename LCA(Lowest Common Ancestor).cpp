#include <bits/stdc++.h>
using namespace std;

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/  
    Node *lca(Node *root, int v1,int v2) 
    {
        if(root==NULL) 
        return NULL;                // no node in BST
        if(root->data == v1 || root->data == v2)  
         return root;          // every node is a descendent of itself
         
        Node *leftLCA =lca(root->left, v1, v2);
        Node *rightLCA =lca(root->right,v1,v2);
        
        if(leftLCA == NULL && rightLCA ==NULL)
        return NULL;
        if(leftLCA != NULL && rightLCA != NULL)
        return root;
        
        
        return (leftLCA != NULL) ? leftLCA : rightLCA;
        
    }

}; //End of Solution
