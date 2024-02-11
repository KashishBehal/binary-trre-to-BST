class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
      void PreOrder(Node *root,vector<int> &vec){
        if(root){
            vec.push_back(root->data);
            PreOrder(root->left,vec);
            PreOrder(root->right,vec);
        }
    }
    void InOrderUpdate(Node *root,vector<int> &vec,int &i){
        if(root){
            InOrderUpdate(root->left,vec,i);
            root->data = vec[i++];
            InOrderUpdate(root->right,vec,i);
        }
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> vec;
        PreOrder(root,vec);
        sort(vec.begin(),vec.end());
        int x = 0;
        InOrderUpdate(root,vec,x);
        return root;

    }
};
