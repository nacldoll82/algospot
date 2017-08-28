#include <cstdio>
#include <algorithm>
const int EMPTY = -2;

int volmax[51][1001];
int n, upper, vm[50];

void init_volmax()
{
	int i, j;

	for (i=0; i<n; ++i)
		for (j=0; j<=upper; ++j)
			volmax[i][j] = EMPTY;
}

int get_vol(int seq, int vol)
{
	if (vol < 0 || vol > upper) return -1;
	if (seq == n) return vol;

	int &ret = volmax[seq][vol];
	if(ret == EMPTY)
		ret = std::max(get_vol(seq+1, vol+vm[seq]), get_vol(seq+1, vol-vm[seq]));

	return ret;
}

int main()
{
	int tcase, vs, i;

	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d%d%d", &n, &vs, &upper);
		for (i=0; i<n; ++i)
			scanf("%d", &vm[i]);

		init_volmax();
		printf("%d\n", get_vol(0, vs));
	}
}
