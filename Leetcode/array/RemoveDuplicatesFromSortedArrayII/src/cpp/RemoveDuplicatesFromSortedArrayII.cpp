class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0)
            return nums.size();
        int i=0,last=2;
        for (int index=1,temp=0;index<nums.size();index++){
            if (nums[i]!=nums[index]){
                nums[++i]=nums[index];
                temp=0;
            }
            else{
                temp++;
                if (temp<last)
                    nums[++i]=nums[index];
            }
        }
        return i+1;
        
    }
};