#include <cstdio>
const int Magic=10007;

void matmul(int src1[][100], int src2[][100], int dest[][100], int size)
{
	int i, j, k;

	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			dest[i][j] = 0;
			for(k=0; k<size; k++)
				dest[i][j] = (dest[i][j] + src1[i][k] * src2[k][j])%Magic;
		}
	}
}

void matexp(int src[][100], int size, int e, int dest[][100])
{
	int i, j;
	int mid[100][100];

	if(e == 1) {
		for(i=0; i<size; i++)
			for(j=0; j<size; j++)
				dest[i][j] = src[i][j];
		return;
	}

	if(e%2 == 1) {
		matexp(src, size, e-1, mid);
		matmul(mid, src, dest, size);
	}
	else {
		matexp(src, size, e/2, mid);
		matmul(mid, mid, dest, size);
	}
}

void matprint(int mat[][100], int size)
{
	int i, j;

	for(i=0; i<size; i++) {
		for(j=0; j<size; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

int main()
{
	int i, j;
	int tcase, size, e;
	int arr[100][100], dest[100][100];

	scanf("%d", &tcase);
	while(tcase--) {
		scanf("%d%d", &size, &e);
		for(i=0; i<size; i++)
			for(j=0; j<size; j++)
				scanf("%d", &arr[i][j]);

		matexp(arr, size, e, dest);
		matprint(dest, size);
	}
}
