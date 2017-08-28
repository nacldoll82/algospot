#include <cstdio>

int get_maxarea()
{
	int n, height[20002], left[20002], stack[20002];
	int i, maxarea, area, top;

	scanf("%d", &n);
	for (i=1; i<=n; ++i)
		scanf("%d", &height[i]);

	left[0] = 0;
	height[0] = height[n+1] = 0;
	maxarea = 0;
	top = 0;
	stack[top] = 0;

	for (i=1; i<=n+1; ++i) {	
		while (height[stack[top]] > height[i]) {
			area = height[stack[top]] * (i-left[stack[top]]);
			if(area > maxarea)
				maxarea = area;
			top--;
		}
		if (height[i] == height[stack[top]]) {
			left[i] = left[stack[top]];
			top--;
		}
		else
			left[i] = stack[top]+1;

		stack[++top] = i;
	}
	return maxarea;
}

int main()
{
	int tcase;

	scanf("%d", &tcase);
	while (tcase--) {
		printf("%d\n", get_maxarea());
	}
}
