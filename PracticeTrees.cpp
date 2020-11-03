#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;   //self referencing
};

node* addnode(int x)      // returns a node with data "x" in it.
{
    node *newnode= new node;
    newnode -> data = x;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

node* buildTree(node *root)
{
    int x;
    cin>>x;
    if(x==-1)
        return NULL;

    if(root==NULL)
       root = addnode(x);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void preorder(node *root)
{
    if(root == NULL)
        return;

    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}
int height(node *root)
{
    if(root == NULL)
        return -1;
    int leftsubtree = height(root->left);
    int rightsubtree = height(root->right);

    return 1+ max(leftsubtree, rightsubtree);
}

int sumofnodes(node *root)
{
    if(root == NULL)
        return 0;
    int leftsum = sumofnodes(root->left);
    int rightsum = sumofnodes(root->right);

    return leftsum+rightsum+root->data;
}

bool searchinTree(node *root, int x)
{
    if(root == NULL)
        return false;

    if(root->data == x)
        return true;

    bool leftsubtree = searchinTree(root->left, x);
    bool rightsubtree = searchinTree(root->right, x);

    if(leftsubtree || rightsubtree)
        return true;
    else
        return false;
}

int diameter(node * root)
{
    if(root == NULL)
        return 0;

    int leftdia = diameter(root->left);
    int rightdia = diameter(root->right);

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    int merethrough = leftheight + rightheight + 2;

    return max(merethrough , max(leftdia, rightdia));
}

bool isBalanced(node * root)
{
    if(root == NULL)
        return true;

    bool lefttree = isBalanced(root->left);
    bool righttree = isBalanced(root->right);

    if(lefttree == false || righttree == false)
        return false;

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    int gap =abs(leftheight - rightheight);

    if(gap>1)
        return false;
    else
        return true;

}



vector<vector<int> > levelOrder(node *root)
{

}



void bfs(node *root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node *tmp= q.front();
        q.pop();
        cout<<tmp->data<<"  ";

        if(tmp->left != NULL)
            q.push(tmp->left);
        if(tmp->right != NULL)
            q.push(tmp->right);
    }

}

node * levelorderInsertion(node *root, int x)
{
    if(root == NULL)
        return addnode(x);
    queue<node* > q;
    q.push(root);

    while(!q.empty())
    {
        node *tmp =q.front();
        q.pop();

        if(tmp->left == NULL)
        {
            tmp->left = addnode(x);
            break;
        }
        else
            q.push(tmp->left);

        if(tmp->right == NULL)
        {
            tmp->right =addnode(x);
            break;
        }
        else
            q.push(tmp->right);
    }
    return root;

}

node* lowestcommonAncestor(node *root, int p, int q)
{
    if(root == NULL)
        return NULL;
    if(root->data == p || root->data == q)
        return root;

    node *leftLCS= lowestcommonAncestor(root->left, p ,q);
    node *rightLCS= lowestcommonAncestor(root->right, p,q);

    if(leftLCS == NULL && rightLCS == NULL)
      return NULL;
    if(leftLCS != NULL && rightLCS !=NULL)
        return root;

    return  leftLCS !=NULL ? leftLCS : rightLCS ;
}
//
//int maxPathSum(node * root)
//{
//
//
//}


int maxPath;

int helper(node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftMax = helper(root->left);
	int rightMax = helper(root->right);

	leftMax = max(0, leftMax);
	rightMax = max(0, rightMax);

	int mereThrough = leftMax + rightMax + root->data;

	maxPath = max(maxPath, mereThrough);

	return max(leftMax, rightMax) + root->data;
}

int maxPathSum(node* root) {

	maxPath = INT_MIN;
	helper(root);
	return maxPath;
}
int main()
{
    node * root = NULL;
//   root =  buildTree(root);
//    cout<<endl;
//    preorder(root);
//    cout<<endl;
//    cout<<"height of tree = "<<height(root)<<endl;
//    cout<<"sum of nodes = "<<sumofnodes(root)<<endl;
//    cout<<"search in tree  = "<<searchinTree(root, 2)<<endl;
//    cout<<"Diameter of the  tree  = "<<diameter(root)<<endl;
//    cout<<"Balancing of the  tree  = "<<isBalanced(root)<<endl;
//
//
       int arr[7];

       for(int i=1;i<=7;i++)
       {
           root= levelorderInsertion(root,i);
       }

    cout<<endl<<"BFS traversal: - "<<endl;
    bfs(root);
    cout<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Lowest common Ancestor = "<<lowestcommonAncestor(root, 6,7)->data<<endl;

    cout<<"Max path sum = "<<maxPathSum(root)<<endl;




}


