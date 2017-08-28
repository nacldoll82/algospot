#include <cstdio>
using namespace std;

const int Magic_number = 1000000007;

int find_count(int coins[], int coin_cnt, int money)
{
	int i, j;
	int count[5001];

	count[0] = 1;
	for(i=1; i<=money; i++)
		count[i] = 0;

	for(i=0; i<coin_cnt; i++) {
		for(j=coins[i]; j<=money; j++) {
			count[j] = (count[j] + count[j-coins[i]])%Magic_number;

		}   
	}   

	return count[money];
}

int main()
{
	int i;
	int coins[100];
	int tcase, money, coin_cnt;

	scanf("%d", &tcase);

	while(tcase--) {
		scanf("%d%d", &money, &coin_cnt);
		for(i=0; i<coin_cnt; i++)
			scanf("%d", &coins[i]);

		printf("%d\n", find_count(coins, coin_cnt, money));
	}   
}
