class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        if(s.empty())
            return 0;
        
        int curLength=0;
        int maxLength=0;
        
        vector<int> pos(26,-1);
        
        for(int i=0;i<s.size();i++){
            int pre_pos=pos[s[i]-'a'];
            if(pre_pos<0||i-pre_pos>curLength)
                curLength++;
            else{
                if(curLength>maxLength)
                    maxLength=curLength;
                
                curLength=i-pre_pos;
            }
            pos[s[i]-'a']=i;
        }
        if(curLength>maxLength)
            maxLength=curLength;
        return maxLength;
        
    }
};