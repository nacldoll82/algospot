#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void get_divisor(int num, vector<int> &divisor)
{
	int div, quot, root_num;

	root_num = int(sqrt(num));
	divisor.push_back(1);

	for(div=2; div<=root_num; div++) {
		if(num%div == 0) {
			divisor.push_back(div);
			quot = num/div;
			if(quot != div)
				divisor.push_back(quot);
		}
	}
	sort(divisor.rbegin(), divisor.rend());
}

int find_sum(int init, vector<int> &divisor, int idx, int num)
{
	if(init == num)
		return 1;
	if(init > num || divisor.size() == idx)
		return 0;

	if(find_sum(init+divisor[idx], divisor, idx+1, num))
		return 1;
	return find_sum(init, divisor, idx+1, num);
}

int weird(int num)
{
	int i, sum;
	vector<int> divisor;

	get_divisor(num, divisor);

	sum = 0;
	for(i=0; i<divisor.size(); i++)
		sum += divisor[i];

	if(sum <= num || find_sum(0, divisor, 0, num))
		return 0;

	return 1;
}

int main()
{
	int tcase, num;

	scanf("%d", &tcase);

	while(tcase--) {
		scanf("%d", &num);

		if(weird(num))
			printf("weird\n");
		else
			printf("not weird\n");
	}
}
