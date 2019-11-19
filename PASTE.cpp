我们用文本处理器来处理一个特殊的文本文件，该文本文件共有N行文本，每一行文本仅包含一个自然数，
第一行为11、第二行为22，以此类推至N行为自然数NN。

假设对该文本文件执行一次“剪切和粘贴”操作含义如下：首先选定连续的若干行文本，“剪切”操作将选
定的文本从文件中剪下，而“粘贴”操作将剪切下来的文本插入到文件中的其他地方。

编写一个程序求出在进行了连续若干次“剪切和粘贴”操作后，文本文件中前十行的内容。


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;
int n, k;
int doc[MAXN], temp[MAXN];
int cnt;

int main()
{
    for (int i = 1; i < MAXN; i++) doc[i] = i;
    cin >> n >> k;
    for (int oper = 0; oper < k; oper++)
    {
        int s, t, p1, p2, ins, len;
        cin >> s >> t >> ins;
        len = t - s + 1;
        p1 = ins + 1;
        p2 = p1 + len - 1;
        cnt = 0;
        for (int i = s; i <= t; i++) temp[++cnt] = doc[i];
        if (ins < s) for (int i = s - 1; i >= p1; i--) doc[i + len] = doc[i];
        else for (int i = t + 1; i <= p2; i++) doc[i - len] = doc[i];
        for (int i = p2; i >= p1; i--) doc[i] = temp[cnt--];
    }
    for (int i = 1; i <= 10; i++) cout << doc[i] << endl;
    return 0;
}
