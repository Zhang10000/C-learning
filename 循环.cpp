输入格式
一行，包含22个整数n(1 \le n < 10^{100})n(1≤n<10 
100
 )和k(1 \le k \le 100)k(1≤k≤100)，nn和kk之间用一个空格隔开，表示要求nn的正整数次幂的最后kk位的循环长度。

输出格式
一个整数，表示循环长度。如果循环不存在，输出-1。


#include<bits/stdc++.h>
using namespace std;
int xh[11]={1,1,4,4,2,1,1,4,4,2};//打个小表 
int k,b[205],c[205],d[205],p[205],q[205],ss[205],tot1,tot2=2,t;
//d数组:承接各种运算结果并转移
//c数组:存读入数的后k位
//ss数组:存储结果
//b数组:记录c最后一位循环第一次时的c数组
//p,q数组:复制b数组 
//tot1 方便记录c数组
//已循环的位数 
char a[105];
void mul1(int x[],int y[],int z[])//高精*高精 
{
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++)
        {
            z[i+j-1]+=x[i]*y[j];
            z[i+j]+=z[i+j-1]/10;
            z[i+j-1]%=10;
        }
}
void mul2(int x[],int y,int z[])//低精*高精 
{
    for(int i=1;i<=k;i++)
    {
        z[i]+=x[i]*y;
        z[i+1]+=z[i]/10;
        z[i]%=10;
    }
}
int main()
{

    scanf("%s%d",a+1,&k);int len=strlen(a+1);
    for(int i=len;i>=len-k+1;i--) c[++tot1]=a[i]-'0';
    for(int i=1;i<=k;i++) b[i]=c[i];
    for(int i=1;i<xh[c[1]];i++)
    {
        memset(d,0,sizeof(d));
        mul1(b,c,d);
        for(int j=1;j<=k;j++) b[j]=d[j];
    }
    ss[1]=xh[c[1]];
    for(int i=1;i<=k;i++) q[i]=p[i]=b[i];
    while(tot2<=k)
    {
        for(int i=1;i<=k;i++) b[i]=c[i];
        while(t<11)
        {
            memset(d,0,sizeof(d));
            mul1(b,p,d);t++;
            for(int i=1;i<=k;i++) b[i]=d[i];
            if(b[tot2]==c[tot2]) break;
            memset(d,0,sizeof(d));
            mul1(q,p,d);
            for(int i=1;i<=k;i++) q[i]=d[i];
        }
        if(t==11){cout<<-1;return 0;}//如果某一位循环超过10次还未出现循环,则输出-1 
        for(int i=1;i<=k;i++) p[i]=q[i];
        memset(d,0,sizeof(d));
        mul2(ss,t,d);
        for(int i=1;i<=100;i++) ss[i]=d[i];
        tot2++;t=0;
    }
    int len1=105;
    while(ss[len1]==0&&len1>1) len1--;//去除高位0 
    for(int i=len1;i>=1;i--) printf("%d",ss[i]);
}
