class Solution {
public:
    void Insert(int num)
    {
        if(((max.size()+min.size())&1)==0){// 堆的总长度为偶数时, 添加新元素到最小堆
            if(max.size()>0&&num<max[0]){
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<int>());
                num=max[0];
                pop_heap(max.begin(),max.end(),less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<int>());
        }else{// 堆的总长度为奇数时, 添加新元素到最大堆
            if(min.size()>0&&num>min[0]){
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<int>());
                num=min[0];
                pop_heap(min.begin(),min.end(),greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<int>());
        }
    }

    double GetMedian()
    { 
        int size=max.size()+min.size();
        double res=0;
        if(size==0)
            throw new std::logic_error("invalid input");
        if((size&1)==0)
            res=(max[0]+min[0])/2.;//这里要注意整数和整数相除结果是整数, 所以应该除以2.
        else
            res=min[0];//因为先从最小堆开始放, 如果数据总长度是奇数, 那么最后一个元素一定在最小堆
        return res;
    }

    vector<int> max;//最大堆
    vector<int> min;//最小堆
};