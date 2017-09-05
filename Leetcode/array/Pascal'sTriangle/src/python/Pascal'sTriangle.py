class Solution(object):
    def generate(self, numRows):
        pas=[]
        for i in xrange(numRows):
            pas.append([])
            for j in xrange(0,i+1):
                if j in (0,i):
                    pas[i].append(1)
                else:
                    pas[i].append(pas[i-1][j-1]+pas[i-1][j])
        return pas
if __name__ =="__main__":
    print Solution().generate(5)