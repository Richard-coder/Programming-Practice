118. Pascal's Triangle

tags： Array

---

## 题目原文
[题目链接](https://leetcode-cn.com/problems/pascals-triangle/)

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
![img](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

**示例:**

```
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

## 题目大意

输入一个数字，输出相应阶数的帕斯卡三角。



## 解题思路

要得到一个帕斯卡三角， 我们只需要找到规律即可。

第k层有k个元素
每层第一个以及最后一个元素值为1
对于第k（ k > 2） 层, 第n（ n > 1 && n < k） 个元素A[k][n]， A[k][n] = A[k-1][n-1] + A[k-1][n]

## c++ 知识点

### vector resize和reserve区别

```
void reserve (size_type n);
```

reserve函数用来给vector**预分配**存储区大小，即capacity的值 ，但是没有给这段内存进行初始化。reserve 的参数n是推荐预分配内存的大小，实际分配的可能等于或大于这个值，即n大于capacity的值，就会reallocate内存 capacity的值会大于或者等于n 。这样，当vector调用push_back函数使得size 超过原来的默认分配的capacity值时 避免了内存重分配开销。

需要注意的是：reserve 函数分配出来的内存空间，只是表示vector可以利用这部分内存，但vector不能有效地访问这些内存空间，访问的时候就会出现越界现象，导致程序崩溃。

```
void resize (size_type n);
void resize (size_type n, value_type val);
```

resize函数**重新分配**大小，改变容器的大小，并且创建对象

当n小于当前size()值时候，vector首先会减少size()值 保存前n个元素，然后将超出n的元素删除(remove and destroy)

当n大于当前size()值时候，vector会插入相应数量的元素 使得size()值达到n，并对这些元素进行初始化，如果调用上面的第二个resize函数，指定val，vector会用val来初始化这些新插入的元素

当n大于capacity()值的时候，会自动分配重新分配内存存储空间。

容器调用resize()函数后，所有的空间都已经初始化了，所以可以直接访问。

而reserve()函数预分配出的空间没有被初始化，所以不可访问。



参考: [C++：vector中的resize()函数 VS reserve()函数](https://www.cnblogs.com/biyeymyhjob/archive/2013/05/11/3072893.html), [vector resize和reverse区别](https://blog.csdn.net/yockie/article/details/7992057)

## python 知识点

### Python List append()方法

**描述**
append() 方法用于在列表末尾添加新的对象。

**语法**
append()方法语法：

```python
list.append(obj)
```

**参数**
obj -- 添加到列表末尾的对象。
**返回值**
该方法无返回值，但是会修改原来的列表。

### python中append和extend函数区别

append函数直接将object整体当作一个元素追加到列表中，而extend函数则是将可迭代对象中的元素逐个追加到列表中。

```python
In [1]: lt1=['A','B','C']
   ...: lt2=['D','E','F']
   ...: lt1.append(lt2)#将lt2整体当作一个元素追加到到lt1中
   ...: print(lt1)
   ...: lt3=['A','B','C']
   ...: lt2=['D','E','F']
   ...: lt3.extend(lt2)#将lt2中每个元素逐个追加到t3中
   ...: print(lt3)
   ...:
['A', 'B', 'C', ['D', 'E', 'F']]

```

### 技巧

```python
if j in (0,i):
	pas[i].append(1)
```



## 代码

### [c++代码](./src/cpp/Pascal'sTriangle.cpp)
```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > pas;
        pas.resize(numRows);
        for(int i=0;i<numRows;i++){
            pas[i].resize(i+1);
            pas[i][0]=1;
            pas[i][pas[i].size()-1]=1;
            for(int j=1;j<pas[i].size()-1;j++){
                pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
            }
        }
        return pas;
    }
};
```

### [python代码](./src/python/Pascal'sTriangle.py)
```python
class Solution(object):
    def generate(self, numRows):
        pas=[]
        for i in xrange(numRows):
            pas.append([])
            for j in xrange(0,i+1):
                if j in (0,i):
                    pas[i].append(1)
                else:
                    pas[i].append(pas[i-1][j-1]+pas[i-1][j])
        return pas
if __name__ =="__main__":
    print Solution().generate(5)
```
