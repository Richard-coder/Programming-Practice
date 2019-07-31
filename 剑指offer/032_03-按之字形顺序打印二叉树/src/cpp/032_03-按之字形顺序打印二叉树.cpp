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
        vector<int> v;
        stack<TreeNode*> s[2];
        int current=0;
        int next=1;
        s[current].push(pRoot);
        while(!s[0].empty()||!s[1].empty()){
            TreeNode* node=s[current].top();
            v.push_back(node->val);
            s[current].pop();
            
            if(current==0){
                if(node->left!=nullptr)
                    s[next].push(node->left);
                if(node->right!=nullptr)
                    s[next].push(node->right);
            }else{
                if(node->right!=nullptr)
                    s[next].push(node->right);
                if(node->left!=nullptr)
                    s[next].push(node->left);
            }
            
            if(s[current].empty()){
                res.push_back(v);
                vector<int> ().swap(v);
                current=1-current;
                next=1-next;
            }
        }
        
        return res;
        
    }
    
};