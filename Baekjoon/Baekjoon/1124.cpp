#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> prime[20];
int m;
int a, b, ans;

// 100000������ ��� �Ҽ��� ���ϴ� �Լ�
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

// index ���� �Ҽ��� ���� dp�� num�� �̹� �����ϴ��� Ȯ���ϴ� �Լ�
bool check(int index, ll num) {
	for (int i = 0; i < prime[index].size(); i++) {
		if (prime[index][i] == num)
			return false;
	}
	return true;
}

int main() {
	cin >> a >> b;
	get_prime(); // �Ҽ��� ����
	for (int i = 2; i <= 20; i++) { // i���� �Ҽ��� ���Ͽ� �̷���� ���� ����
		for (int k = 0; k < prime[i - 1].size(); k++) {
			for (int j = 0; j < prime[1].size(); j++) {
				ll temp = prime[1][j] * prime[i - 1][k]; // i-1���� �Ҽ��� ���Ͽ� ������� ���� �Ҽ��� ���Ͽ� i���� �Ҽ��� ���� ���� ����
				if (temp <= b) {
					if (check(i, temp)) // �̹� �ִ� ���� �ƴϸ� �߰�
						prime[i].push_back(prime[i - 1][k] * prime[1][j]);
				}
				else
					break;
			}
		}
	}
	for (int i = 2; i <= 20; i++) {
		for (int j = 0; j < prime[1].size(); j++) {
			if (i == prime[1][j]) { // �Ҽ����� �Ҽ��� ������ �̷���� ���̸� ans ����
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
