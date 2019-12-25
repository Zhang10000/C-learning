#include<iostream> 
#include<cstring>
#include<string>
using namespace std;
int n,m,p,fake[21],err,w[200],nx;
string name[100],say[200];
string day[10]={"233","Today is Sunday.","Today is Monday.","Today is Tuesday.","Today is Wednesday.","Today is Thursday.","Today is Friday.","Today is Saturday.",};
void set(int who,int yx){
    //err是错误标记，如果一个人既说真话又说假话显然是不吼滴 
    if(fake[who]&&fake[who]!=yx)err=1;
    else fake[who]=yx;
}
int main(){
    cin>>m>>n>>p;
    for(int i=1;i<=m;i++)
        cin>>name[i];
    for(int i=1;i<=p;i++){
        string nm;
        cin>>nm;//输入这句话是谁说的 
        nm.erase(nm.end()-1);//把冒号搞掉 

        for(int j=1;j<=m;j++)
        if(name[j]==nm)w[i]=j; //判断这句话是谁说的

        getline(cin,say[i]);
        say[i].erase(say[i].begin());//把空格搞掉 
    //  say[i].erase(say[i].end()-1);
    //把换行符去掉，上一行注释如果不去掉自己电脑能过，去掉评测能过。。。 
    }
    for(int td=1;td<=7;td++)//枚举今天是星期几 
    for(int px=1;px<=m;px++){//枚举罪犯是谁 

        //清除标记 
        err=0;
        memset(fake,0,sizeof(fake)); 

        for(int i=1;i<=p;i++){//依次判断每句话 
            int who=w[i];

            if(say[i]=="I am guilty.")set(who,px==who?1:-1);
            //如果一个人是罪犯，而且说自己是罪犯，那他说的就是真话，否则就是假话 

            if(say[i]=="I am not guilty.")set(who,px!=who?1:-1);
            //如果一个人不是罪犯，而且说自己不是罪犯，那他说的就是真话，否则就是假话 

            for(int j=1;j<=7;j++)
            if(say[i]==day[j])set(who,j==td?1:-1);
            //如果一个人说今天是星期几，说对了就是真话，说错了就是假话 
            for(int j=1;j<=m;j++){
                if(say[i]==name[j]+" is guilty.")set(who,j==px?1:-1);
                if(say[i]==name[j]+" is not guilty.")set(who,j!=px?1:-1);
                //显然说对了就是真话，否则就是假话 
            }
        }
        int cnt=0,ppp=0;//cnt:说假话的人数，ppp:不确定的人数 
        for(int i=1;i<=m;i++){
            if(fake[i]==-1)cnt++;
            if(fake[i]==0)ppp++;
        }
        if(!err&&cnt<=n&&cnt+ppp>=n)
        // 如果cnt<=n<=cnt+ppp，就说明这个假设合理 
        //如果出现Impossible的情况，怎么枚举都会err，这里直接跳过就行了 
            if(nx&&nx!=px){
                //出现了两个合理的罪犯 
                cout<<"Cannot Determine";
                return 0;
            }else nx=px;
    }
    if(!nx)cout<<"Impossible"; 
    else cout<<name[nx];
}
