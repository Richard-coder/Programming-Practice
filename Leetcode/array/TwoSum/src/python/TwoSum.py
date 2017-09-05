class Solution(object):
    def twoSum(self,nums,target):
        if len(nums)<=1:
            return False
        buff_dict={}
        for i in xrange(len(nums)):
            if nums[i] in buff_dict:
                return [buff_dict[nums[i]],i]
            else:
                buff_dict[target-nums[i]]=i

if __name__ =="__main__":
    print Solution().twoSum((3,5,9,13,15),20)