#include <cstdio>
#include <algorithm>
using namespace std;

int trimax(const int tri[][100], const int len)
{
	int i, j;
	int maxval[100][100];
	int ret;

	maxval[0][0] = tri[0][0];

	for(i=1; i<len; i++) {
		for(j=0; j<=i; j++) {
			if (j==0)
				maxval[i][j] = maxval[i-1][j] + tri[i][j];
			else
				maxval[i][j] = max(maxval[i-1][j], maxval[i-1][j-1]) + tri[i][j];
		}   
	}   

	i = len-1;
	ret = maxval[i][0];
	for (j=1; j<len; ++j)
		ret = max(ret, maxval[i][j]);

	return ret;
}

int main()
{
	int tcase, len;
	int tri[100][100];
	int i, j;

	scanf("%d", &tcase);

	while(tcase--) {
		scanf("%d", &len);

		for(i=0; i<len; i++) {
			for(j=0; j<=i; j++)
				scanf("%d", &tri[i][j]);
		}   
		printf("%d\n", trimax(tri, len));
	}   

	return 0;
}
