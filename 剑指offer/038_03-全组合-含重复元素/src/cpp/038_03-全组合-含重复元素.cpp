class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        ans.push_back(v);
        int right = 1, left = 0, len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && (nums[i] == nums[i-1])) left = ans.size() - len;
            else left = 0;
            right = ans.size();
            len = right - left;
            for (int j = left; j < right; ++j) {
                v = ans[j];
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};