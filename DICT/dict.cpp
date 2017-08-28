#include <stdio.h>
unsigned long long cache[201][201];

unsigned long long dict(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	if (cache[n][r] == 0)
		cache[n][r] = dict(n-1, r) + dict(n-1, r-1);
	return cache[n][r];
}


void get_word(int a, int b, int order, char *word)
{
	if ( a==0 || b == 0) {
		while (a>0) {
			*word++ = 'a';
			a--;
		}
		while (b>0) {
			*word++ = 'b';
			b--;
		}
		*word = 0;
		return;
	}

	if (order <= dict(a+b-1, a-1)) {
		*word = 'a';
		get_word(a-1, b, order, word+1);
	}
	else {
		*word = 'b';
		get_word(a, b-1, order-dict(a+b-1,a-1), word+1);
	}
}

int main()
{
	int tcase, a, b, order;
	char word[201];

	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d%d%d", &a, &b, &order);
		if (order > dict(a+b, a))
			puts("NONE");
		else {
			get_word(a, b, order, word);
			puts(word);
		}
	}
}
