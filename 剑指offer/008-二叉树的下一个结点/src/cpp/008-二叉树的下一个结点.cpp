/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; //parent
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==nullptr) return nullptr;
        TreeLinkNode* pNext=nullptr;
        if(pNode->right!=nullptr){
            pNode=pNode->right;
            while(pNode->left!=nullptr)
                pNode=pNode->left;
            pNext=pNode;
        }
        // 我的写法将第二种情况的两小种情况合二为一, 并且可以完美处理输入节点为根节点,或者为最后一个节点的情况.
        else{
            while(pNode->next!=nullptr&&pNode==pNode->next->right)
                pNode=pNode->next;
            pNext=pNode->next;
        }
        return pNext;
    }
};