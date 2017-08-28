#include <cstdio>
#include <cstring>

char board[12][12];

void set(int q_cnt, int row, int col, int setval)
{
	for (int i=1; i+row<q_cnt; i++) {
		board[row+i][col] += setval;
		if (col-i >= 0)
			board[row+i][col-i] += setval;
		if (col+i <q_cnt)
			board[row+i][col+i] += setval;
	}
}

int nq_count(int q_cnt, int row)
{
	int solution = 0;

	if (row == q_cnt)
		return 1;

	for (int col=0; col<q_cnt; col++) {
		if(board[row][col]==0) {
			set(q_cnt, row, col, 1);
			solution += nq_count(q_cnt, row+1);
			set(q_cnt, row, col, -1);
		}
	}
	return solution;
}

int main()
{
	int tcase, q_cnt;

	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%d", &q_cnt);
		memset(board, 0, sizeof(board));
		printf("%d\n", nq_count(q_cnt, 0));
	}
	return 0;
}
