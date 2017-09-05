class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            int numberToFind=target-nums[i];
            if(hash.find(numberToFind)!=hash.end()){
                ret.push_back(hash[numberToFind]);
                ret.push_back(i);
                return ret;
            }
            hash[nums[i]]=i;
        }
        return ret;
    }
};