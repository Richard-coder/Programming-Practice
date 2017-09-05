class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int >> res;
        for(int i=0;i<nums.size();i++){
            int target=-nums[i];
            int front=i+1;
            int back=nums.size()-1;
            while(front<back){
                int sum=nums[front]+nums[back];
                if(sum>target)
                    back--;
                else if(sum<target)
                    front++;
                else{
                    vector<int> tri(3,0);
                    tri[0]=nums[i];
                    tri[1]=nums[front];
                    tri[2]=nums[back];
                    res.push_back(tri);
                    
                    while(front<back&&nums[front]==tri[1]) front++;
                    while(front<back&&nums[back]==tri[2])  back--;
                    

                }
                while(i+1<nums.size()&&nums[i+1]==nums[i]) i++;
            }
        }
        return res;
    }
};