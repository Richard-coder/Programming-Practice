class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return res;
        res.push_back(v);
        for(int i=1;i<=nums.size();i++){
            subsetsCore(nums,0,i);
        }
        return res;
    }
private:
    void subsetsCore(vector<int>& nums,int begin,int m){
        if(m==0){
            res.push_back(v);
            return;
        }
        if(begin==nums.size()){
            return;
        }
        v.push_back(nums[begin]);
        subsetsCore(nums,begin+1,m-1);
        v.pop_back();
        subsetsCore(nums,begin+1,m);
           
    }
    vector<int> v;
    vector<vector<int>> res;
};