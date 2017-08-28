#include<cstdio>

int main()
{
	int tcase, len, val;
	int maxsum, sum;

	scanf("%d", &tcase);

	while(tcase--) {
		scanf("%d", &len);
		sum = maxsum = 0;
		while(len--) {
			scanf("%d", &val);
			sum = (sum<=0)?val:sum+val;
			if(sum > maxsum)
				maxsum = sum;
		}
		printf("%d\n", maxsum);
	}
	return 0;
}
