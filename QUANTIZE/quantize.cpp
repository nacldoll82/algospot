#include <cstdio>
#include <algorithm>
using namespace std;

int tcase, seq_len, num_cnt;
int seq[100];
int cache[100][11];

int quantize(int seq_idx, int num_remain)
{
	int sum, ssum, qtm, cnt;
	int i, sse, tmpse;

	if (seq_idx == seq_len)
		return 0;

	if (cache[seq_idx][num_remain] != -1)
		return cache[seq_idx][num_remain];

	sum = ssum = cnt = 0;

	if (num_remain == 1) {
		for (i=seq_idx; i<seq_len; ++i) {
			sum += seq[i];
			ssum += seq[i]*seq[i];
			cnt++;
		}

		qtm = (double)sum/cnt + 0.5;
		sse = ssum + cnt*qtm*qtm - 2*sum*qtm;
	}
	else {
		sse = 987654321;
		for (i=seq_idx; i<seq_len; ++i) {
			sum += seq[i];
			ssum += seq[i]*seq[i];
			cnt++;
			qtm = (double)sum/cnt + 0.5;

			tmpse = ssum + cnt*qtm*qtm - 2*sum*qtm;
			tmpse += quantize(i+1, num_remain-1);
			if(tmpse < sse)
				sse = tmpse;
		}
	}

	cache[seq_idx][num_remain] = sse;
	return sse;
}

int main()
{
	int i, j;

	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d%d", &seq_len, &num_cnt);
		for (i=0; i<seq_len; ++i)
			scanf("%d", &seq[i]);
		sort(seq, seq+seq_len);

		for (i=0; i<seq_len; ++i)
			for (j=0; j<=num_cnt; ++j)
				cache[i][j] = -1;

		printf("%d\n", quantize(0, num_cnt));
	}
	return 0;
}
