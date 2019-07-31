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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res=false;
        if(pRoot1!=nullptr&&pRoot2!=nullptr){
            if(pRoot1->val==pRoot2->val)
                res=doesTree1HasTree2(pRoot1,pRoot2);
            if(!res)
                res=doesTree1HasTree2(pRoot1->left,pRoot2);
            if(!res)
                res=doesTree1HasTree2(pRoot1->right,pRoot2);
        }
        return res;
    }
    
    bool doesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        if (pRoot2==nullptr)
            return true;
        if (pRoot1==nullptr)
            return false;
        if(pRoot1->val!=pRoot2->val)
            return false;
        return doesTree1HasTree2(pRoot1->left,pRoot2->left)&&doesTree1HasTree2(pRoot1->right,pRoot2->right);
    }
};