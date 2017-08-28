#include <cstdio>

int subsum(int *sum, int first, int last)
{
	if (first == 0) return sum[last];
	return sum[last] - sum[first-1];
}

void make_sum(int *day, int len, int *sum)
{
	sum[0] = day[0];
	for (int i=1; i<len; ++i)
		sum[i] = sum[i-1] + day[i];
}

float get_val(int *day, int len, int bound)
{
	int i, j, cnt, m_cnt, cost, m_cost;
	int sum[1000];

	m_cnt = 1;
	m_cost = 100000;
	make_sum(day, len, sum);

	for (i=0; i<=len-bound; ++i) {
		for (j=i+bound-1; j<len; ++j) {
			cost = subsum(sum, i, j);
			cnt = j-i+1;
			if (cnt >= bound && m_cost * cnt > m_cnt * cost) {
				m_cost = cost;
				m_cnt = cnt;
			}
		}
	}
	return (float)m_cost/m_cnt;
}

int main()
{
	int tcase, i;
	int len, bound, day[1000];

	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%d%d", &len, &bound);
		for (i=0; i<len; ++i)
			scanf("%d", &day[i]);
		printf("%.8f\n", get_val(day, len, bound));
	}
}
