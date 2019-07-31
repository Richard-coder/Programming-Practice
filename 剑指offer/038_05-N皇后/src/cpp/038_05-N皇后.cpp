class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n<=0)
            return res;
        vector<int> nums;
        nums.resize(n);
        for(int i=0;i<n;i++)
            nums[i]=i;
        solveNQueensCore(nums,0);
        return res;
    }
    
    void solveNQueensCore(vector<int> &nums, int begin){
        if(begin==nums.size()){
            if(check(nums))
                draw(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[begin],nums[i]);
            solveNQueensCore(nums,begin+1);
            swap(nums[begin],nums[i]);
        }
        
    }
    
    bool check(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j)
                    continue;
                if(fabs(nums[i]-nums[j])==j-i){
                    return false;
                }
            }
        }
        return true;
    }
    
    void draw(vector<int>& nums){
        string temp(nums.size(),'.');
        vector<string> v(nums.size(),temp);
        for(int i=0;i<nums.size();i++){
            v[nums[i]][i]='Q';
        }
        res.push_back(v);
        
    }
    vector<vector<string>> res;
    

};