class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0)
            return 0;
        vector<int> ugly(index);
        ugly[0]=1;
        int idx2=0,idx3=0,idx5=0,idx=1,val;
        
        while(idx<index){
            val=min(ugly[idx2]*2,min(ugly[idx3]*3,ugly[idx5]*5));
            if(val==ugly[idx2]*2) //将产生这个丑数的index*向后挪一位；
                idx2++;
            if(val==ugly[idx3]*3)//这里不能用elseif，因为可能有两个最小值，这时都要挪动；
                idx3++;
            if(val==ugly[idx5]*5)
                idx5++;
            ugly[idx++]=val;
        }
        
        return ugly[index-1];
    }
};