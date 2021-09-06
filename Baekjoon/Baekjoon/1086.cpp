#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int n, k;
ll d[1 << 15][100];

// 최대공약수를 구하는 함수
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	cin >> n;
	vector<string> vec(n); // 집합의 원소
	vector<int> len(n); // 각 원소의 길이
	vector<int> m(n); // 각 원소의 k 모듈러 값
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

	vector<int> ten(51); // pow(10, 1~50)의 k 모듈러 값
	ten[0] = 1;
	for (int i = 1; i <= 50; i++)
		ten[i] = (ten[i - 1] * 10) % k;

	d[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < n; l++) {
				if ((i & (1 << l)) == 0) { // 현재 합친수에 포함되어 있지 않은 수라면
					int next = ((j * ten[len[l]]) % k + m[l]) % k; // (현재 합친수 * pow(10, 새로운 수의 길이) + 새로운 수)의 k 모듈러 값
					d[i | (1 << l)][next] += d[i][j]; // d[새로운 합친수][next]값 갱신
				}
			}
		}
	}
	ll ans = d[(1 << n) - 1][0]; // k로 나누어 떨어지는 합친수의 개수
	ll fac = 1;
	for (int i = 2; i <= n; i++) fac *= i; // 전체 경우의 수
	ll g = gcd(ans, fac); // 기약분수
	ans /= g;
	fac /= g;
	cout << ans << '/' << fac << '\n';

	return 0;
}