#include<cstdio>
#include<algorithm>
using std::sort;
int a[510][510];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
        }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        sort(a[i]+1,a[i]+1+n);
        ans=ans>a[i][n-1]?ans:a[i][n-1];//选出排名第二中最大的那个
    }
    printf("1\n%d\n",ans);//一定有解
    return 0;
}
