//给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

//字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
//每个元音 'a' 后面都只能跟着 'e'
//每个元音 'e' 后面只能跟着 'a' 或者是 'i'
//每个元音 'i' 后面 不能 再跟着另一个 'i'
//每个元音 'o' 后面只能跟着 'i' 或者是 'u'
//每个元音 'u' 后面只能跟着 'a'
//由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果

class Solution {
public:
    int countVowelPermutation(int n) {
        const int M = 1e9+7;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 2; k <= n; k++) {
            long aa = (e+i+u)%M;
            long ee = (a+i)%M;
            long ii = (e+o)%M;
            long oo = i;
            long uu = (o+i)%M;
            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
        }
        return (a+e+i+o+u)%M;
    }
};
