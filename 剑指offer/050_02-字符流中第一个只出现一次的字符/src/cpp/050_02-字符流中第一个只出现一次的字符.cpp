class Solution{
public:
    //Insert one char from stringstream
    Solution():index(0){
        for(int i=0;i<256;i++)
            occurrence[i]=-1;
    }

    void insert(char ch)
    {
        if(occurrence[ch] == -1)
            occurrence[ch] = index;
        else if(occurrence[ch] >= 0)
            occurrence[ch] = -2;

        index++;
    }

    char firstAppearingOnce()
    {
        char ch;
        int minIndex = INT_MAX;
        for(int i = 0; i < 256; ++i)
        {
            if(occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char) i;
                minIndex = occurrence[i];
            }
        }
        if(minIndex == INT_MAX)
        return '#';
        else
        return ch;
    }
private:
    int index;
    // occurrence[i]: A character with ASCII value i;
    // occurrence[i] = -1: The character has not found;
    // occurrence[i] = -2: The character has been found for mutlple times
    // occurrence[i] >= 0: The character has been found only once
    int occurrence[256];
};