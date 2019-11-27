给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。

一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）


class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen=s.length(),tLen = t.length();
        unsigned long table[tLen];for (int i = 0; i < tLen; i ++) table[i] = 0;
        for(int i=0;i<sLen;++i){
            for(int j=tLen-1;j>=0;--j){
                if(s[i]==t[j]){
                    if(j==0)++table[0];
                    else table[j]+=table[j-1];
                }
            }
        }
        return table[tLen-1];
    }
};
