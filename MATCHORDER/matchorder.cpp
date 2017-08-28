#include <algorithm>
#include <iostream>

using namespace std;

int match(int *russia, int *korea, int tlen)
{
	int ri, ki, mki, win;
	int klen, found;

	win = 0;
	klen = tlen;

	for (ri=0; ri<tlen; ri++) {
		found = 0;
		for (ki=0; ki<klen; ki++) {
			if (korea[ki] >= russia[ri]) {
				if (!found) {
					mki = ki;
					found = 1;
				}
				else if (korea[ki] < korea[mki])
					mki = ki;
			}
		}
		if (found) {
			swap(korea[mki], korea[--klen]);
			win++;
		}

	}
	return win;
}

int main()
{
	int tcase, tlen, i;
	int russia[100], korea[100];

	cin >> tcase;

	while (tcase--) {
		cin >> tlen;
		for (i=0; i<tlen; ++i)
			cin >> russia[i];
		for (i=0; i<tlen; ++i)
			cin >> korea[i];
		cout << match(russia, korea, tlen) << endl;
	}
}
