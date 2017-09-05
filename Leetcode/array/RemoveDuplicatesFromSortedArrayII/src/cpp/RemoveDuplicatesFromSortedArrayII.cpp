class Solution {
public:
        int removeDuplicates(vector<int>& nums) {
                int k=2,i=0;
                if (nums.size()<=k)
                        return nums.size();
                int num=0;
                for(int index=1;index<nums.size();index++)
                {
                        if (nums[i]==nums[index])
                        {
                                num++;
                                if (num<k)
                                {
                                        nums[++i]=nums[index];
                                }
                        }
                        else
                                {
                                        nums[++i]=nums[index];
                                        num=0;
                                }
                }

                return i+1;
        }
};