/**
** 二叉搜索树节点的最近公共祖先
** 就是遍历到的第一个在它们中间的节点
**/

 // * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root) return NULL;
      int larger = p->val > q->val ? p->val: q->val;
      int smaller = p->val < q->val ? p->val: q->val;

      while(root)
      {
        if(root->val < smaller)
        {
          root = root->right;
          continue;
        }

        if (root->val > larger) {
          root = root->left;
          continue;
        }

        // if(root->val == larger
        //   or root->val == smaller
        //   or root->left == p
        //   or root->left == q
        //   or root->right == p
        //   or root->right == q
        // )
        return root;

      }
      return NULL;
    }
};
