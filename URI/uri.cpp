#include <stdio.h>
#include <string.h>

char *tbl[7][2] = {
	{"%20", " "},
	{"%21", "!"},
	{"%24", "$"},
	{"%25", "%"},
	{"%28", "("},
	{"%29", ")"},
	{"%2a", "*"}
};

void decode(char *src, char *dst)
{
	int si, ti, di;

	si = di = 0;
	while (src[si]) {
		for (ti=0; ti<7; ++ti) {
			if (strncmp(src+si, tbl[ti][0], 3) == 0)
				break;
		}

		if (ti < 7) {
			dst[di] = tbl[ti][1][0];
			si += 3;
		}
		else {
			dst[di] = src[si];
			si++;
		}
		di++;
	}
	dst[di] = 0;
}

int main()
{
	int tcase;
	char src[101], dst[101];

	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%s", src);
		decode(src, dst);
		printf("%s\n", dst);
	}
	return 0;
}
