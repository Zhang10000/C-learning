class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size()==0)return 0;
        int cursum=array[0];
        int maxsum=array[0];
        for(int i=1;i<array.size();i++){
            cursum += array[i];
            if(cursum < array[i])
                cursum = array[i];
            if(cursum > maxsum)
                maxsum = cursum;
        }
    return maxsum;
    }
};
