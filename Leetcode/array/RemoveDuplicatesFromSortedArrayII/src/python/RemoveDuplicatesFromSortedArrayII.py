class Solution(object):
    def removeDuplicates(self, nums):
        if not nums:
            return 0
        
        last,i,same=0,1,False
        while i<len(nums):
            if nums[last]!=nums[i] or not same:
                same=nums[last]==nums[i]
                last+=1;
                nums[last]=nums[i]
            i+=1
        return last+1
if __name__=="__main__":
    print Solution().removeDuplicates([1,1,1,2,2,3])