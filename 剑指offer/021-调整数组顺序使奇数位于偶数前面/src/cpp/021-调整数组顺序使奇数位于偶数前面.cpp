    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }
        bool isSwap = false;
        for (int i = 0; i < array.size( ); i++)
        {
            isSwap = false;
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1]%2 == 0) //前偶后奇交换
                {
                    swap(array[j], array[j-1]);
                    isSwap = true;
                }
            }
            if(isSwap == false)
            {
                break;
            }
        }


    }