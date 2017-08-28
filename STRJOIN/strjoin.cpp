#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int strjoin()
{
	priority_queue<int, vector<int>, greater<int> > q;
	int cnt, elmt, sum = 0;

	scanf("%d" , &cnt);
	while (cnt--) {
		scanf("%d" , &elmt);
		q.push(elmt);
	}

	while (q.size() > 1) {
		elmt = q.top();
		q.pop();
		elmt += q.top();
		q.pop();
		q.push(elmt);
		sum += elmt;
	}
	return sum;
}

int main()
{
	int tcase;

	scanf("%d", &tcase);
	while(tcase--)
		printf("%d\n", strjoin());

	return 0;
}
