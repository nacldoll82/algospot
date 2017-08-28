#include <stdio.h>
unsigned int cache[1000];

unsigned int grid(int n)
{
	if (cache[n])
		return cache[n];

	cache[n] = grid(n-1) - grid(n-4) + 5*grid(n-2) + grid(n-3);
	return cache[n];
}

int main()
{
	int i, k, tcase;

	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 5;
	cache[3] = 11;

	scanf("%d", &tcase);

	for (i=1; i<=tcase; ++i) {
		scanf("%d", &k);
		printf("%d %u\n", i, grid(k));
	}
	return 0;
}
