#include <cstdio>
const int EMPTY=-1;

int size;
int grid[100][100], memo[100][100];

void init_memo()
{
	int i, j;

	for (i=0; i<size; ++i)
		for (j=0; j<size; ++j)
			memo[i][j] = EMPTY;
	memo[size-1][size-1] = 1;
}

int jump(int y, int x)
{
	if (y >= size || x >= size)
		return 0;

	if (memo[y][x] == EMPTY)
		memo[y][x] = jump(y+grid[y][x], x) || jump(y, x+grid[y][x]);

	return memo[y][x];
}

int main()
{
	int tcase, i, j;

	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d", &size);

		for (i=0; i<size; ++i) {
			for (j=0; j<size; ++j)
				scanf("%d", &grid[i][j]);
		}

		init_memo();
		if (jump(0,0))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
