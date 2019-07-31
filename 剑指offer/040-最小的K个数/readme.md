# 040-最小的K个数

tags： 数组

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

## 解题思路

[参考](https://www.cnblogs.com/edisonchou/p/4799678.html)

### 需要修改数据源的O(n)解法

基于快速排序中的**Partition**函数来解决这个问题。如果基于数组的第k个数字来调整，使得比第k个数字小的所有数字都位于数组的左边，比第k个数字大的所有数字都位于数组的右边。这样调整之后，位于数组中左边的k个数字就是最小的k个数字（这k个数字不一定是排序的）。

　　But，采用这种思路是**有限制的**。我们**需要修改输入的数组**，因为函数Partition会调整数组中数字的顺序。

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k<1||input.size()<k)
            return res;
        int start=0,end=input.size()-1;
        int index=Partion(input,start,end);
        while(index!=k-1){
            if(index>k-1){
                end=index-1;
                index=Partion(input,start,end);
            }
            else{
                start=index+1;
                index=Partion(input,start,end);
            }
        }
        for(int i=0;i<k;i++){
            res.push_back(input[i]);
        }
        return res;
    }
    int Partion(vector<int>& input, int start, int end){
        if(input.empty()||start<0||end<0||start>end)
            throw new std::logic_error("invalid input");
        int index=RandomInrange(start,end);
        int small=start-1;
        swap(input[index],input[end]);
        for(int i=start;i<end;i++){
            if(input[i]<input[end]){
                small++;
                if(small!=i){
                    swap(input[small],input[i]);
                }
            }
        }
        small++;
        swap(input[small],input[end]);
        return small;
    }
    
    int RandomInrange(int start, int end){
        srand(time(NULL));
        return start+rand()%(end-start+1);
    }
};
```

### 适合处理海量数据的O(nlogk)解法



```c++
class Solution {
public:
    typedef multiset<int, greater<int>> IntSet;
    typedef multiset<int, greater<int>>::iterator setIterator;
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k<1||input.size()<k)
            return res;
        IntSet leastNumbers;
        for(int i=0;i<input.size();i++){
            if(leastNumbers.size()<k){
                leastNumbers.insert(input[i]);
            }else{
                setIterator begin=leastNumbers.begin();
                if(input[i]<*begin){
                    leastNumbers.erase(begin);
                    leastNumbers.insert(input[i]);
                }
            }
        }
        setIterator temp=leastNumbers.begin();
        for(int i=0;i<k;i++)
            res.push_back(*(temp++));
        return res;
    }
};
```

可以先创建一个大小为k的数据容器来存储最小的k个数字，接下来我们每次从输入的n个整数中读入一个数。

　　如果容器中已有的数字少于k个，则直接把这次读入的整数**放入容器之中**；

　　如果容器中已有k个数字了，也就是容器已满，此时我们**不能再插入新的数字而只能替换已有的数字**。

　　找出这已有的k个数中的最大值，然后拿这次待插入的整数和最大值进行比较。如果待插入的值比当前已有的最大值小，则用这个数替换当前已有的最大值；如果待插入的值比当前已有的最大值还要大，那么这个数不可能是最小的k个整数之一，于是我们可以抛弃这个整数。

　　因此当容器满了之后，我们要做3件事情：一是在k个整数中找到最大数；二是有可能在这个容器中删除最大数；三是有可能要插入一个新的数字。如果用一个二叉树来实现这个数据容器，那么我们能在**O(logk)**时间内实现这三步操作。因此对于n个输入数字而言，总的时间效率就是**O(nlogk)**。

采用了红黑树结构作为容器，当然也可以采用堆来实现

## STL知识

[std::set与std::multiset使用总结](https://blog.csdn.net/cv_jason/article/details/83048406)

[C++：greater<int>和less<int>](https://www.cnblogs.com/lzhu/p/7010894.html)

## 代码

### [c++代码](./src/cpp/040-最小的K个数.cpp)

```c++
class Solution {
public:
    typedef multiset<int, greater<int>> IntSet;
    typedef multiset<int, greater<int>>::iterator setIterator;
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k<1||input.size()<k)
            return res;
        IntSet leastNumbers;
        for(int i=0;i<input.size();i++){
            if(leastNumbers.size()<k){
                leastNumbers.insert(input[i]);
            }else{
                setIterator begin=leastNumbers.begin();
                if(input[i]<*begin){
                    leastNumbers.erase(begin);
                    leastNumbers.insert(input[i]);
                }
            }
        }
        setIterator temp=leastNumbers.begin();
        for(int i=0;i<k;i++)
            res.push_back(*(temp++));
        return res;
    }
};
```

### [python代码](./src/python/040-最小的K个数.py)

```python

```
