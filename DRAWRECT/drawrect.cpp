#include<cstdio>

int main()
{
	int t, x1,x2,x3, y1,y2,y3;

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3);
		printf("%d %d\n", x1^x2^x3, y1^y2^y3);
	}
	return 0;
}
