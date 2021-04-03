#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, num = 1, count;
	string str_num;
	bool flag;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		num++;
		while (1) {
			flag = false;
			str_num = to_string(num);
			count = 0;
			for (int i = 0; i < str_num.length(); i++) {
				if (str_num[i] == '6') {
					count++;
					if (count == 3) {
						flag = true;
						break;
					}
				}
				else
					count = 0;
			}
			if (flag == true)
				break;
			else
				num++;
		}
	}
	cout << num << endl;

	return 0;
}