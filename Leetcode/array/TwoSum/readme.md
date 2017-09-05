# 1. Two Sum

tags： Array, Hash Table

---

## 题目原文
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.

Example:

Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

UPDATE (2016/2/13):

The return format had been changed to zero-based indices. Please read the above updated description carefully.
## 题目大意
n这道题目的意思是给定一个数组和一个值， 让求出这个数组中两个值的和等于这个给定值的坐
标。 输出是有要求的， 1， 坐标较小的放在前面， 较大的放在后面。 2， 这俩坐标从0开始计数。



## 解题思路
第一步： 我们要分析题意， 其中有三个关键点：
1. 求出来的坐标值要按序排列。
2. 这两个坐标从零开始。
3. 这道题目假设是只有一组答案符合要求， 这样降低了我们解题的难度。

根据题目我们可以得到以下信息：
1. 我们得到坐标的时候， 要根据大小的顺序放入数组。
2. 因为有且只有一组答案符合要求， 所以这大大的降低了这道题目的难度， 也就是说， 我们只要找到符
合条件的两个数， 存入结果， 直接终止程序， 返回答案即可。


这道题不是很难， 是leetcode最开始的题目， 要求很明确， 很直接， 如果我们用两个for循环，
O(n2)的时间复杂度去求解的话， 很容易计算出来， 但这明显不是面试官需要的答案。 brute force只有在你
不知道如何优化题目的时候， 将就的给出的一个解法。 。 那么我们能不能用O(n)的时间复杂度去解这道题
呢？很显然是可以的， 不过， 天下没有掉馅饼的事情啦， 既然优化了时间复杂度， 我们就要牺牲空间复杂
度啦。 在这里用什么呢？stack？queue？vector？还是hash_map?
对于stack和queue， 除了pop外， 查找的时间复杂度也是O(n)。 明显不是我们所需要的， 那么什么数据结构
的查找时间复杂度小呢？很显然是 hash_map, 查找的时间复杂度理想情况下是O(1)。 



## 代码
### [c++代码](./src/cpp/TwoSum.cpp)
```c++
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
```

### [python代码](./src/python/TwoSum.py)
```python
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
```
