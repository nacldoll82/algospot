#include <cstdio>
#include <algorithm>
using namespace std;

pair<int,int> do_find(int len, int interval)
{
	int i, arr[1000], target;

	for(i=0; i<len; i++)
		arr[i] = i;

	target = 0;
	while(len > 2) {
		for(i=target+1; i<len; i++)
			arr[i-1] = arr[i];
		len--;
		target = ((target-1) + interval)%len;
	}

	return pair<int, int>(arr[0]+1, arr[1]+1);
}

int main()
{
	int tcase, len, interval;
	pair<int, int> remain;

	scanf("%d", &tcase);

	while(tcase--) {
		scanf("%d%d", &len, &interval);
		remain = do_find(len, interval);

		printf("%d %d\n", remain.first, remain.second);
	}

	return 0;
}
