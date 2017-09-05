class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool find=false;
        for(int row=0,col=array[row].size()-1;row < array.size()&&col>=0;){
                if (target==array[row][col])
                    return find=true;
                else if(array[row][col]>target)
                    col--;
                else
                    row++;
        }
        return find;
    }
};