class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() == 0)
            return 0;

        int index1 = 0, index2 = rotateArray.size() - 1;
        int indexMid = index1;

        while (rotateArray[index1] >= rotateArray[index2])
        {
            if (index2 - index1 == 1)
            {
                indexMid = index2;
                break;
            }
            indexMid = (index1 + index2) / 2;

            if (rotateArray[index1] == rotateArray[index2] && rotateArray[index1] == rotateArray[indexMid])
                return minInOrder(rotateArray, index1, index2);

            if (rotateArray[indexMid] >= rotateArray[index1])
                index1 = indexMid;
            else if (rotateArray[indexMid] <= rotateArray[index2])
                index2 = indexMid;
        }

        return rotateArray[indexMid];
    }

    int minInOrder(const vector<int> rotateArray, int index1, int index2)
    {
        int minNum = rotateArray[index1];
        for (int i = index1; i <= index2; i++)
        {
            if (rotateArray[i] <= minNum)
                minNum = rotateArray[i];
        }
        return minNum;
    }
};