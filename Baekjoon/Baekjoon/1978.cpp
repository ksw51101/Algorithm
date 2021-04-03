#include <iostream>
#include <math.h>
using namespace std;

int arr[1000], N, num = 0;
bool flag;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		if (arr[i] == 1)
			continue;
		else if (arr[i] == 2)
			num++;
		else {
			flag = true;
			for (int j = 2; j <= sqrt(arr[i]); j++) {
				if (arr[i] % j == 0) {
					flag = false;
					break;
				}
			}
			if (flag)
				num++;
		}
			 
	}
	cout << num << endl;

	return 0;
}