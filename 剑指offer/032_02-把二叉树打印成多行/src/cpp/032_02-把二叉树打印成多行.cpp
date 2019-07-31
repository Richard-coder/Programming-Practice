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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if(pRoot==nullptr)
                return res;
            int currentLevelNum=1;
            int nextLevelNum=0;
            queue<TreeNode*> nodeQueue;
            nodeQueue.push(pRoot);
            vector<int> level;
            while(!nodeQueue.empty()){
                TreeNode* node=nodeQueue.front();
                nodeQueue.pop();
                currentLevelNum--;
                level.push_back(node->val);
                
                if(node->left!=nullptr){
                    nodeQueue.push(node->left);
                    nextLevelNum++;
                }
                
                if(node->right!=nullptr){
                    nodeQueue.push(node->right);
                    nextLevelNum++;
                }
                
                if(currentLevelNum==0){
                    res.push_back(level);
                    vector<int>().swap(level);
                    currentLevelNum=nextLevelNum;
                    nextLevelNum=0;
                }
            }
            
            return res;
        }
    
};