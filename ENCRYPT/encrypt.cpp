#include <stdio.h>
#include <string.h>

int main()
{
	int tcase, len, i;
	char str[101];

	scanf("%d", &tcase);
	while(tcase--) {
		scanf("%s", str);
		len = strlen(str);

		for(i=0; i<len; i+=2)
			printf("%c", str[i]);
		for(i=1; i<len; i+=2)
			printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}
