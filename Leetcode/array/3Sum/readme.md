# 15. 3Sum

tags： Array, Two Pointers

---

## 题目原文
[原文地址](https://leetcode.com/problems/3sum/description/)

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:

    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]

## 题目大意
给定一个整型数组num， 找出这个数组中满足这个条件的所有数字： num[i]+num[j]+num[k] = 0. 并且所有
的答案是要和其他不同的， 也就是说两个相同的答案是不被接受的。
题目的两点要求：
1. 每个答案组里面的三个数字是要从大到小排列起来的。
2. 每个答案不可以和其他的答案相同。 



## 解题思路
### 网上分析1

题目分析：

1. 每一个答案数组triplet中的元素是要求升序排列的。
2. 不能包含重复的答案数组。

解题思路：
1. 根据第一点要求： 因为要求每个答案数组中的元素是升序排列的， 所以在开头我们要对数组进行排
序。
2. 根据第二点要求： 因为不能包含重复的答案数组， 所以我们要在代码里面做一切去掉重复的操作， 对
于数组， 这样的操作是相同的。 最开始我做leetcode的时候是把所有满足条件的答案数组存起来， 之后
再用map进行处理， 感觉那样太麻烦了， 所以这次给出的答案是不需要额外空间的。

时间复杂度分析：
对于这道题， 因为是要找三个元素， 所以怎样都要O(n2)的时间复杂度， 目前我没有想出来O(n)时间复杂度
的解法。

归根结底， 其实这是two pointers的想法， 定位其中两个指针， 根据和的大小来移动另外一个。 解题中要
注意的就是一些细节问题。 好了， 上代码吧。

### 网上分析2

这个题目核心思想与 TwoSum, 当第一个数字固定后, 第二个数字和第三个数字就可以采用和TwoSum问题差不多的方法. 不同的是 TwoSum 问题只有一个确定的解, 这个问题却可能有多个解

这个问题还有一点是要解决数组中可能有重复的元素造成重复解的问题, 直觉上的想法是用STL: 

```c++
std::sort(res.begin(), res.end());
res.erase(unique(res.begin(), res.end()), res.end());
```

但根据提交的结果分析, 采用上面的方法耗时较长. 比较好的方法是在遍历数据的时候, 就剔除重复数据, 无论这个数据是否是可行解的一部分.

### 我的分析：

主要是先将原数组排序，并充分利用排序好的数组的特性。去除重复答案的方法是，先按index从小到大确定第一个元素，在按（bengin=index）++和（end）--的顺序确定第二个元素和第三个元素，当begin=begin+1是跳过，end同理，第一个元素的所有可能循环完成后，index++之前也要判断index是否等于index+1。总而言之就是利用排序号数组特性保证每个元素都各不相同。先确定答案中最小的数，防止答案中出现重复的组合

具体思路:

1. 先用`std::sort`将原数组按升序排列
2. 基本思路是定位第一个元素, 然后用两个指针分别指向数组剩余部分的头部和尾部, 根据两个指针指向数字的和移动指针.

## 加速的小技巧

    if(target < 0)
    {
    	break;
    }
    # 这个实用性不是很强
    if(num[back] < 0)
    {
        break;
    }
## 代码

### [c++代码](./src/cpp/3Sum.cpp)
```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        for (int i=0; i<nums.size(); i++){
            int target=-nums[i];
            
            if (target<0)//加速,全是正数的数组不可能和为0
                break;
            int front=i+1, back=nums.size()-1;
            while (front<back){
                int sum=nums[front]+nums[back];
                if (sum>target)
                    back--;
                else if(sum<target)
                    front++;
                else{
                    vector<int> tri={nums[i], nums[front], nums[back]};
                    res.push_back(tri);
                    while(front<back&&nums[front]==tri[1]) front++;//防止中间数字有重复
                    while(front<back&&nums[back]==tri[2]) back--;//防止最后的数字有重复
                }
            }
            while(i<nums.size()-1&&nums[i]==nums[i+1]) i++;//防止第一个数字重复
        }
        return res;
    }
};
```

### [python代码](./src/python/3Sum.py)

```python
cimport collections


class Solution(object):
        def threeSum(self, nums):
                """
:type nums: List[int]
:rtype: List[List[int]]
"""
                nums, result, i = sorted(nums), [], 0
                while i < len(nums) - 2:
                        if i == 0 or nums[i] != nums[i - 1]:
                                j, k = i + 1, len(nums) - 1
                                while j < k:
                                        if nums[i] + nums[j] + nums[k] < 0:
                                                j += 1
                                        elif nums[i] + nums[j] + nums[k] > 0:
                                                k -= 1
                                        else:
                                                result.append([nums[i], nums[j], nums[k]])
                                                j, k = j + 1, k - 1
                                                while j < k and nums[j] == nums[j - 1]:
                                                        j += 1
                                                while j < k and nums[k] == nums[k + 1]:
                                                        k -= 1
                        i += 1
                return result

        def threeSum2(self, nums):
                """
:type nums: List[int]
:rtype: List[List[int]]
"""
                d = collections.Counter(nums)
                nums_2 = [x[0] for x in d.items() if x[1] > 1]
                nums_new = sorted([x[0] for x in d.items()])
                rtn = [[0, 0, 0]] if d[0] >= 3 else []
                for i, j in enumerate(nums_new):
                        if j <= 0:
                                numss2 = nums_new[i + 1:]
                                for x, y in enumerate(numss2):
                                        if 0 - j - y in [j, y] and 0 - j - y in nums_2:
                                                if sorted([j, y, 0 - j - y]) not in rtn:
                                                        rtn.append(sorted([j, y, 0 - j - y]))
                                        if 0 - j - y not in [j, y] and 0 - j - y in nums_new:
                                                if sorted([j, y, 0 - j - y]) not in rtn:
                                                        rtn.append(sorted([j, y, 0 - j - y]))
                return rtn

if __name__ == '__main__':
        result = Solution().threeSum([-1, 0, 1, 2, -1, -4])
        print result

```
