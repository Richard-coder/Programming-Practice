class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if(array.empty())
            throw new std::logic_error("invalid input");
        int sum=0;
        int maxSum=INT_MIN;
        
        for(int i=0;i<array.size();i++){
            if(sum<=0)
                sum=array[i];
            else
                sum+=array[i];
            if(sum>maxSum)
                maxSum=sum;
        }
        return maxSum;
    }
};