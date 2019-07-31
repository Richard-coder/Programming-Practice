# 038_03-全组合-含重复元素

tags： 全组合

---

## 题目原文

[leetcode链接]()

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

**说明：**解集不能包含重复的子集。

**示例:**

```
输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```



## 解题思路

### 迭代法

[参考](https://leetcode-cn.com/problems/subsets-ii/comments/)

这道题相比上一道题多了去重的步骤，所以在看懂上一道题的情况下，这道题就是如何理解去重了。上一道题的解题介绍（[78. Subsets](https://github.com/Kunwuwu/notes/blob/master/leetcode/78. Subsets.md)）,下面讲解思路。

\> 以下思路基于元素列已经被排序。

1. 为什么会出现重复子列？

   - 该解法生成子列是在之前已经生成的所有子列上依次加上新的元素，生成新的子列。
   - 如果元素列(nums)中存在重复元素，则当前元素生成新子列的过程会与前面重复元素生成新子列的过程部分重复，则生成的子列也是部分重复的。

2. 重复子列出现在哪些部分？ 假设元素列(nums)为：[1, 2, 2]，下面进行模拟

   - 遍历完第一个元素--->[[], [1]]
   - 遍历完第二个元素--->[[], [1], [2], [1, 2]]
   - 遍历完第三个元素--->[[], [1], [2], [1, 2], **[2]**, **[1, 2]**, [2, 2], [1, 2, 2]]。
   - ![image.png](img/readme.assets/87ba90075a0a54e867ee05a65612d6f00766624c9f50f92beb9004e8b5a3ff27-image.png)

   加粗部分就是第三个元素遍历以后，产生的重复部分。[ **[2]**, **[1, 2]**]是因为第三个元素`2`，在与[[], [1]]生成新序列时生成的，可以看到这个过程与第二个元素`2`生成新序列的过程时一样的。即重复序列就是第三个元素在与[[], [1]]生成新序列时生成的，同时注意到[[], [1]]之后的序列就是第二元素遍历时生成的新序列，而第三个序列与这些新序列不会生成重复序列，同时注意每次生成的新序列的长度是可以被记录的。

3. 如何避免生成重复序列 在了解重复序列出现的原因和位置以后，就可以去重操作了。

   - 先进行排序，保证重复元素挨在一起
   - 记录每次遍历生成的新序列的长度，这里用`left`表示每次遍历的开始位置，`right`结束位置，`len`表示上次新生成记录的长度
   - 根据与前面元素是否重复，来决定`left`的取值，也就是开始遍历的位置

   

   上述三个步骤就能有效避免当前元素与之前相同元素遍历过程发生重叠。

   

   ```c++
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
   ```

   

   

   

   ### 位运算

   [参考](https://leetcode-cn.com/problems/subsets-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-19/)

   回顾一下，这个题的思想就是每一个数字，考虑它的二进制表示。

   例如，nums = [ 1, 2 , 3 ]。用 1 代表在，0 代表不在。

   ```
   1 2 3
   0 0 0 -> [     ]
   0 0 1 -> [    3]
   0 1 0 -> [  2  ]   
   0 1 1 -> [  2 3]  
   1 0 0 -> [1    ]
   1 0 1 -> [1   3] 
   1 1 0 -> [1 2  ]
   1 1 1 -> [1 2 3]
   ```

   但是如果有了重复数字，很明显就行不通了。例如对于 nums = [ 1 2 2 2 3 ]。

   ```
   1 2 2 2 3
   0 1 1 0 0  -> [  2 2  ]
   0 1 0 1 0  -> [  2 2  ]
   0 0 1 1 0  -> [  2 2  ]
   ```

   上边三个数产生的数组重复的了。上面三个产生[2 2]的情况中我们只取其中 1 个，取哪个呢？取从重复数字的开头连续的情况。什么意思呢？就是下边的情况是我们所保留的。

   ```
   2 2 2 2 2 
   1 0 0 0 0 -> [  2         ]
   1 1 0 0 0 -> [  2 2       ]
   1 1 1 0 0 -> [  2 2 2     ]
   1 1 1 1 0 -> [  2 2 2 2   ]
   1 1 1 1 1 -> [  2 2 2 2 2 ]  
   ```

   而对于 [ 2 2 ] 来说，除了 1 1 0 0 0 可以产生，下边的几种情况，都是产生的 [ 2 2 ]

   ```
   2 2 2 2 2 
   1 1 0 0 0 -> [  2 2       ]
   1 0 1 0 0 -> [  2 2       ]
   0 1 1 0 0 -> [  2 2       ]
   0 1 0 1 0 -> [  2 2       ]
   0 0 0 1 1 -> [  2 2       ]
   ......
   ```

   

   怎么把 1 1 0 0 0 和上边的那么多种情况区分开来呢？我们来看一下出现了当前数字与前面数字重复的情况. 对于`1 1 0 0 0`重复数字的二进制表示前一位是1,保留, 对于剩下情况, 重复数字的二进制表示前一位是0, 舍弃.

   ```
   对于 1 1 0 0 0 ，是 1。
   
   对于 1 0 1 0 0 , 是 0。
   
   对于 0 1 1 0 0 ，是 0。
   
   对于 0 1 0 1 0 ，是 0。
   
   对于 0 0 0 1 1 ，是 0。
   
   ......
   ```

   

   可以看到只有第一种情况重复数字前一位对应的是 1 ，其他情况都是 0。其实除去从开头是连续的 1 的话，就是两种情况。

   第一种就是，占据了开头，类似于这种 10...1....

   第二种就是，没有占据开头，类似于这种 0...1...

   这两种情况，除了第一位，其他位的 1 的前边一定是 0。所以的话，有重复数字时, 去除重复组合的条件是, 重复数字的前一位是0;

   所以可以改代码了。

   ```
   class Solution {
   public:
       vector<vector<int>> subsetsWithDup(vector<int>& nums) {
           sort(nums.begin(),nums.end());
           int n = nums.size();
           int all = 1 << n;
           vector<vector<int>> res;//存放最后的结果
    
           for(int i = 0; i < all; i++){ 
               bool illegal=false;
               vector<int> vec;
               for(int j = 0; j < nums.size(); j++){
                   if((i & (1 << j)) != 0){
                       if(j>0&&nums[j]==nums[j-1]&&(i&(1<<(j-1)))==0){
                           illegal=true;
                           break;
                       }
                       else
                       {
                           vec.push_back(nums[j]);
                       }
                   }
                }
               if(!illegal){
                   res.push_back(vec);
               }
           }
           return res;
       }
   };
   ```

   

   或者

   ```c++
   class Solution {
   public:
       vector<vector<int>> subsetsWithDup(vector<int>& nums) {
           sort(nums.begin(),nums.end());
           int n = nums.size();
           int all = 1 << n;
           vector<vector<int>> res;//存放最后的结果
    
           for(int i = 0; i < all; i++){ 
               bool illegal=false;
               vector<int> vec;
               for(int j = nums.size()-1; j>=0; j--){
                   int bit_j=nums.size()-1-j;
                   if((i & (1 << bit_j)) != 0){
                       if(bit_j>0&&nums[j]==nums[j+1]&&(i & (1 << (bit_j-1))) == 0){
                           illegal=true;
                           break;
                       }
                       else
                       {
                           vec.push_back(nums[j]);
                       }
                   }
                }
               if(!illegal){
                   res.push_back(vec);
               }
           }
           return res;
       }
   };
   ```

   

## 代码

### [c++代码](./src/cpp/038_03-全组合-含重复元素.cpp)

```c++
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
```

### [python代码](./src/python/038_03-全组合-含重复元素.py)

```python

```
