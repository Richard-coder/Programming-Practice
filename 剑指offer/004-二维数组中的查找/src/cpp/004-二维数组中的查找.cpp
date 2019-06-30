class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()) return false;
        for(int i=0,j=array[i].size()-1;i<array.size()&&j>=0;){
            if(array[i][j]==target)
                return true;
            else if(array[i][j]>target)
                j--;
            else
                i++;
        }
        return false;
    }
};