
/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// returns the inorder successor of the Node x in BST (rooted at 'root')

Node *getleftmost(Node *x)        // returns the left most node 
 {
     if(x->left==NULL)
      return x;
     else
      getleftmost(x->left);
 }

Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    if(x == NULL)  return NULL;
    
    if(x->right != NULL) // if right child exists go right
      {
         return getleftmost(x->right);          // return min in the right most subtree
      }
      
      Node *succ=NULL;
      while(root != NULL)
       {
           if(x->data < root->data) 
            {
                // ans exists in left subtree
                succ =root;
                root =root->left;
            }
           else if(x->data > root->data)
            {
                // ans exists in right subtree
                root=root->right;
            }
            else
             break;
       }
      
      return succ;
}

Complexity Analysis: 

Time Complexity: O(h), where h is the height of the tree. 
In the worst case as explained above we travel the whole height of the tree
Auxiliary Space: O(1). 
Due to no use of any data structure for storing values.
