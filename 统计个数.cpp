class Solution {
public:
int BinarySearch(vector<int> data, int low, int high, int k)
{
    while (low<=high)
    {
        int m = (high + low) / 2;
        if (data[m] == k)return m;
        else if (data[m] < k) low = m+ 1;
        else high = m - 1;
    }
    return -1;
}
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0)return 0;
         int len=data.size();
        int KeyIndex=0;
         
        KeyIndex=BinarySearch(data,0,len-1,k);
       if(KeyIndex==-1) return 0;
        int sumber=1;
        int m=KeyIndex-1;
        int n=KeyIndex+1;
       
       while(m>=0&&data[m]==k)
        {
                m--;sumber++;
            }
        while(n<len&&data[n]==k)
        {
               n++; sumber++;
            }
        return sumber;
    }
};
