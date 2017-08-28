#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int tcase, val;
	string op1, op2, code, eq, res;
	map<string, int> num;
	map<string, int>::iterator it;

	num["eorz"] = 0;
	num["eno"] = 1;
	num["otw"] = 2;
	num["eehrt"] = 3;
	num["foru"] = 4;
	num["efiv"] = 5;
	num["isx"] = 6;
	num["eensv"] = 7;
	num["eghit"] = 8;
	num["einn"] = 9;
	num["ent"] = 10;

	cin >> tcase;
	while (tcase--) {
		cin >> op1 >> code >> op2 >> eq >> res;
		sort(op1.begin(), op1.end());
		sort(op2.begin(), op2.end());
		sort(res.begin(), res.end());

		if (num.find(res) == num.end()) {
			cout << "No" << endl;
		}
		else {
			if (code  == "+")
				val = num[op1] + num[op2];
			else if (code  == "-")
				val = num[op1] - num[op2];
			else if (code  == "*")
				val = num[op1] * num[op2];
			
			if (val == num[res])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}
