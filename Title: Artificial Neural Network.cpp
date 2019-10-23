// 输入格式
// 输入文件第一行是两个整数n(1 \le n \le 100)n(1≤n≤100)和pp。接下来nn行，每行22个整数，第i+1i+1行是神经元ii最初状态和其阈值（U_iU 
// i），非输入层的神经元开始时状态必然为00。再下面PP行，每行由22个整数i,ji,j及11个整数W_{ij}W ij，表示连接神经元i,ji,j的边权值为W_{ij}W ij
// ​	 。

// 输出格式
// 输出文件包含若干行，每行有22个整数，分别对应一个神经元的编号，及其最后的状态，22个整数间以空格分隔。仅输出最后状态大于00的输出层神经元状态，并且按照编号由小到大顺序输出。

// 若输出层的神经元最后状态均为 00，则输出 “NULL”。

#include<queue>
#include<cstdio>
#include<algorithm>
#define N 102
#define M N*N
using namespace std;
queue<int> q;
struct edge{
    int to,val,from,next;
} e[M];
struct answ{
    int num,val;
} ans[N];
int h,i,m,n,t,u,v,w,x,c[N],hd[N];
bool out[N],vis[N];
int cnt=0,tot=0;
 bool cmp(answ aa,answ bb)
 {return aa.num<bb.num;}
 void build(int u,int v,int w)
 {
    cnt++;
    e[cnt].to=v;
    e[cnt].val=w;
    e[cnt].from=u;
    e[cnt].next=hd[u];
    hd[u]=cnt;
 }
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        hd[i]=0;out[i]=false;
        scanf("%d%d",&c[i],&x);
        if(c[i])
         {q.push(i);vis[i]=true;}
        else
         {c[i]-=x;vis[i]=false;}
    }
    for(i=1;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        build(u,v,w);
        out[u]=true;
    }
    while(!q.empty())
    {
        h=q.front();q.pop();
        for(i=hd[h];i;i=e[i].next)
        {
            if(c[e[i].from]<=0) continue;
            t=e[i].to;
            c[t]+=(e[i].val*c[h]);
            if(!vis[t])
            {
                q.push(t);
                vis[t]=true;
            }
        }
    }
    for(i=1;i<=n;++i)
     if(c[i]&&!out[i])
     {
        tot++;
        ans[tot].num=i;
        ans[tot].val=c[i];
     }
    if(tot==0) {printf("NULL");return 0;}
    sort(ans+1,ans+tot+1,cmp);
    for(i=1;i<=tot;++i)
    printf("%d %d\n",ans[i].num,ans[i].val);
    return 0;
}
