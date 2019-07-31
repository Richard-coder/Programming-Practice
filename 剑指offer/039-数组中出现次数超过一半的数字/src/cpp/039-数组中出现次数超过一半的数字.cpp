class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int times=1;
        int res=numbers[0];
        for(int i=1;i<numbers.size();i++){
            if(times==0){
                times=1;
                res=numbers[i];
            }
            else if(numbers[i]==res){
                times++;
            }
            else
                times--;
        }
        times=0;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==res)
                times++;
        }
        if (times>numbers.size()/2)
            return res;
        else
            return 0;
    }
};