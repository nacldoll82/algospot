#include <cstdio>
#include <cstring>

#define LIMIT 1000001

int tree[LIMIT+1], size;

int get_sum(int idx)
{
	int val = 0;

	while (idx) {
		val += tree[idx];
		idx &= (idx-1);
	}
	return val;
}

void add(int idx)
{
	while (idx <= LIMIT) {
		++tree[idx];
		idx += (idx & -idx);
	}
}

int measure()
{
	int val, sum = 0;

	memset(tree, 0x00, sizeof(tree));

	while (size--) {
		scanf("%d", &val);
		add(LIMIT-val);
		sum += get_sum(LIMIT-val-1);
	}
	return sum;
}

int main()
{
	int tcase;

	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%d", &size);
		printf("%d\n", measure());
	}
	return 0;
}
