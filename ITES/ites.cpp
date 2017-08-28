#include <cstdio>
#include <queue>

int ites(int bound, int len)
{
	int result, sum, cur;
	unsigned int seed;
	std::queue<int> q;

	sum = result = 0;
	seed = 1983;

	while(len--) {
		cur = seed%10000 + 1;
		q.push(cur);
		sum += cur;

		while(sum > bound) {
			sum -= q.front();
			q.pop();
		}
		if(sum == bound)
			result++;
		seed = seed*214013 + 2531011;
	}
	return result;
}

int main()
{
	int tcase, bound, len;

	scanf("%d", &tcase);
	while(tcase--) {
		scanf("%d%d", &bound, &len);
		printf("%d\n", ites(bound, len));
	}
	return 0;
}
