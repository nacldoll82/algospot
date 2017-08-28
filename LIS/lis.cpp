#include <cstdio>
#include <algorithm>
using namespace std;

int find_lis(int seq[], int seq_len)
{
	int i, j, max_len;
	int seq_val[501];
	int *pos, pos_val;

	max_len = 1;
	seq_val[0] = seq[0];

	for(i=1; i<seq_len; ++i) {
		pos = lower_bound(seq_val, seq_val + max_len, seq[i]);
		*pos = seq[i];
		max_len = max(max_len, int(pos - seq_val + 1));
	}   

	return max_len;
}

int main()
{
	int i, j;
	int Tcase, seq_len, seq[500];
	int result;


	scanf("%d", &Tcase);

	while(Tcase--) {
		scanf("%d", &seq_len);
		for(i=0; i<seq_len; ++i)
			scanf("%d", &seq[i]);

		result = find_lis(seq, seq_len);
		printf("%d\n", result);
	}   

	return 0;
}
