#include <iostream>
#include <string>
using namespace std;

string reverse_tree(char **pos)
{
	char c = **pos;
	(*pos)++;

	if ( c == 'b' || c == 'w')
		return string(1, c);

	string sub[4];
	sub[0] = reverse_tree(pos);
	sub[1] = reverse_tree(pos);
	sub[2] = reverse_tree(pos);
	sub[3] = reverse_tree(pos);

	return "x" + sub[2] + sub[3] + sub[0] + sub[1];
}

int main()
{
	int tcase;
	char *pos;
	string input;

	cin >> tcase;

	while (tcase--) {
		cin >> input;
		pos = &(input[0]);
		cout << reverse_tree(&pos) << endl;
	}
	return 0;
}
