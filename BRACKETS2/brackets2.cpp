#include <cstdio>

int ptr;
int iserror;
char str[10001];

void init()
{
	ptr = 0;
	iserror = 0;
}

void goahead()
{
	++ptr;
}

int parsed_ok()
{
	return (str[ptr]==0 && iserror==0);
}

int match(char c)
{
	return (str[ptr] == c);
}

void parse()
{
	if (match('\0') || match(')') || match('}') || match(']'))
		return;

	if (match('(')) {
		goahead();
		parse();
		if(!match(')')) {
			iserror = 1;
			return;
		}
		goahead();
		parse();
	}
	else if (match('{')) {
		goahead();
		parse();
		if(!match('}')) {
			iserror = 1;
			return;
		}
		goahead();
		parse();
	}
	else if (match('[')) {
		goahead();
		parse();
		if(!match(']')) {
			iserror = 1;
			return;
		}
		goahead();
		parse();
	}
	else
		iserror = 1;
}

int main()
{
	int tcase;

	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%s", str);
		init();
		parse();

		if (parsed_ok())
			printf("YES\n");
		else
			printf("NO\n");
	}

}
