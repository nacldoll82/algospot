#include <cstdio>
#include <algorithm>

double tsp(double path[][8], int cnt)
{
	double min_path = 987654;
	double tmp;
	int order[8], i;

	for (i=0; i<cnt; ++i)
		order[i] = i;

	do {
		tmp = 0;
		for (i=1; i<cnt; ++i) {
			tmp += path[order[i-1]][order[i]];
			if (tmp > min_path)
				break;
		}
		if (tmp < min_path)
			min_path = tmp;
	} while ( std::next_permutation(order, order+cnt));

	return min_path;
}

int main()
{
	int tcase;
	int cnt, i, j;
	double path[8][8];

	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%d", &cnt);

		for (i=0; i<cnt; ++i)
			for (j=0; j<cnt; ++j)
				scanf("%lf", &path[i][j]);

		printf("%.10lf\n", tsp(path, cnt));
	}

	return 0;
}
