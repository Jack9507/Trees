/* 
The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

     vector<long long> nums;
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    nums.push_back(root->data);
    inorder(root->right);
    
    return;
}
	bool checkBST(Node* root) 
    {
        if(root == NULL)          // tree with no nodes is  a bst
            return true;
        if(root->left==NULL && root->right==NULL)    // single node is a bst
            return true;
		inorder(root);
      
        vector<int> mp(10000,0);
        for(int i=0;i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int flag=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp[nums[i]]>1)
                flag=1;      // two nodes have same values
        }
        
        if(flag==1)
            return false;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1])
                 return false;
        }
        return true;
	}
