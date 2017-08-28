#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int Magic=20090711;

int median_sum(int len, int a, int b)
{
	int i, median_sum, cur;

	priority_queue<int> left_q; 
	priority_queue<int , vector<int>, greater<int> > right_q; 

	cur = 1983;
	left_q.push(cur);
	median_sum = cur;

	for(i=1; i<len ; i++) {
		cur = ((long long)cur*a + b)%Magic;
		if(cur <= left_q.top()) {
			left_q.push(cur);
			if(left_q.size()>right_q.size()+1) {
				right_q.push(left_q.top());
				left_q.pop();
			}
		}
		else {
			right_q.push(cur);
			if(left_q.size()<right_q.size()) {
				left_q.push(right_q.top());
				right_q.pop();
			}
		}
		median_sum = (median_sum + left_q.top())%Magic;
	}
	return median_sum;
}

int main()
{
	int tcase, len, a, b;

	scanf("%d", &tcase);
	while(tcase--) {
		scanf("%d%d%d", &len, &a, &b);
		printf("%d\n", median_sum(len, a, b));
	}
	return 0;
}
