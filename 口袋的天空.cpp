题目描述
给你云朵的个数NN，再给你MM个关系，表示哪些云朵可以连在一起。

现在小杉要把所有云朵连成KK个棉花糖，一个棉花糖最少要用掉一朵云，小杉想知道他怎么连，花费的代价最小。

输入格式
每组测试数据的

第一行有三个数N,M,K(1 \le N \le 1000,1 \le M \le 10000,1 \le K \le 10)N,M,K(1≤N≤1000,1≤M≤10000,1≤K≤10)

接下来MM个数每行三个数X,Y,LX,Y,L，表示XX云和YY云可以通过LL的代价连在一起。(1 \le X,Y \le N,0 \le L<10000)(1≤X,Y≤N,0≤L<10000)

30\%30%的数据N \le 100,M \le 1000N≤100,M≤1000

输出格式
对每组数据输出一行，仅有一个整数，表示最小的代价。

如果怎么连都连不出KK个棉花糖，请输出'No Answer'。



#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 1005
using namespace std;
int n,m,k,x,y,l,sum,ans;
int fa[N];
struct Edge
{
    int u,v,w;
    bool operator <(Edge a) const    //重置运算符的函数写在里面的话必须加const
    {
        return w<a.w;
    }
}edge[N*10];
/*bool operator <(Edge a,Edge b)    //重置运算符的函数写在外面的话不能加const
{
        return a.w<b.w;
}*/
int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    sort(edge+1,edge+m+1);    //按代价升序排列 
    for(int i=1;i<=m;i++)
    {
        int fx=find(edge[i].u),fy=find(edge[i].v);
        if(fx!=fy)        //如果这两个点不在同一棵树中 
        {
            fa[fx]=fy;
            sum++;        //连一条边，让它们合并成为一棵树 
            ans+=edge[i].w;        //加上合并的代价 
        }
        if(sum==n-k)        //已经连好了k棵树 
        {
            printf("%d",ans);
            return 0;
        }
    }
    puts("No Answer");    //不可能连好 
    return 0;
}
