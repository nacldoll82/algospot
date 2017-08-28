#include <cstdio>

int mat[200][200], sum[200][200], size;

void make_colsum()
{
	int row, col;

	for (col=0; col<size; ++col) {
		sum[0][col] = mat[0][col];
		for (row=1; row<size; row++)
			sum[row][col] = sum[row-1][col] + mat[row][col];
	}
}

int colsum(int row, int row_cnt, int col)
{
	if (row == 0)
		return sum[row+row_cnt-1][col]; 
	else
		return sum[row+row_cnt-1][col] - sum[row-1][col];
}

int maxmat()
{
	int row, row_cnt, col;
	int maxsum, localsum, val;

	maxsum = mat[0][0];
	for (row=0; row<size; ++row) {
		for (row_cnt=1; row+row_cnt<=size; ++row_cnt) {
			localsum = colsum(row, row_cnt, 0);

			for (col=1; col<size; ++col) {
				val = colsum(row, row_cnt, col);

				if (localsum <= 0)
					localsum = val;
				else
					localsum += val;

				if(localsum > maxsum)
					maxsum = localsum;
			}
		}
	}
	return maxsum;
}

int main()
{
	int tcase, i, j;

	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%d", &size);
		for (i=0; i<size; i++)
			for (j=0; j<size; j++)
				scanf("%d", &mat[i][j]);
		make_colsum();
		printf("%d\n", maxmat());
	}
}
