#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

//和冬令营的一道题目很像，更复杂。
//由此可见递推和动规的关系了
//虽然这是明显的动规，但是没必要打
//不过这是个很老的题目了，洛谷上只有90个人做，1个对的。。只有一篇pascal题解，沙发被抢了很伤心。。。
/*
Tips:
  ascii中 a为97,z为122
 */

int n;
string co;
int ct=0;
int C[100];
struct word{
    int loc;//在字符串中的位置
    int len;//长度
    string code;//对应密码
    string w;//string本身
}W[101];
bool ok=false;

void build_C(){
    for (int i=0;i<12;i++)
        C[i]=i/3+1;
    C[12]=5;
    C[13]=5;
    for (int i=14;i<26;i++)
        C[i]=(i+1)/3+1;
}

string change(string s){
    int st=s.length();
    string ans;
    for (int i=0;i<st;i++){
        ans=ans+(char)(C[s[i]-'a']+48);
    }
    return ans;
}

bool cmp(word a,word b){
    return a.loc<=b.loc;
}

bool check(int loc,string c){
    int maxn=loc+c.length();
    for (int i=loc;i<=maxn-1;i++)
        if (co[i]!=c[i-loc])
            return false;
    return true;
}

void solve(int loc,string a){
    if (ok==true) //ok表示已经找到解了
        return ;
    if (loc==ct){
        if (!ok){
            ok=true;
            int temp=a.length();
            for (int i=0;i<temp-1;i++)
                cout<<a[i];
            cout<<endl;
        }
        return ;
    }
    bool flag=false;
    for (int i=1;i<=n;i++){
        if (!ok and  loc+W[i].len<=ct and check(loc,W[i].code)){
            solve(loc+W[i].len,a+W[i].w+' ');
            flag=true;
        }
    }
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    cin>>n;
    cin>>co;
    build_C();//建立字符到密码的映射
    int tloc;
    ct=co.length();
    for (int i=1;i<=n;i++){
        cin>>W[i].w;
        W[i].len=W[i].w.length();
        W[i].code=change(W[i].w);//将密码转换为数字
        tloc=co.find(W[i].code);//这还是史同学教的函数
        if (tloc!=co.npos)//npos=2^32-1 刚好够Int
            W[i].loc=tloc;
        else
            W[i].loc=11111;//赋值，极大值,    
    }
    int st=co.length();//st 记录code的长度
    string stemp;
    solve(0,stemp);
    if (ok==false) 
        cout<<"No Solutions!"<<endl;
    return 0;
}
