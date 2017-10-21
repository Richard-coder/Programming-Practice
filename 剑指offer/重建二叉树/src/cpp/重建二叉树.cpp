/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //判断两个序列长度是否相等,不相等则出错
        if(pre.size()!=vin.size())
            return NULL;
        int length = pre.size();
        //判断序列长度是否为0，为0是有可能是输入错误，也有可能是空的子树
        if (length==0)
            return NULL;
        int rootValue= pre[0];
        TreeNode *root=new TreeNode(rootValue);
        
        //找到中序遍历中根节点的位置
        int rootIndex=0;
        for(;rootIndex<length;rootIndex++)
            if (rootValue==vin[rootIndex])
                break;
        //判断根节点索引是否越界，越界则说明没有根节点，出错
        if (rootIndex>=length)
            return NULL;
        int leftLenghth=rootIndex,rightLength=length-rootIndex-1;
        vector<int> preLeft(leftLenghth),preRight(rightLength);//长度为0时。则初始化为空的容器
        vector<int> vinLeft(leftLenghth),vinRight(rightLength);
        for (int i=0;i<length;i++){
            if (i<rootIndex){
                preLeft[i]=pre[i+1];
                vinLeft[i]=vin[i];
            }
            if (i>rootIndex){
                preRight[i-rootIndex-1]=pre[i];
                vinRight[i-rootIndex-1]=vin[i];
            }
        }
        root->left=reConstructBinaryTree(preLeft,vinLeft);
        root->right=reConstructBinaryTree(preRight,vinRight);
        return root;
        
    }
};