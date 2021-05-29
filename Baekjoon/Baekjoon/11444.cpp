#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

// matrix���� ������ ���� ������ �������̵�
matrix operator *(const matrix &a, const matrix &b) {
	ll size = a.size();
	matrix temp(size, vector<ll>(size));
	for (ll i = 0; i < size; i++)
		for (ll j = 0; j < size; j++) {
			for (ll k = 0; k < size; k++)
				temp[i][j] += a[i][k] * b[k][j];
			temp[i][j] %= 1000000007;
		}
	return temp;
}

// a�� n������ ���ϴ� �Լ�
matrix power(matrix a, ll n) {
	ll size = a.size();
	matrix temp(size, vector<ll>(size));
	for (ll i = 0; i < size; i++)
		temp[i][i] = 1;
	while (n > 0) {
		if (n % 2 == 1) {
			temp = temp * a;
		}
		n /= 2;
		a = a * a;
	}
	return temp;
}

int main() {
	ll n;
	cin >> n;

	matrix a = { {1, 1}, {1, 0} };
	matrix ans = (power(a, n - 1));
	cout << (ans[1][0] + ans[1][1]) % 1000000007;
	return 0;
}