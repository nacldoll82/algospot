#include <cstdio>
#include <algorithm>

int lis(int *seq, int seq_len)
{
	int i, *pos;
	int last[500], max_len;

	max_len = 1;
	last[0] = seq[0];

	for(i=1; i<seq_len; ++i) {
		pos = std::lower_bound(last, last+max_len, seq[i]);
		*pos = seq[i];
		if(pos == last+max_len)
			max_len++;
	}
	return max_len;
}

int main()
{
	int tcase, i;
	int seq_len, seq[500];

	scanf("%d", &tcase);

	while(tcase--) {
		scanf("%d", &seq_len);
		for(i=0; i<seq_len; ++i)
			scanf("%d", &seq[i]);

		printf("%d\n", lis(seq, seq_len));
	}
	return 0;
}
