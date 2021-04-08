#include <iostream>
#include <string>
using namespace std;

string str, str_num = "";
int sum = 0;
bool flag = false, oper = true;

int main() {
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+') {
			if (flag)
				sum -= stoi(str_num);
			else {
				sum += stoi(str_num);
				oper = true;
			}
			str_num = "";
		}
		else if (str[i] == '-') {
			if (!flag)
				flag = true;
			if (oper)
				sum += stoi(str_num);
			else
				sum -= stoi(str_num);
			oper = false;
			str_num = "";
		}
		else
			str_num += str[i];
	}
	if (oper)
		sum += stoi(str_num);
	else
		sum -= stoi(str_num);

	cout << sum << '\n';

	return 0;
}