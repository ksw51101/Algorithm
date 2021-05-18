#include <iostream>
#include <math.h>
using namespace std;

int N, M, queue[50], num[50], func1_num = 0, func2_num = 0, func3_num = 0, temp, total;

int func1() {
	total--;
	func1_num++;
	temp = queue[0];
	for (int i = 0; i < total; i++) {
		queue[i] = queue[i + 1];
		queue[i + 1] = 0;
	}
	return temp;
}

void func2() {
	func2_num++;
	temp = queue[0];
	for (int i = 0; i < total - 1; i++)
		queue[i] = queue[i + 1];
	queue[total - 1] = temp;
}

void func3() {
	func3_num++;
	temp = queue[total - 1];
	for (int i = 0; i < total - 1; i++)
		queue[total - 1 - i] = queue[total - 2 - i];
	queue[0] = temp;
}


int main() {

	cin >> N >> M;
	total = N;
	for (int i = 0; i < N; i++)
		queue[i] = i + 1;

	for (int i = 0; i < M; i++)
		cin >> num[i];

	for (int i = 0; i < M; i++) {
		if (queue[0] == num[i])
			func1();
		else {
			for (int j = 0; j < total; j++) {
				if (queue[j] == num[i]) {
					if (j < ceil((double)total / 2)) {
						func2();
						i--;
					}
					else {
						func3();
						i--;
					}
					break;
				}
			}
		}
	}

	cout << func2_num + func3_num << endl;

	return 0;
}