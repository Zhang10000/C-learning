class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n+2][n+2];
        int[] nums2 = new int[n+2];
        nums2[0]=1;
        nums2[n+1]=1;
        for(int i=1;i<n+1;i++){
            nums2[i] = nums[i-1];
        }
        //dp[i][j] = max(dp[i][k-1]+dp[k+1][j]+nums2[i-1]*nums2[j+1]*nums[k])
        for(int i=1;i<n+1;i++){
            dp[i][i] = nums2[i-1]*nums2[i]*nums2[i+1];
        }
        for(int j=1;j<n;j++){
            for(int i=1;i<n+1-j;i++){
                int max;
                for(int k=i;k<=i+j;k++){
                    int left = (k-1>=i)?dp[i][k-1]:0;
                    int right = (k+1<=i+j)?dp[k+1][i+j]:0;
                    dp[i][i+j] = Math.max(left+right+nums2[i-1]*nums2[j+i+1]*nums2[k],dp[i][i+j]);
                }
                
            }
            
        }
        return dp[1][n];
    }
}
