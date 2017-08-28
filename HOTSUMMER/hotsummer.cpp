#include <cstdio>

int is_ok()
{
	int w, a, i;

	scanf("%d", &w);
	for (i=0; i<9; ++i) {
		scanf("%d", &a);
		w -= a;
	}

	return (w >= 0);
}

int main()
{
	int tcase;

	scanf("%d", &tcase);
	while (tcase--) {
		puts(is_ok()?"YES":"NO");
	}
	return 0;
}
