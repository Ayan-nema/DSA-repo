#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
 
  struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return BST(preorder,0,preorder.size()-1);
    }
     TreeNode* BST(vector<int>& preorder,int start,int end)
     { if (start>end)return NULL;
        TreeNode* node=new TreeNode(preorder[start]);
        int leftEnd=start+1;
        while(leftEnd<=end && preorder[leftEnd]<node->val){
            leftEnd++;
        }
        node->left=BST(preorder,start+1,leftEnd-1);
        node->right=BST(preorder,leftEnd,end);
        return node;
     } 
}; 