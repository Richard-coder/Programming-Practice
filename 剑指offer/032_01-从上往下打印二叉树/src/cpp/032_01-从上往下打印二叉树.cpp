/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            TreeNode* node=nodeQueue.front();
            nodeQueue.pop();
            res.push_back(node->val);
            if(node->left!=nullptr)
                nodeQueue.push(node->left);
            if(node->right!=nullptr)
                nodeQueue.push(node->right);
        }
        return res;
    }
};