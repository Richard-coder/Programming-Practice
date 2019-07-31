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