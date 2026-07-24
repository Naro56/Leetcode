/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
      vector<vector<int>> res ; 
      queue<TreeNode*> q;
      q.push(root);
      bool isRight = true;
      while(!q.empty()){
        vector<int> level;
        int size = q.size();   

        for(int i = 0 ; i <size; i++){
            TreeNode * temp = q.front();
            q.pop();
            if(temp->left !=NULL)q.push(temp->left);
            if(temp->right !=NULL) q.push(temp->right);
            level.push_back(temp->val);
        }
        if(isRight){
            res.push_back(level);
            isRight= false;
        }else{
            reverse(level.begin(), level.end());
            res.push_back(level);
            isRight = true;
        }
      } 
      return res;
        
    }
};