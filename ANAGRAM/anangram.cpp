#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int isAnagram(string str1, string str2)
{
	if(str1.compare(str2)==0)
		return 0;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	if(str1.compare(str2)==0)
		return 1;
	return 0;
}

int main()
{
	int tcase;
	string str1, str2;

	cin >> tcase;
	while(tcase--) {
		cin >> str1 >> str2;
		if (isAnagram(str1, str2))
			cout << "Yes\n";
		else
			cout << "No.\n";
	}

	return 0;
}
