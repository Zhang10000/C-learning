#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
double h,s1,v,l,k;
int n;
int main()
{
    scanf("%lf%lf%lf%lf%lf%d",&h,&s1,&v,&l,&k,&n);
    double time_oncar=sqrt((h-k)/5);
    double carend=(s1+l)-v*time_oncar+0.0001;
    double time_under=sqrt(h/5);
    double start=s1-v*time_under-0.0001;
    int s,e,ans;
    s=start;
    if(double(s)!=start)s++;
    e=carend;
    ans=min(n-1,e)-max(0,s)+1;
    printf("%d",max(ans,0));
}
