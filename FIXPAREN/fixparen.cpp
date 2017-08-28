#include <stdio.h>
#include <string.h>

char pair(char x)
{
	switch (x) {
		case '(' : return ')';
		case ')' : return '(';
		case '<' : return '>';
		case '>' : return '<';
		case '[' : return ']';
		case ']' : return '[';
		case '{' : return '}';
		case '}' : return '{';
	}
}

void fixparen(char *order, char *paren)
{
	int i, top, lp;
	int lpos[50];

	top = -1;

	for (i=0; paren[i]; ++i) {
		if (strchr(order, paren[i]))
			lpos[++top] = i;
		else  {
			lp = lpos[top--];
			if (strchr(order, paren[lp]) < strchr(order, pair(paren[i])))
				paren[i] = pair(paren[lp]);
			else
				paren[lp] = pair(paren[i]);
		}
	}
}

int main()
{
	int tcase;
	char order[5], paren[101];

	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%s%s", paren, order);
		fixparen(order, paren);
		puts(paren);
	}
	return 0;
}
