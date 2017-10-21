/**
 * 快速排序的简单代码示例
 */
int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length)
        throw new std::exception("Invalid Parameters");

    int index = RandomInRange(start, end);//随机选取主元index
    //这里把index和end对应元素交换是因为，交换后遍历的程序写起来比较简洁明了，遍历结束后将原index对应元素交换到相应位置即可
   //这里index和start对应元素交换也一样，原理相同
    Swap(&data[index],&data[end]);

    int small = start -1;//small是一个标记变量
    for (index=start;index<end;++index){
        //进入if语句前，small对应元素为序列已遍历元素中小于data[end]的索引最大元素
        if(data[index]<data[end]){
            ++small;
            //small+1后，small对应已遍历元素中大于等于data[end]的索引最小元素
            if(small!=index)
                Swap(&data[index],&data[small]);
        }
    }
    //small+1前，索引<=small的元素，均小于data[end]，索引>small的元素均>=data[end]
    ++small;
    //small+1后，small指向序列中大于等于small的索引最小元素
    Swap(&data[small],&data[end]);

    return small;
}
//下面是递归实现快速排序的参考代码
//对于长度为n的数组排序，只需要把start设为0、把end设为n-1，调用函数QuickSot即可

void QuickSort(int data[],int length, int start,int end){
    if (start==end)//递归终止条件
        return;
    int index=Partition(data,length,start,end);
    if(index>start)
        QuickSort(data,length,start,index-1);
    if(index<end)
        QuickSort(data,length,index+1,end);
}