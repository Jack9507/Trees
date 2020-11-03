
string helper(node *root, string str)
{
    if(root== NULL || str.length()==0)
    return NULL;
    
    string ans="";
    node *curr=root;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='0')
           curr =curr->left;
        else
           curr=curr->right;
        
        if(curr->left==NULL && curr->right==NULL)
        {
            // reached leaf node
            ans+=curr->data;
            curr=root;
        }
    }
    return ans;
}
void decode_huff(node * root, string str) 
{
    string res =helper(root, str);
    cout<<res<<endl;
    
}


Problem link:  https://www.hackerrank.com/challenges/tree-huffman-decoding/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=trees
