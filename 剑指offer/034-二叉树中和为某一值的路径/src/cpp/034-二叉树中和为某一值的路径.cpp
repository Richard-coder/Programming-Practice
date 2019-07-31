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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        vector<int> path;
        int currentSum=0;
        FindPathCore(root,expectNumber,res,path,currentSum);
        return res;
    }
    
    void FindPathCore(TreeNode* root,int expectNumber,vector<vector<int>>& res, vector<int>& path,int currentSum){
        path.push_back(root->val);
        currentSum+=root->val;
        //如果是叶节点, 并且路径上节点值的和等于输入值,则保存路径
        bool isLeaf=(root->left==nullptr&&root->right==nullptr);
        if(currentSum==expectNumber&&isLeaf){
            res.push_back(path);
        }
        //如果不是叶节点, 则遍历其子节点
        if(root->left!=nullptr){
            FindPathCore(root->left,expectNumber,res,path,currentSum);
        }
        if(root->right!=nullptr){
            FindPathCore(root->right,expectNumber,res,path,currentSum);
        }
        // path需要pop_back而currentSum不需要减去root->val的原因是, 前者是传引用, 后者是传值
        path.pop_back();
    }
};