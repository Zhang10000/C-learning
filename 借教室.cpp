输入格式
第一行包含两个正整数n,mn,m，表示天数和订单的数量。

第二行包含nn个正整数，其中第ii个数为r_ir 
i
​	
 ，表示第ii天可用于租借的教室数量。

接下来有mm行，每行包含三个正整数d_j,s_j,t_jd 
j
​	
 ,s 
j
​	
 ,t 
j
​	
 ，表示租借的数量，租借开始、结束分别在第几天。

每行相邻的两个数之间均用一个空格隔开。天数与订单均用从11开始的整数编号。

输出格式
如果所有订单均可满足，则输出只有一行，包含一个整数00。否则（订单无法完全满足）

输出两行，第一行输出一个负整数-1−1，第二行输出需要修改订单的申请人编号。

#include<iostream>
#include<cstring>
#include<cstdio> 
using namespace std;
int n,m;
int diff[1000011],need[1000011],rest[1000011],r[1000011],l[1000011],d[1000011];
bool isok(int x)
{
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=x;i++)
    {
        diff[l[i]]+=d[i];
        diff[r[i]+1]-=d[i]; 
    }
    for(int i=1;i<=n;i++)
    {
        need[i]=need[i-1]+diff[i];
        if(need[i]>rest[i])return 0;
    }
    return 1;
} 
int main()
{

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&rest[i]);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&d[i],&l[i],&r[i]);
    int begin=1,end=m; 
    if(isok(m)){cout<<"0";return 0;}
    while(begin<end)
    {
        int mid=(begin+end)/2;
        if(isok(mid))begin=mid+1;
        else end=mid;
    }
    cout<<"-1"<<endl<<begin;
}
