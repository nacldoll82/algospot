#include <cstdio>
const int Magic=1000000007;

int tile1[101], tile2[101];

int tiling2(int size)
{
	if (size < 2) return 1;
	if (size == 2) return 2;

	if ( !tile2[size] )
		tile2[size] = (tiling2(size-1)+tiling2(size-2)) % Magic;
	return tile2[size];
}

int tiling1(int size)
{
	if (size < 3) return 0;

	if ( !tile1[size] )
		tile1[size] = (2*tiling2(size-3)%Magic +
				(tiling1(size-2)+tiling1(size-4))%Magic) % Magic;
	return tile1[size];
}

int main()
{
	int tcase, size, i;

	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d", &size);
		printf("%d\n", tiling1(size));
	}
	return 0;
}
