/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetricalCore(pRoot,pRoot);
    }
    
    bool isSymmetricalCore(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot1==nullptr&&pRoot2==nullptr)
            return true;
        if(pRoot1==nullptr||pRoot2==nullptr)
            return false;
        if(pRoot1->val!=pRoot2->val)
            return false;
        return isSymmetricalCore(pRoot1->left,pRoot2->right)&&isSymmetricalCore(pRoot1->right,pRoot2->left);
    }

};