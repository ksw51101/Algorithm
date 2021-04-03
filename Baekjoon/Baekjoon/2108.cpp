#include <iostream>
#include <algorithm>
using namespace std;

int n, num[500000], count_num[8001] = { 0, }, count_num_max = 0, max_num, second;
bool flag = false;
double sum = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		count_num[num[i] + 4000]++;
		sum += num[i];
	}

	for (int i = 0; i < 8001; i++) {
		if (count_num[i] > count_num_max) {
			count_num_max = count_num[i];
			max_num = i - 4000;
			flag = false;
		}
		else if (count_num[i] == count_num_max && flag == false) {
			second = i - 4000;
			flag = true;
		}
	}
		
	sort(num, num + n);

	cout << fixed;
	cout.precision(0);
	cout << sum / n << endl;
	cout << num[n / 2] << endl;
	if (flag==false)
		cout << max_num << endl;
	else
		cout << second << endl;
	cout << num[n - 1] - num[0] << endl;





	return 0;
}