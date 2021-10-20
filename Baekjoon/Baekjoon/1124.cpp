#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> prime[20];
int m;
int a, b, ans;

// 100000이하의 모든 소수를 구하는 함수
void get_prime() {
	prime[1].push_back(2);
	for (int i = 3; i <= 100000; i++) {
		bool flag = false;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag = true;
				break;
			}
		}
		if (!flag)
			prime[1].push_back(i);
	}
}

// index 개의 소수를 곱한 dp에 num이 이미 존재하는지 확인하는 함수
bool check(int index, ll num) {
	for (int i = 0; i < prime[index].size(); i++) {
		if (prime[index][i] == num)
			return false;
	}
	return true;
}

int main() {
	cin >> a >> b;
	get_prime(); // 소수를 구함
	for (int i = 2; i <= 20; i++) { // i개의 소수가 곱하여 이루어진 수를 구함
		for (int k = 0; k < prime[i - 1].size(); k++) {
			for (int j = 0; j < prime[1].size(); j++) {
				ll temp = prime[1][j] * prime[i - 1][k]; // i-1개의 소수를 곱하여 만들어진 수에 소수를 곱하여 i개의 소수를 곱한 수를 만듦
				if (temp <= b) {
					if (check(i, temp)) // 이미 있는 수가 아니면 추가
						prime[i].push_back(prime[i - 1][k] * prime[1][j]);
				}
				else
					break;
			}
		}
	}
	for (int i = 2; i <= 20; i++) {
		for (int j = 0; j < prime[1].size(); j++) {
			if (i == prime[1][j]) { // 소수개의 소수의 곱으로 이루어진 수이면 ans 갱신
				for (int k = 0; k < prime[i].size(); k++) {
					if (prime[i][k] >= a)
						ans++;
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
