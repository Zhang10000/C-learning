// 键盘输入一个高精度的正整数NN（不超过250250位） ，去掉其中任意kk个数字后剩下的数字按原左右次序将组成一个新的正整数。
// 编程对给定的NN和kk，寻找一种方案使得剩下的数字组成的新数最小。


#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

std::string n;
int k;

std::string tmp,t;
int main(){
    std::cin>>n>>k;
    for(int i=1,l=n.size();i<=k;i++,l--){
        tmp=std::string(250,'9');
        int j=0;
        for(register int i=0;i<l;i++){
            t=n;t.erase(i,1);
            if(t<tmp){
                tmp=t;
                j=i;
            }
        }
        n.erase(j,1);
    }
    std::cout<<n<<std::endl;
    return 0;
}
