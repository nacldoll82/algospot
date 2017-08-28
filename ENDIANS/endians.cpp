#include <stdio.h>

int main()
{
	int tcase;
	char num[4], res[4];

	scanf("%d", &tcase);
	while(tcase--) {
		scanf("%u", &num);

		res[0] = num[3];
		res[1] = num[2];
		res[2] = num[1];
		res[3] = num[0];

		printf("%u\n", *(unsigned int *)res);
	}
	return 0;
}
