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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr)
            return nullptr;
        TreeNode* pLastNodeInList=nullptr;
        ConvertCore(pRootOfTree,&pLastNodeInList);
        while(pLastNodeInList!=nullptr&&pLastNodeInList->left!=nullptr)
            pLastNodeInList=pLastNodeInList->left;
        return pLastNodeInList;
    }
    void ConvertCore(TreeNode* pRootOfTree,TreeNode** pLastNodeInList){
        if(pRootOfTree==nullptr)
            return;
        TreeNode* currentNode=pRootOfTree;
        
        if(currentNode->left!=nullptr)
            ConvertCore(currentNode->left,pLastNodeInList);
        
        currentNode->left=*pLastNodeInList;
        
        if(*pLastNodeInList!=nullptr)
            (*pLastNodeInList)->right=currentNode;
        
        currentNode->left=*pLastNodeInList;
        *pLastNodeInList=currentNode;
        
        if(currentNode->right!=nullptr)
            ConvertCore(currentNode->right,pLastNodeInList);
    }
};