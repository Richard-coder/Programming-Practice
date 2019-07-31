class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty())
            return -1;
        unsigned int hashTable[256]={0};
        int i=0;
        for(;i<str.size();i++)
            hashTable[str[i]]++;
        for(i=0;i<str.size();i++){
            if(hashTable[str[i]]==1)
                break;
        }
        return i;
    }
};