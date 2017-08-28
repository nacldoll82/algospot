#include <stdio.h>

const int DIV = 1000000007;

long long power(int x,int n)
{
	long long res;

	if (n==1)
		return x % DIV;

	if (n&1)
		return (x * power(x, n-1))%DIV;

	res = power(x, n/2);
	res = (res*res) % DIV;

	return res;
}

long long getsum(int x, int n)
{
	if (n==0)
		return 0;
	if (n==1)
		return x;
	if (n&1)
		return (power(x, n) + getsum(x, n-1))%DIV;

	return ((1+power(x, n/2)) * getsum(x, n/2))%DIV;

}

int main()
{
	int tcase, low, high, digit;

	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d%d%d", &low, &high, &digit);
		printf("%lld\n", (getsum(digit, high) - getsum(digit, low-1) + DIV)%DIV);
	}
	return 0;
}
