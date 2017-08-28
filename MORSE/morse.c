#include <stdio.h>
unsigned long long morse[201][201];

void init_morse()
{
	int n, r;

	for(n=1; n<=200; ++n) {
		for(r=0; r<=n; ++r) {
			if(n == r || r == 0)
				morse[n][r] = 1;
			else
				morse[n][r] = morse[n-1][r] + morse[n-1][r-1];
		}
	}
}

void get_morse(int dash, int dot, int order, char *sign)
{
	int len = 0;

	while(dash > 0 && dot > 0) {
		if(order > morse[dash+dot-1][dash-1]) {
			sign[len++] = 'o';
			order -= morse[dash+dot-1][dash-1];
			dot--;
		}
		else {
			sign[len++] = '-';
			dash--;
		}
	}

	while(dash>0) {
		sign[len++] = '-';
		dash--;
	}
	while(dot>0) {
		sign[len++] = 'o';
		dot--;
	}
	sign[len] = 0;
}

int main()
{
	int tcase, dash, dot, order;
	char sign[201];

	init_morse();
	scanf("%d", &tcase);

	while(tcase--) {
		scanf("%d%d%d", &dash, &dot, &order);
		get_morse(dash, dot, order, sign);
		puts(sign);
	}
}
