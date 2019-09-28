//有三只球队，每只球队编号分别为球队1，球队2，球队3，这三只球队一共需要进行  //n 场比赛。现在已经踢完了k场比赛，每场比赛不能打平，踢赢一场比赛得一分，输 //了不得分不减分。已知球队1和球队2的比分相差d1分，球队2和球队3的比分相差d2分 //，每场比赛可以任意选择两只队伍进行。求如果打完最后的(n - k) 场比赛，有没有 //可能三只球队的分数打平。  //第一行包含一个数字 t(1 <= t <= 10)
//接下来的t行每行包括四个数字 n, k, d1, d2(1 <= n <= 10 ^ 12; 0 <= k <= n, 
//0 <= d1, d2 <= k)

#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
int T;
LL n;
LL k;
LL d1;
LL d2;
bool F(LL A)
{
	return A >= 0 && A <= n;
}
void Solve()
{
	scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
	if (n % 3)
	{
		printf("no\n");
		return;
	}
	LL N, x1, x2, x3;
	N = k - d1 - d2;
	if (F(N) && !(N % 3))
	{
		x2 = N / 3;
		x1 = x2 + d1;
		x3 = x2 + d2;
		if (F(x1) && F(x2) && F(x3))
			if (x1 <= n / 3 && x2 <= n / 3 && x3 <= n / 3)
			{
				printf("yes\n");
				return;
			}
	}
	N = k + d2 - d1;
	if (F(N) && !(N % 3))
	{
		x2 = N / 3;
		x1 = x2 + d1;
		x3 = x2 - d2;
		if (F(x1) && F(x2) && F(x3))
			if (x1 <= n / 3 && x2 <= n / 3 && x3 <= n / 3)
			{
				printf("yes\n");
				return;
			}
	}
	N = k - d2 + d1;
	if (F(N) && !(N % 3))
	{
		x2 = N / 3;
		x1 = x2 - d1;
		x3 = x2 + d2;
		if (F(x1) && F(x2) && F(x3))
			if (x1 <= n / 3 && x2 <= n / 3 && x3 <= n / 3)
			{
				printf("yes\n");
				return;
			}
	}
	N = k + d1 + d2;
	if (F(N) && !(N % 3))
	{
		x2 = N / 3;
		x1 = x2 - d1;
		x3 = x2 - d2;
		if (F(x1) && F(x2) && F(x3))
			if (x1 <= n / 3 && x2 <= n / 3 && x3 <= n / 3)
			{
				printf("yes\n");
				return;
			}
	}
	printf("no\n");
}

int main()
{
	//  freopen("in.txt","r",stdin);
	scanf("%d", &T);
	while (T--) Solve();
	return 0;
}