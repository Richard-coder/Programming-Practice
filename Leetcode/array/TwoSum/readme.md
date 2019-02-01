# 1. Two Sum

tags： Array, Hash Table

---

## 题目原文

[原文网址](https://leetcode.com/problems/two-sum/description/)

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

这道题的解题思路想到了用hash map, 就比较好办了. hash map中, 其键值为输入数组的元素, hash map的元素为输入数组的索引. 从头遍历输入数组的数据nums[i], 如果hash map 中没有target-nums[i], 则将i存入哈希表, nums[i]为键值. 若果有, 则先返回hash[target-nums[i]], 再返回i, 因为输入数组按照从小到大的顺序排列, 较小的元素先被遍历, 会被存入哈希表.

## C++ 知识点

### C++ STL之哈希表 | unordered_map

C++ STL中，哈希表对应的容器是`unordered_map`（since C++ 11）。 根据C++ 11标准的推荐，用`unordered_map`代替`hash_map`。

**为什么要使用unordered_map代替hash_map？**

- 因为标准化的推进，unordered_map原来属于boost分支和std::tr1中，而hash_map属于非标准容器。
- 另外，使用之后，感觉速度和hash_map差不多，但是支持string做key，也可以使用复杂的对象作为key。
- gxx需要添加编译选项：--std=gnu++0x或者--std=c++0x

**与map的区别**
STL中，map对应的数据结构是红黑树。红黑树是一种近似于平衡的二叉查找树，里面的数据是有序的。在红黑树上做查找操作的时间复杂度为 O(logN)。而unordered_map对应 哈希表，哈希表的特点就是查找效率高，时间复杂度为常数级别 O(1)， 而额外空间复杂度则要高出许多。所以对于需要高效率查询的情况，使用unordered_map容器。而如果对内存大小比较敏感或者数据存储要求有序的话，则可以用map容器。

**成员函数**

| 操作          | 说明                                                         |
| ------------- | ------------------------------------------------------------ |
| operator=     | 赋值操作                                                     |
| empty()       | 判断容器是否为空                                             |
| size()        | 返回容器存储元素数量                                         |
| max_size()    | 返回容器最大存储容量                                         |
| begin()       | 返回一个前向迭代器，指向第一个元素的位置                     |
| end()         | 返回一个迭代器，指向最后一个元素的下一个位置                 |
| cbegin()      | 返回一个逆向迭代器，指向逆序第一个元素的位置                 |
| cend()        | 返回一个逆序迭代器，指向逆序最后一个元素的下一个位置         |
| operator[]    | 根据键值直接存取元素，若键值不存在，则插入之                 |
| at()          | 同上，不过不会插入新的键值，而是抛出out_of_range异常         |
| find()        | 根据键值进行查找，找到返回所在迭代器，否则返回end迭代器      |
| count()       | 统计key值在unordered_map中出现的次数。实际上，c++ unordered_map不允许有重复的key。因此，如果key存在，则count返回1，如果不存在，则count返回0 |
| equal_range() | 返回键值相等的区间，找到返回迭代器对，值均为参数键值对应的迭代器；找不到返回两个end |
| emplace()     | 构造键值对，并插入容器内                                     |
| insert()      | 插入键值对，支持拷贝插入，区间插入                           |
| erase()       | 移除元素，可传迭代器参数，键值参数，迭代器区间参数           |
| clear()       | 清除容器内所有元素                                           |
| swap()        | 交换两个容器内的元素                                         |

### python 知识点

### 字典

字典是另一种可变容器模型，且可存储任意类型对象。

字典的每个键值(key=>value)对用冒号(**:**)分割，每个对之间用逗号(**,**)分割，整个字典包括在花括号(**{})**中 ,格式如下所示：

```
d = {key1 : value1, key2 : value2 }
```

键必须是唯一的，但值则不必。

值可以取任何数据类型，但键必须是不可变的，如字符串，数字或元组。

一个简单的字典实例：

```
dict = {'Alice': '2341', 'Beth': '9102', 'Cecil': '3258'}
```

也可如此创建字典：

```
dict1 = { 'abc': 456 };
dict2 = { 'abc': 123, 98.6: 37 };
```

**迭代**

1. 只对键的遍历

```python
d = {'name1' : 'pythontab', 'name2' : '.', 'name3' : 'com'}
for key in d:
    print (key, ' value : ', d[key])
```

2. 对键和值都进行遍历

``` python
for key, value in d.items():
    print (key, ' value : ', value)
```

**字典键的特性**

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
