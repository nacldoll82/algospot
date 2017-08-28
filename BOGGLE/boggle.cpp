#include <cstdio>
#include <cstring>

int delta[8][2] = {
	{-1,-1}, {-1, 0}, {-1, 1},
	{0, -1}, {0, 1},
	{1,-1}, {1, 0}, {1, 1}
};

char board[5][6], cache[2][5][5];

int find(int row, int col, char c, int num)
{
	int i, new_row, new_col, is_find=0;

	if (!c) return 1;

	for (i=0; i<8; ++i) {
		new_row = row + delta[i][0];
		new_col = col + delta[i][1];

		if (new_row >= 0 && new_row < 5 && new_col >= 0 && new_col < 5  &&
				board[new_row][new_col] == c) {
			cache[num&1][new_row][new_col] = num;
			is_find = 1;
		}
	}
	return is_find;
}

int boggle(char *str)
{
	int i, j, num, is_find;

	memset(cache[0], 0, sizeof(cache[0]));
	for (num = 0; str[num]; ++num) {
		is_find = 0;
		for (i=0; i<5; ++i) {
			for (j=0; j<5; ++j) {
				if (board[i][j] == str[num] && cache[num&1][i][j] == num &&
						find(i, j, str[num+1], num+1))
					is_find = 1;
			}
		}
		if (is_find == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int i, cnt, tcase;
	char str[11];

	scanf("%d", &tcase);
	while (tcase--) {
		for (i=0; i<5; ++i)
			scanf("%s", board[i]);

		scanf("%d", &cnt);
		while (cnt--) {
			scanf("%s", str);
			printf("%s %s\n", str, boggle(str)?"YES":"NO");
		}
	}
}
