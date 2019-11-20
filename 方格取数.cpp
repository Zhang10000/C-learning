设有N \times NN×N的方格图(N \le 9)(N≤9)，我们将其中的某些方格中填入正整数，而其他的方格中则放入数字00。如下图所示（见样例）:

A
 0  0  0  0  0  0  0  0
 0  0 13  0  0  6  0  0
 0  0  0  0  7  0  0  0
 0  0  0 14  0  0  0  0
 0 21  0  0  0  4  0  0
 0  0 15  0  0  0  0  0
 0 14  0  0  0  0  0  0
 0  0  0  0  0  0  0  0
                         B
某人从图的左上角的AA点出发，可以向下行走，也可以向右走，直到到达右下角的BB点。在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字00）。
此人从AA点到BB点共走两次，试找出22条这样的路径，使得取得的数之和为最大。





#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
    int x,y,data;//记录每个点的位置和数值
}p[100];
int n,m,map[11][11],f[11][11];
int main()
{
    int i,ii,j,jj,l;
    scanf("%d",&n);
    while(1)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(!a&&!b&&!c)
            break;
        p[++m].x=a;
        p[m].y=b;
        p[m].data=c;
    }
    for(i=1;i<=m;i++)
        map[p[i].x][p[i].y]=p[i].data;
    for(l=2;l<=n*2;l++)//每个点最少横着竖着都走一格，最多都走n格就到终点
        for(i=l-1;i>=1;i--)//和前面说的一样，倒着做
            for(ii=l-1;ii>=1;ii--)
            {
                j=l-i;jj=l-ii;//i+j=ii+jj=l
                f[i][ii]=max(max(f[i][ii],f[i-1][ii-1]),max(f[i-1][ii],f[i][ii-1]))+map[i][j];
//重点说明一下吧，这里省略了很多。如果i不减1，意思就是j-1，因为上一个阶段就是l-1嘛。如果ii-1，意思就是说jj不减1。
                f[i][ii]+=map[ii][jj]*(i!=ii);
//如果i==ii，其实就是(i==ii&&j==jj)，因为和都是l嘛。如果走过一遍，第二遍走得到的值就是0（题目上说的）。
            }
    printf("%d\n",f[n][n]);
//输出意思是在路径长度为2*n的阶段，两遍都走到(n,n)的最优值。因为在这里(j=2*n-i=n,jj=2*n-ii=n),所以走到的就是(n,n)的位置
    return 0;
}
