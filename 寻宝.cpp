/*第一行22个整数NN和MM，之间用一个空格隔开。NN表示除了顶层外藏宝楼共NN层楼，MM表示除顶层外每层楼有MM个房间。
接下来N \times MN×M行，每行两个整数，之间用一个空格隔开，每行描述一个房间内的情况，其中第(i-1) \times M+
j(i−1)×M+j行表示第ii层j-1j−1号房间的情况（i=1,2,…, Ni=1,2,…,N；j=1,2,…,Mj=1,2,…,M）。第一个整数表示该
房间是否有楼梯通往上一层（00表示没有，11表示有），第二个整数表示指示牌上的数字。注意，从jj号房间的楼梯爬到
上一层到达的房间一定也是jj号房间。
最后一行，一个整数，表示小明从藏宝楼底层的几号房间进入开始寻宝（注：房间编号从00开始）。*/

#include <cstdio>
#include <iostream>
using namespace std;

long long n,m,a[10001][101],b[10001][101],c[10001],sum,k,ans,q;

int main()
{
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;i++)
     for (int j=0;j<=m-1;j++)
     {
        scanf("%lld%lld",&a[i][j],&b[i][j]);
        c[i]+=a[i][j];  //c[i]记录第i层楼梯总数
     } 
    scanf("%lld",&k);
    for (int j=1;j<=n;j++)
    {
        sum+=b[j][k];  //记录答案
        ans=0;
        q=k;
        b[j][q]=(b[j][q]-1)%c[j]+1;  //减去多余部分
        while (ans<b[j][q])
        {
            ans+=a[j][k];  //如上
            if (ans==b[j][q]) break;
            k++;
            if (k==m) k=0;
        }
    }
    printf("%lld\n",sum%20123);
}
