#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int n, k;
ll d[1 << 15][100];

// �ִ������� ���ϴ� �Լ�
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	cin >> n;
	vector<string> vec(n); // ������ ����
	vector<int> len(n); // �� ������ ����
	vector<int> m(n); // �� ������ k ��ⷯ ��
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		len[i] = vec[i].size();
	}
	cin >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			m[i] = (m[i] * 10 + (vec[i][j] - '0')) % k;
		}
	}

	vector<int> ten(51); // pow(10, 1~50)�� k ��ⷯ ��
	ten[0] = 1;
	for (int i = 1; i <= 50; i++)
		ten[i] = (ten[i - 1] * 10) % k;

	d[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < n; l++) {
				if ((i & (1 << l)) == 0) { // ���� ��ģ���� ���ԵǾ� ���� ���� �����
					int next = ((j * ten[len[l]]) % k + m[l]) % k; // (���� ��ģ�� * pow(10, ���ο� ���� ����) + ���ο� ��)�� k ��ⷯ ��
					d[i | (1 << l)][next] += d[i][j]; // d[���ο� ��ģ��][next]�� ����
				}
			}
		}
	}
	ll ans = d[(1 << n) - 1][0]; // k�� ������ �������� ��ģ���� ����
	ll fac = 1;
	for (int i = 2; i <= n; i++) fac *= i; // ��ü ����� ��
	ll g = gcd(ans, fac); // ���м�
	ans /= g;
	fac /= g;
	cout << ans << '/' << fac << '\n';

	return 0;
}