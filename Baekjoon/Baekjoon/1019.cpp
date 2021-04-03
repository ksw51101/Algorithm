#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long N;
int len, Count[10] = { 0, }, temp, index, portion, a, total;
string str_num, save;

int main() {
	index = total = 0;
	cin >> N;

	str_num = to_string(N);
	len = str_num.length();

	for (int i = 1; i <= len; i++)
		total += pow(10, len - i);

	for (int i = 1; i < len + 1; i++) {
		save = str_num[len - i];
		temp = stoi(save);
		for (int j = 1; j < 10; j++) {
			if (j < temp) {
				Count[j] += (int)(N / pow(10, i) + 1) * pow(10, i - 1);
			}
			else if (j > temp) {

				Count[j] += (int)(N / pow(10, i)) * pow(10, i - 1);
			}
			else {
				if (i - 1 > 0) {
					portion = pow(10, i - 1);
					Count[j] += (int)(N / pow(10, i)) * portion + N % portion + 1;
				}
				else {
					Count[j] += (int)(N / pow(10, i)) + 1 * pow(10, i - 1);
				}
			}
		}
	}

	Count[0] = (N + 1) * len;
	for (int i = 1; i < 10; i++)
		Count[0] -= Count[i];
	Count[0] -= total;

	for (int i = 0; i < 10; i++) {
		cout << Count[i] << ' ';
	}

	return 0;
}