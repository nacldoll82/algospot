#include<cstdio>

void input_process(char *input, int *toggle)
{
	int i;

	toggle[0]=0;
	for(i=1; input[i]!=0; i++) {
		if(input[i] == input[i-1])
			toggle[i] = toggle[i-1];
		else
			toggle[i] = toggle[i-1]+1;
	}
}

int main()
{
	char input[1000001];
	int tcase, first, last;
	int toggle[1000001];

	scanf("%s", input);
	input_process(input, toggle);

	scanf("%d", &tcase);
	while(tcase--) {
		scanf("%d%d", &first, &last);
		puts(toggle[first]==toggle[last]?"Yes":"No");
	}
	return 0;
}
